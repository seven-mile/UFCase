#include "pch.h"
#include "PackageModel.h"
#include "CbsProviderManager.h"
#include "MallocUtil.h"
#include "CbsUtil.h"
#include <wil/resource.h>

#include <ranges>

namespace winrt::UFCase {

    PackageModel::PackageModel(hstring const&sessionClient, hstring const& id)
    {
        auto pSess = CbsProviderManager::Current().ApplyFromBootdrive(sessionClient,
            CbsProviderManager::GetOnlineBootdrive())->ApplySession();

        com_ptr<ICbsIdentity> pId;
        check_hresult(pSess->CreateCbsIdentity(pId.put()));

        check_hresult(pId->LoadFromStringId(id.c_str()));
        check_hresult(pSess->OpenPackage(0, pId.get(), nullptr, package.put()));

        package = package.as<ICbsPackage>();
    }

    PackageModel* winrt::UFCase::PackageModel::Create(hstring const&sessionClient, hstring const& identity)
    {
        return new PackageModel{ sessionClient, identity };
    }

    PackageModel* PackageModel::Create(com_ptr<ICbsPackage> package)
    {
        return new PackageModel{ package };
    }

    hstring PackageModel::Identity()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyIdentityString, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ReleaseType()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyReleaseType, wil::out_param(ws)));
        return ws.get();
    }

    _CbsInstallState PackageModel::State()
    {
        return _CbsInstallState();
    }

    hstring PackageModel::Name()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyDisplayName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Description()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyDescription, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::RestartRequired()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyRestart, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ProductName()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyProductName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ProductVersion()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyProductVersion, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Company()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyCompany, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Copyright()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyCopyright, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::SupportInformation()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertySupportInformation, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::CreationTime()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyCreationTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::LastUpdateTime()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyLastUpdateTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallTime()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyInstallTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallPackageName()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyInstallPackageName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallLocation()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyInstallLocation, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallClient()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyInstallClient, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallUserName()
    {
        unique_malloc_wstring ws;
        check_hresult(package->GetProperty(CbsPackagePropertyInstallUserName, wil::out_param(ws)));
        return ws.get();
    }

    bool PackageModel::IsApplicable()
    {
        _CbsInstallState state_applicable{}, state_current{};
        return SUCCEEDED(package->EvaluateApplicability(0, &state_applicable, &state_current));
    }

    void PackageModel::Install()
    {
        check_hresult(package->InitiateChanges(0, CbsInstallStateInstalled, nullptr));
    }

    void PackageModel::Remove()
    {
        check_hresult(package->InitiateChanges(0, CbsInstallStateAbsent, nullptr));
    }

    void PackageModel::Stage()
    {
        check_hresult(package->InitiateChanges(0, CbsInstallStateStaged, nullptr));
    }

    FeatureModel* PackageModel::OpenFeature(hstring const& UpdateName)
    {
        com_ptr<ICbsUpdate> update;
        check_hresult(package->GetUpdate(UpdateName.c_str(), update.put()));

        return FeatureModel::Create(update, *this);
    }

    std::vector<FeatureModel*> PackageModel::GetPackageFeatureCollection()
    {
        com_ptr<IEnumCbsUpdate> updates;
        std::vector<FeatureModel*> handles;
        for (auto&& update : GetIEnumComPtrVector<ICbsUpdate>(updates)) {
            handles.push_back(FeatureModel::Create(update, *this));
        }
        return handles;
    }
}
