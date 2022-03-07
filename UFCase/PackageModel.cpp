#include "pch.h"
#include "PackageModel.h"
#include "SessionModel.h"
#include "FeatureModel.h"

#include "CbsProviderManager.h"
#include "MallocUtil.h"
#include "CbsUtil.h"
#include <wil/resource.h>

#include <ranges>

namespace winrt::UFCase {

    PackageModel* PackageModel::Create(SessionModel* session, com_ptr<ICbsPackage> package)
    {
        return new PackageModel{ session, package };
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

    FeatureModel* PackageModel::OpenFeature(hstring const& name)
    {
        if (auto it = updates.find(name); it != updates.end())
            return &FeatureModel::GetInstance(it->second);
        com_ptr<ICbsUpdate> update;
        check_hresult(package->GetUpdate(name.c_str(), update.put()));

        auto &&res = FeatureModel::Create(update, this);
        updates[name] = res->GetHandle();
        return res;
    }

    std::vector<FeatureModel*> PackageModel::GetPackageFeatureCollection(_CbsApplicability appl, _CbsSelectability sele)
    {
        com_ptr<IEnumCbsUpdate> cbs_updates;
        check_hresult(package->EnumerateUpdates(appl, sele, cbs_updates.put()));

        std::vector<FeatureModel*> handles;
        for (auto&& update : GetIEnumComPtrVector<ICbsUpdate>(cbs_updates)) {
            unique_malloc_wstring ws_name;
            check_hresult(update->GetProperty(CbsUpdatePropertyName, wil::out_param(ws_name)));
            try {
                handles.push_back(this->OpenFeature(ws_name.get()));
            } catch (hresult_error const&) {
                continue;
            }
        }
        return handles;
    }
}
