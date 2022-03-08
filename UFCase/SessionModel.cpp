#include "pch.h"
#include "SessionModel.h"
#include "PackageModel.h"
#include "ImageModel.h"

#include "MallocUtil.h"
#include "CbsUtil.h"
#include "CbsProviderManager.h"
#include <wil/resource.h>

namespace winrt::UFCase {

    SessionModel::SessionModel(ImageModel* image, _CbsSessionOption option) : image(*image), option(option) {
        session = CbsProviderManager::Current()
            .ApplyFromBootdrive(L"UFCase",
                // cannot use image session for now
                // just apply online session
                // image->Bootdrive().c_str()
                CbsProviderManager::GetOnlineBootdrive())
            ->ApplySession();

        if (image->Type() == ImageType::Online) {
            check_hresult(session->Initialize(option, L"UFCase", nullptr, nullptr));
        } else {
            check_hresult(session->Initialize(option, L"UFCase", image->Bootdrive().c_str(), image->WinDir().c_str()));
        }

    }

    SessionModel* SessionModel::Create(ImageModel* image, _CbsSessionOption option)
    {
        return new SessionModel{ image, option };
    }

    PackageModel* SessionModel::OpenPackageWithoutHash(com_ptr<ICbsIdentity> identity)
    {
        com_ptr<ICbsPackage> package;
        check_hresult(session->OpenPackage(0, identity.get(), nullptr, package.put()));
        package = package.as<ICbsPackage>();
        return PackageModel::Create(this, package);
    }

    SessionModel::~SessionModel()
    {
        for (auto&& [_, val] : packages)
            ModelManager<PackageModel>::Erase(val);
        packages.clear();
    }

    void SessionModel::SaveChanges()
    {
        _CbsRequiredAction action{};
        check_hresult(session->Finalize(&action));
    }

    std::vector<PackageModel*> SessionModel::Packages(DWORD flag)
    {
        com_ptr<IEnumCbsIdentity> ids;

        check_hresult(session->EnumeratePackages(flag, ids.put()));
        std::vector<PackageModel*> res;
        for (auto&& id : GetIEnumComPtrVector<ICbsIdentity>(ids)) {
            res.push_back(this->OpenPackage(id));
        }
        return res;
    }

    PackageModel* SessionModel::OpenPackage(com_ptr<ICbsIdentity> identity)
    {
        unique_malloc_wstring ws_id;
        check_hresult(identity->GetStringId(wil::out_param(ws_id)));
        if (auto it = packages.find(ws_id.get()); it != packages.end())
            return &PackageModel::GetInstance(it->second);

        auto &&res = this->OpenPackageWithoutHash(identity);
        packages[ws_id.get()] = res->GetHandle();
        return res;
    }

    PackageModel* SessionModel::OpenPackage(hstring const& identity)
    {
        if (auto it = packages.find(identity); it != packages.end())
            return &PackageModel::GetInstance(it->second);

        com_ptr<ICbsIdentity> id;
        check_hresult(session->CreateCbsIdentity(id.put()));
        check_hresult(id->LoadFromStringId(identity.c_str()));
        auto &&res = this->OpenPackageWithoutHash(id);
        packages[identity] = res->GetHandle();
        return res;
    }

    PackageModel* SessionModel::FoundationPackage()
    {
        return this->OpenPackage(L"@Foundation");
    }

    PackageModel* SessionModel::ProductPackage()
    {
        return this->OpenPackage(L"@Product");
    }
}
