#include "pch.h"
#include "PackageModel.h"
#include "SessionModel.h"
#include "FeatureModel.h"

#include "MallocUtil.h"
#include "CbsUtil.h"
#include <wil/resource.h>

#include <ranges>

namespace winrt::UFCase {

    PackageModel* PackageModel::Create(SessionModel* session, com_ptr<ICbsPackage> package)
    {
        return new PackageModel{ session, package };
    }

    SessionModel* PackageModel::Session() const
    {
        return &this->session;
    }

    hstring PackageModel::Identity() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyIdentityString, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ReleaseType() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyReleaseType, wil::out_param(ws)));
        return ws.get();
    }

    _CbsInstallState PackageModel::State() const
    {
        return _CbsInstallState();
    }

    hstring PackageModel::Name() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyDisplayName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Description() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyDescription, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::RestartRequired() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyRestart, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ProductName() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyProductName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ProductVersion() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyProductVersion, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Company() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyCompany, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Copyright() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyCopyright, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::SupportInformation() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertySupportInformation, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::CreationTime() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyCreationTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::LastUpdateTime() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyLastUpdateTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallTime() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyInstallTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallPackageName() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyInstallPackageName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallLocation() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyInstallLocation, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallClient() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyInstallClient, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallUserName() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyInstallUserName, wil::out_param(ws)));
        return ws.get();
    }

    bool PackageModel::IsApplicable() const
    {
        _CbsInstallState state_applicable{}, state_current{};
        return SUCCEEDED(GetInterface()->EvaluateApplicability(0, &state_applicable, &state_current));
    }

    void PackageModel::Install() const
    {
        check_hresult(GetInterface()->InitiateChanges(0, CbsInstallStateInstalled, nullptr));
    }

    void PackageModel::Remove() const
    {
        check_hresult(GetInterface()->InitiateChanges(0, CbsInstallStateAbsent, nullptr));
    }

    void PackageModel::Stage() const
    {
        check_hresult(GetInterface()->InitiateChanges(0, CbsInstallStateStaged, nullptr));
    }

    FeatureModel* PackageModel::OpenFeature(hstring const& name)
    {
        if (auto it = updates.find(name); it != updates.end())
            return &FeatureModel::GetInstance(it->second);
        com_ptr<ICbsUpdate> update;
        check_hresult(GetInterface()->GetUpdate(name.c_str(), update.put()));

        auto &&res = FeatureModel::Create(update, this);
        updates[name] = res->GetHandle();
        return res;
    }

    std::vector<FeatureModel*> PackageModel::GetPackageFeatureCollection(_CbsApplicability appl, _CbsSelectability sele)
    {
        com_ptr<IEnumCbsUpdate> cbs_updates;
        check_hresult(GetInterface()->EnumerateUpdates(appl, sele, cbs_updates.put()));

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
