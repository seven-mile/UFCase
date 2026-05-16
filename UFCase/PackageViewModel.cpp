#include "pch.h"
#include "PackageViewModel.h"
#if __has_include("PackageDetails.g.cpp")
#include "PackageDetails.g.cpp"
#endif
#if __has_include("PackageListItem.g.cpp")
#include "PackageListItem.g.cpp"
#endif
#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    static hstring FormatPackageState(Isolation::CbsInstallState state)
    {
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

    inline hstring ParseCbsTimeStampString(const wchar_t *ts_str)
    {
        auto timeStamp = std::wcstoull(ts_str, nullptr, 10);
        LARGE_INTEGER liTmp;
        liTmp.QuadPart = timeStamp;
        FILETIME fileTimeTmp, fileLocalTimeTmp;
        fileTimeTmp.dwLowDateTime = liTmp.LowPart;
        fileTimeTmp.dwHighDateTime = liTmp.HighPart;

        // Optional
        FileTimeToLocalFileTime(&fileTimeTmp, &fileLocalTimeTmp);

        SYSTEMTIME sysTimeTmp;
        FileTimeToSystemTime(&fileLocalTimeTmp, &sysTimeTmp);

        return std::format(L"{}/{:02}/{:02} {}:{:02}:{:02}", sysTimeTmp.wYear, sysTimeTmp.wMonth,
                           sysTimeTmp.wDay, sysTimeTmp.wHour, sysTimeTmp.wMinute,
                           sysTimeTmp.wSecond)
            .c_str();
    }

    PackageListSnapshot ReadPackageListSnapshot(Isolation::PackageModel const &model)
    {
        PackageListSnapshot data;
        data.Identity = model.Identity();

        auto display_name = model.Name();
        if (display_name.empty())
        {
            data.ListName = data.Identity;
            data.ListIdentity = L"";
            data.ListIdentityVisibility = Visibility::Collapsed;
        }
        else
        {
            data.ListName = display_name;
            data.ListIdentity = data.Identity;
            data.ListIdentityVisibility = Visibility::Visible;
        }

        data.ReleaseType = model.ReleaseType();
        data.State = FormatPackageState(model.State());
        data.Description = model.Description();
        data.IsApplicable = model.IsApplicable();
        return data;
    }

    PackageDetailsSnapshot ReadPackageDetailsSnapshot(Isolation::PackageModel const &model)
    {
        PackageDetailsSnapshot data;
        auto display_name = model.Name();
        data.DetailName = display_name.empty() ? L"(Unnamed)" : display_name;
        data.DetailIdentity = model.Identity();
        data.Description = model.Description();
        data.RestartRequired = model.RestartRequired();
        data.ProductName = model.ProductName();
        data.ProductVersion = model.ProductVersion();
        data.Company = model.Company();
        data.Copyright = model.Copyright();
        data.SupportInformation = model.SupportInformation();
        data.CreationTime = ParseCbsTimeStampString(model.CreationTime().c_str());
        data.LastUpdateTime = ParseCbsTimeStampString(model.LastUpdateTime().c_str());
        data.InstallTime = ParseCbsTimeStampString(model.InstallTime().c_str());
        data.InstallPackageName = model.InstallPackageName();
        data.InstallLocation = model.InstallLocation();
        auto install_client = model.InstallClient();
        data.InstallClient = install_client.empty() ? L"Unknown" : install_client;
        data.InstallUserName = model.InstallUserName();
        data.ManifestFilePath = model.ManifestFilePath();
        data.RegistryPath = model.RegistryPath();
        return data;
    }

    PackageListItem::PackageListItem(uint32_t record_id, PackageListSnapshot data)
        : m_record_id(record_id), m_data(std::move(data))
    {
    }

    hstring PackageListItem::ListName()
    {
        return m_data.ListName;
    }

    hstring PackageListItem::ListIdentity()
    {
        return m_data.ListIdentity;
    }

    Visibility PackageListItem::ListIdentityVisibility()
    {
        return m_data.ListIdentityVisibility;
    }

    hstring PackageListItem::Identity()
    {
        return m_data.Identity;
    }

    hstring PackageListItem::ReleaseType()
    {
        return m_data.ReleaseType;
    }

    hstring PackageListItem::State()
    {
        return m_data.State;
    }

    hstring PackageListItem::Description()
    {
        return m_data.Description;
    }

    bool PackageListItem::IsApplicable()
    {
        return m_data.IsApplicable;
    }

    PackageDetails::PackageDetails(PackageDetailsSnapshot data) : m_data(std::move(data)) {}

    hstring PackageDetails::DetailName() { return m_data.DetailName; }
    hstring PackageDetails::DetailIdentity() { return m_data.DetailIdentity; }
    hstring PackageDetails::Description() { return m_data.Description; }
    hstring PackageDetails::RestartRequired() { return m_data.RestartRequired; }
    hstring PackageDetails::ProductName() { return m_data.ProductName; }
    hstring PackageDetails::ProductVersion() { return m_data.ProductVersion; }
    hstring PackageDetails::Company() { return m_data.Company; }
    hstring PackageDetails::Copyright() { return m_data.Copyright; }
    hstring PackageDetails::SupportInformation() { return m_data.SupportInformation; }
    hstring PackageDetails::CreationTime() { return m_data.CreationTime; }
    hstring PackageDetails::LastUpdateTime() { return m_data.LastUpdateTime; }
    hstring PackageDetails::InstallTime() { return m_data.InstallTime; }
    hstring PackageDetails::InstallPackageName() { return m_data.InstallPackageName; }
    hstring PackageDetails::InstallLocation() { return m_data.InstallLocation; }
    hstring PackageDetails::InstallClient() { return m_data.InstallClient; }
    hstring PackageDetails::InstallUserName() { return m_data.InstallUserName; }
    hstring PackageDetails::ManifestFilePath() { return m_data.ManifestFilePath; }
    hstring PackageDetails::RegistryPath() { return m_data.RegistryPath; }

} // namespace winrt::UFCase::implementation
