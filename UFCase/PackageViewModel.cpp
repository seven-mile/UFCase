﻿#include "pch.h"
#include "PackageViewModel.h"
#if __has_include("PackageViewModel.g.cpp")
#include "PackageViewModel.g.cpp"
#endif

#include "CbsProviderManager.h"
#include "MallocUtil.h"
#include "CbsUtil.h"
#include <wil/resource.h>


namespace winrt::UFCase::implementation
{
    PackageViewModel::PackageViewModel(uint64_t hModel) : m_model(PackageModel::GetInstance(hModel)) { }

    uint64_t PackageViewModel::Handle() {
        return m_model.GetHandle();
    }

    hstring PackageViewModel::Identity()
    {
        return m_model.Identity();
    }

    hstring PackageViewModel::ReleaseType()
    {
        return m_model.ReleaseType();
    }

    hstring PackageViewModel::State()
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

    hstring PackageViewModel::Name()
    {
        return m_model.Name();
    }

    hstring PackageViewModel::Description()
    {
        return m_model.Description();
    }

    hstring PackageViewModel::RestartRequired()
    {
        return m_model.RestartRequired();
    }

    hstring PackageViewModel::ProductName()
    {
        return m_model.ProductName();
    }

    hstring PackageViewModel::ProductVersion()
    {
        return m_model.ProductVersion();
    }

    hstring PackageViewModel::Company()
    {
        return m_model.Company();
    }

    hstring PackageViewModel::Copyright()
    {
        return m_model.Copyright();
    }

    hstring PackageViewModel::SupportInformation()
    {
        return m_model.SupportInformation();
    }

    hstring PackageViewModel::CreationTime()
    {
        return ParseCbsTimeStampString(m_model.CreationTime().c_str());
    }

    hstring PackageViewModel::LastUpdateTime()
    {
        return ParseCbsTimeStampString(m_model.LastUpdateTime().c_str());
    }

    hstring PackageViewModel::InstallTime()
    {
        return ParseCbsTimeStampString(m_model.InstallTime().c_str());
    }

    hstring PackageViewModel::InstallPackageName()
    {
        return m_model.InstallPackageName();
    }

    hstring PackageViewModel::InstallLocation()
    {
        return m_model.InstallLocation();
    }

    hstring PackageViewModel::InstallClient()
    {
        return m_model.InstallClient();
    }

    hstring PackageViewModel::InstallUserName()
    {
        return m_model.InstallUserName();
    }

    bool PackageViewModel::IsApplicable() {
        return m_model.IsApplicable();
    }
}
