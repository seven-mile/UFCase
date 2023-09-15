#include "pch.h"
#include "SessionModel.h"
#if __has_include("SessionModel.g.cpp")
#include "SessionModel.g.cpp"
#endif

#include "../UFCase/CCbsUIHandler.h"
#include "../UFCase/CbsUtil.h"
#include "../UFCase/MallocUtil.h"

#include "PackageModel.h"

static const CLSID CLSID_CbsSession = {
    0x752073A1, 0x23F2, 0x4396, {0x85, 0xF0, 0x8F, 0xDB, 0x87, 0x9E, 0xD0, 0xED}};

namespace winrt::UFCase::Isolation::implementation
{
    void SessionModel::Initialize(DWORD option_)
    {
        auto option = static_cast<::_CbsSessionOption>(option_);
        // todo: support offline cbs session
        m_session = create_instance<ICbsSession>(CLSID_CbsSession, CLSCTX_LOCAL_SERVER);

        if (m_image.Type() == ImageType::Online)
        {
            check_hresult(m_session->Initialize(option, L"UFCase", nullptr, nullptr));
        }
        else
        {
            check_hresult(m_session->Initialize(option, L"UFCase", m_image.Bootdrive().c_str(),
                                              m_image.WinDir().c_str()));
        }

        THROW_IF_FAILED(CoSetProxyBlanket(m_session.get(), RPC_C_AUTHN_DEFAULT, RPC_C_AUTHZ_NONE,
                                          nullptr, RPC_C_AUTHN_LEVEL_CALL,
                                          RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE));
    }

    Isolation::PackageModel SessionModel::OpenPackage(com_ptr<ICbsIdentity> identity)
    {
        com_ptr<ICbsPackage> package;
        check_hresult(GetInterface()->OpenPackage(0, identity.get(), nullptr, package.put()));
        package = package.as<ICbsPackage>();
        return make<implementation::PackageModel>(*get_strong(), package);
    }

    void SessionModel::AddSource(hstring const &source_dir)
    {
        check_hresult(GetInterface().as<ICbsSession8>()->AddSource(0, source_dir.c_str()));
    }

    Windows::Foundation::IAsyncActionWithProgress<uint32_t> SessionModel::SaveChanges()
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

    Windows::Foundation::Collections::IVector<Isolation::PackageModel> SessionModel::
        GetPackageCollection(DWORD flag)
    {
        com_ptr<IEnumCbsIdentity> ids;

        check_hresult(GetInterface()->EnumeratePackages(flag, ids.put()));
        auto res = single_threaded_vector<Isolation::PackageModel>();
        for (auto &&id : GetIEnumComPtrVector<ICbsIdentity>(ids))
        {
            res.Append(this->OpenPackage(id));
        }
        return res;
    }

    Isolation::PackageModel SessionModel::OpenPackage(hstring const &identity)
    {
        com_ptr<ICbsIdentity> id;
        check_hresult(GetInterface()->CreateCbsIdentity(id.put()));
        check_hresult(id->LoadFromStringId(identity.c_str()));
        return this->OpenPackage(id);
    }

    Isolation::PackageModel SessionModel::FoundationPackage()
    {
        return this->OpenPackage(L"@Foundation");
    }

    Isolation::PackageModel SessionModel::ProductPackage()
    {
        return this->OpenPackage(L"@Product");
    }

    void SessionModel::PerformOperation(CbsOperationType operation_)
    {
        auto operation = static_cast<::_CbsOperationType>(operation_);
        if (auto session10 = GetInterface().try_as<ICbsSession10>())
        {
            check_hresult(session10->PerformOperation(0, operation));
        }
        else
        {
            throw hresult_no_interface{};
        }
    }
} // namespace winrt::UFCase::Isolation::implementation
