#include "pch.h"
#include "PackageModel.h"
#if __has_include("PackageModel.g.cpp")
#include "PackageModel.g.cpp"
#endif

#include "FeatureModel.h"
#include "Utils/MallocUtil.h"
#include "Utils/ComUtil.h"

#include <filesystem>

namespace winrt::UFCase::Isolation::implementation
{
    Isolation::SessionModel PackageModel::Session()
    {
        return m_session;
    }

    hstring PackageModel::Identity()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyIdentityString, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ReleaseType()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyReleaseType, wil::out_param(ws)));
        return ws.get();
    }

    CbsInstallState PackageModel::State()
    {
        // todo: why here is applicable state correct
        // rather than current state?
        _CbsInstallState stApp{}, stCur{};
        check_hresult(GetInterface()->EvaluateApplicability(0, &stApp, &stCur));
        return static_cast<CbsInstallState>(stApp);
    }

    hstring PackageModel::Name()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyDisplayName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Description()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyDescription, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::RestartRequired()
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyRestart, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ProductName()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyProductName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::ProductVersion()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyProductVersion, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Company()
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyCompany, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::Copyright()
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsPackagePropertyCopyright, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::SupportInformation()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertySupportInformation, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::CreationTime()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyCreationTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::LastUpdateTime()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyLastUpdateTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallTime()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyInstallTimeStamp, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallPackageName()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyInstallPackageName, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallLocation()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyInstallLocation, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallClient()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyInstallClient, wil::out_param(ws)));
        return ws.get();
    }

    hstring PackageModel::InstallUserName()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsPackagePropertyInstallUserName, wil::out_param(ws)));
        return ws.get();
    }

    bool PackageModel::IsApplicable()
    {
        _CbsInstallState state_applicable{}, state_current{};
        return SUCCEEDED(
            GetInterface()->EvaluateApplicability(0, &state_applicable, &state_current));
    }

    hstring PackageModel::ManifestFilePath()
    {
        std::filesystem::path bootdrive_path = m_session.Image().Bootdrive().c_str();
        auto manifest_root = bootdrive_path / L"Windows" / L"servicing" / L"Packages";
        auto manifest_name = Identity() + L".mum";
        auto mani_path = manifest_root / manifest_name.c_str();
        if (std::filesystem::exists(mani_path))
        {
            return mani_path.c_str();
        }
        else
        {
            return L"";
        }
    }

    hstring PackageModel::RegistryPath()
    {
        // SOFTWARE\Microsoft\Windows\CurrentVersion\Component Based Servicing\Packages;
        std::wstring reg_path =
            (m_session.Image().GetRegistryHive(L"SOFTWARE") +
             LR"(\Microsoft\Windows\CurrentVersion\Component Based Servicing\Packages\)" +
             Identity())
                .c_str();

        if (reg_path.starts_with(L"HKEY_LOCAL_MACHINE\\"))
        {
            auto sub_reg_path = reg_path.substr(19);
            wil::unique_hkey reg_key{};
            if (ERROR_SUCCESS ==
                RegOpenKey(HKEY_LOCAL_MACHINE, sub_reg_path.c_str(), wil::out_param(reg_key)))
            {
                return reg_path.c_str();
            }
        }
        return L"";
    }

    void PackageModel::Install()
    {
        check_hresult(GetInterface()->InitiateChanges(0, CbsInstallStateInstalled, nullptr));
    }

    void PackageModel::Remove()
    {
        check_hresult(GetInterface()->InitiateChanges(0, CbsInstallStateAbsent, nullptr));
    }

    void PackageModel::Stage()
    {
        check_hresult(GetInterface()->InitiateChanges(0, CbsInstallStateStaged, nullptr));
    }

    Isolation::FeatureModel PackageModel::OpenFeature(hstring const &name)
    {
        com_ptr<ICbsUpdate> update;
        check_hresult(GetInterface()->GetUpdate(name.c_str(), update.put()));

        return make<implementation::FeatureModel>(*get_strong(), update);
    }

    Windows::Foundation::Collections::IVector<Isolation::FeatureModel> PackageModel::
        GetFeatureCollection(DWORD appl, DWORD sele)
    {
        com_ptr<IEnumCbsUpdate> cbs_updates;
        check_hresult(GetInterface()->EnumerateUpdates(static_cast<::_CbsApplicability>(appl),
                                                       static_cast<::_CbsSelectability>(sele),
                                                       cbs_updates.put()));

        auto handles = single_threaded_vector<Isolation::FeatureModel>();
        for (auto &&update : GetIEnumComPtrVector<ICbsUpdate>(cbs_updates))
        {
            unique_malloc_wstring ws_name;
            check_hresult(update->GetProperty(CbsUpdatePropertyName, wil::out_param(ws_name)));
            try
            {
                handles.Append(this->OpenFeature(ws_name.get()));
            }
            catch (hresult_error const &)
            {
                continue;
            }
        }
        return handles;
    }
} // namespace winrt::UFCase::Isolation::implementation
