#include "pch.h"
#include "PackageViewModel.h"
#if __has_include("PackageViewModel.g.cpp")
#include "PackageViewModel.g.cpp"
#endif

#include "MallocUtil.h"
#include "CbsUtil.h"
#include <wil/resource.h>


namespace winrt::UFCase::implementation
{
    PackageViewModel::PackageViewModel(uint64_t hModel)
        : m_model(PackageModel::GetInstance(hModel)) {
        Prefetch();
    }

    uint64_t PackageViewModel::Handle() {
        return m_model.GetHandle();
    }

    hstring PackageViewModel::ReleaseTypeRaw()
    {
        return m_model.ReleaseType();
    }

    hstring PackageViewModel::StateRaw()
    {
        auto state = m_model.State();
        switch (state) {
        case CbsInstallStateAbsent:
            return L"Absent";
        case CbsInstallStateCancel:
            return L"Cancel";
        case CbsInstallStatePartiallyInstalled:
            return L"PartiallyInstalled";
        case CbsInstallStateUninstallRequested:
            return L"UninstallRequested";
        case CbsInstallStateInstallRequested:
            return L"InstallRequested";
        case CbsInstallStateSuperseded:
            return L"Superseded";
        case CbsInstallStateDefault:
            return L"Default";
        case CbsInstallStatePermanent:
            return L"Permanent";
        case CbsInstallStateInstalled:
            return L"Installed";
        case CbsInstallStateStaged:
            return L"Staged";
        case CbsInstallStateStaging:
            return L"Staging";
        case CbsInstallStateResolving:
            return L"Resolving";
        case CbsInstallStateResolved:
            return L"Resolved";
        default:
            return L"Unknown";
        }
    }

    hstring PackageViewModel::ListNameRaw()
    {
        auto &&res = m_model.Name();
        if (res.empty()) return m_model.Identity();
        return res;
    }

    hstring PackageViewModel::ListIdentityRaw()
    {
        auto&& res = m_model.Name();
        // avoid repetition of display
        if (res.empty()) return L"";
        return m_model.Identity();
    }

    Visibility PackageViewModel::ListIdentityVisibilityRaw()
    {
        auto&& res = m_model.Name();
        // avoid repetition of display
        if (res.empty()) return Visibility::Collapsed;
        return Visibility::Visible;
    }

    hstring PackageViewModel::DetailNameRaw()
    {
        auto&& res = m_model.Name();
        if (res.empty()) return L"(Unnamed)";
        return res;
    }

    hstring PackageViewModel::DetailIdentityRaw()
    {
        return m_model.Identity();
    }

    hstring PackageViewModel::DescriptionRaw()
    {
        auto &&res = m_model.Description();
        if (res.empty()) return L"No description.";
        return res;
    }

    hstring PackageViewModel::RestartRequiredRaw()
    {
        return m_model.RestartRequired();
    }

    hstring PackageViewModel::ProductNameRaw()
    {
        return m_model.ProductName();
    }

    hstring PackageViewModel::ProductVersionRaw()
    {
        return m_model.ProductVersion();
    }

    hstring PackageViewModel::CompanyRaw()
    {
        return m_model.Company();
    }

    hstring PackageViewModel::CopyrightRaw()
    {
        return m_model.Copyright();
    }

    hstring PackageViewModel::SupportInformationRaw()
    {
        return m_model.SupportInformation();
    }

    hstring PackageViewModel::CreationTimeRaw()
    {
        return ParseCbsTimeStampString(m_model.CreationTime().c_str());
    }

    hstring PackageViewModel::LastUpdateTimeRaw()
    {
        return ParseCbsTimeStampString(m_model.LastUpdateTime().c_str());
    }

    hstring PackageViewModel::InstallTimeRaw()
    {
        return ParseCbsTimeStampString(m_model.InstallTime().c_str());
    }

    hstring PackageViewModel::InstallPackageNameRaw()
    {
        return m_model.InstallPackageName();
    }

    hstring PackageViewModel::InstallLocationRaw()
    {
        return m_model.InstallLocation();
    }

    hstring PackageViewModel::InstallClientRaw()
    {
        return m_model.InstallClient();
    }

    hstring PackageViewModel::InstallUserNameRaw()
    {
        return m_model.InstallUserName();
    }

    bool PackageViewModel::IsApplicableRaw() {
        return m_model.IsApplicable();
    }
}
