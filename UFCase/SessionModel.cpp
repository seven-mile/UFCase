#include "pch.h"
#include "SessionModel.h"
#include "PackageModel.h"
#include "ImageModel.h"

#include "CCbsUIHandler.h"

#include "MallocUtil.h"
#include "CbsUtil.h"
#include <wil/resource.h>

#include <ranges>

extern "C" CLSID CLSID_CbsSession;

namespace winrt::UFCase
{

    std::unordered_multimap<ImageModel *, com_ptr<ICbsSession>> image_work_session;

    SessionModel::SessionModel(ImageModel *image, com_ptr<ICbsSession> session)
        : image(*image), GitObject(session)
    {
    }

    SessionModel *SessionModel::Create(ImageModel *image, _CbsSessionOption option)
    {
        auto session = create_instance<ICbsSession>(CLSID_CbsSession, CLSCTX_LOCAL_SERVER);

        if (image->Type() == ImageType::Online)
        {
            check_hresult(session->Initialize(option, L"UFCase", nullptr, nullptr));
        }
        else
        {
            check_hresult(session->Initialize(option, L"UFCase", image->Bootdrive().c_str(),
                                              image->WinDir().c_str()));
        }

        THROW_IF_FAILED(CoSetProxyBlanket(session.get(), RPC_C_AUTHN_DEFAULT, RPC_C_AUTHZ_NONE,
                                          nullptr, RPC_C_AUTHN_LEVEL_CALL,
                                          RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE));

        return new SessionModel{image, session};
    }

    PackageModel *SessionModel::OpenPackageWithoutHash(com_ptr<ICbsIdentity> identity)
    {
        com_ptr<ICbsPackage> package;
        check_hresult(GetInterface()->OpenPackage(0, identity.get(), nullptr, package.put()));
        package = package.as<ICbsPackage>();
        return PackageModel::Create(this, package);
    }

    SessionModel::~SessionModel()
    {
        for (auto &&val : packages | std::ranges::views::values)
            ModelManager<PackageModel>::Erase(val);
        packages.clear();
    }

    void SessionModel::AddSource(hstring const &source_dir)
    {
        check_hresult(GetInterface().as<ICbsSession8>()->AddSource(0, source_dir.c_str()));
    }

    IAsyncActionWithProgress<uint32_t> SessionModel::SaveChanges()
    {
        // use bg thread to save changes
        co_await resume_background();

        auto report_progress = co_await get_progress_token();

        if (auto sess = GetInterface().try_as<ICbsSession8>())
        {
            auto ui_handler = make<CCbsUIHandler>([&](uint32_t val) { report_progress(val); },
                                                  [](hresult hr) { throw_hresult(hr); });

            check_hresult(sess->RegisterCbsUIHandler(ui_handler.get()));
        }

        _CbsRequiredAction action{};
        check_hresult(GetInterface()->Finalize(&action));

        co_return;
    }

    std::vector<PackageModel *> SessionModel::Packages(DWORD flag)
    {
        com_ptr<IEnumCbsIdentity> ids;

        check_hresult(GetInterface()->EnumeratePackages(flag, ids.put()));
        std::vector<PackageModel *> res;
        for (auto &&id : GetIEnumComPtrVector<ICbsIdentity>(ids))
        {
            res.push_back(this->OpenPackage(id));
        }
        return res;
    }

    PackageModel *SessionModel::OpenPackage(com_ptr<ICbsIdentity> identity)
    {
        unique_malloc_wstring ws_id;
        check_hresult(identity->GetStringId(wil::out_param(ws_id)));
        if (auto it = packages.find(ws_id.get()); it != packages.end())
            return &PackageModel::GetInstance(it->second);

        auto &&res = this->OpenPackageWithoutHash(identity);
        packages[ws_id.get()] = res->GetHandle();
        return res;
    }

    PackageModel *SessionModel::OpenPackage(hstring const &identity)
    {
        if (auto it = packages.find(identity); it != packages.end())
            return &PackageModel::GetInstance(it->second);

        com_ptr<ICbsIdentity> id;
        check_hresult(GetInterface()->CreateCbsIdentity(id.put()));
        check_hresult(id->LoadFromStringId(identity.c_str()));
        auto &&res = this->OpenPackageWithoutHash(id);
        packages[identity] = res->GetHandle();
        return res;
    }

    PackageModel *SessionModel::FoundationPackage()
    {
        return this->OpenPackage(L"@Foundation");
    }

    PackageModel *SessionModel::ProductPackage()
    {
        return this->OpenPackage(L"@Product");
    }

} // namespace winrt::UFCase
