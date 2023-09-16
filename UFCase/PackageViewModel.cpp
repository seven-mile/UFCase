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
    PackageViewModel::PackageViewModel(Isolation::PackageModel model) : m_model(model)
    {
        Prefetch();
    }

    hstring PackageViewModel::ReleaseTypeRaw()
    {
        return m_model.ReleaseType();
    }

    hstring PackageViewModel::StateRaw()
    {
        auto state = m_model.State();
        switch (state)
        {
        case Isolation::CbsInstallState::CbsInstallStateAbsent:
            return L"Absent";
        case Isolation::CbsInstallState::CbsInstallStateCancel:
            return L"Cancel";
        case Isolation::CbsInstallState::CbsInstallStatePartiallyInstalled:
            return L"PartiallyInstalled";
        case Isolation::CbsInstallState::CbsInstallStateUninstallRequested:
            return L"UninstallRequested";
        case Isolation::CbsInstallState::CbsInstallStateInstallRequested:
            return L"InstallRequested";
        case Isolation::CbsInstallState::CbsInstallStateSuperseded:
            return L"Superseded";
        case Isolation::CbsInstallState::CbsInstallStateDefault:
            return L"Default";
        case Isolation::CbsInstallState::CbsInstallStatePermanent:
            return L"Permanent";
        case Isolation::CbsInstallState::CbsInstallStateInstalled:
            return L"Installed";
        case Isolation::CbsInstallState::CbsInstallStateStaged:
            return L"Staged";
        case Isolation::CbsInstallState::CbsInstallStateStaging:
            return L"Staging";
        case Isolation::CbsInstallState::CbsInstallStateResolving:
            return L"Resolving";
        case Isolation::CbsInstallState::CbsInstallStateResolved:
            return L"Resolved";
        default:
            return L"Unknown";
        }
    }

    hstring PackageViewModel::ListNameRaw()
    {
        auto &&res = m_model.Name();
        if (res.empty())
            return m_model.Identity();
        return res;
    }

    hstring PackageViewModel::ListIdentityRaw()
    {
        auto &&res = m_model.Name();
        // avoid repetition of display
        if (res.empty())
            return L"";
        return m_model.Identity();
    }

    Visibility PackageViewModel::ListIdentityVisibilityRaw()
    {
        auto &&res = m_model.Name();
        // avoid repetition of display
        if (res.empty())
            return Visibility::Collapsed;
        return Visibility::Visible;
    }

    hstring PackageViewModel::DetailNameRaw()
    {
        auto &&res = m_model.Name();
        if (res.empty())
            return L"(Unnamed)";
        return res;
    }

    hstring PackageViewModel::DetailIdentityRaw()
    {
        return m_model.Identity();
    }

    hstring PackageViewModel::DescriptionRaw()
    {
        auto &&res = m_model.Description();
        if (res.empty())
            return L"No description.";
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

    bool PackageViewModel::IsApplicableRaw()
    {
        return m_model.IsApplicable();
    }
} // namespace winrt::UFCase::implementation
