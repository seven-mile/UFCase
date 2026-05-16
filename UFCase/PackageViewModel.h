#pragma once

#include "CbsApi.h"
#include "PackageDetails.g.h"
#include "PackageListItem.g.h"

#include <winrt/UFCase.Isolation.h>

namespace winrt::UFCase::implementation
{
    struct PackageListSnapshot
    {
        hstring ListName;
        hstring ListIdentity;
        Visibility ListIdentityVisibility{Visibility::Collapsed};
        hstring Identity;
        hstring ReleaseType;
        hstring State;
        hstring Description;
        bool IsApplicable{};
    };

    struct PackageDetailsSnapshot
    {
        hstring DetailName;
        hstring DetailIdentity;
        hstring Description;
        hstring RestartRequired;
        hstring ProductName;
        hstring ProductVersion;
        hstring Company;
        hstring Copyright;
        hstring SupportInformation;
        hstring CreationTime;
        hstring LastUpdateTime;
        hstring InstallTime;
        hstring InstallPackageName;
        hstring InstallLocation;
        hstring InstallClient;
        hstring InstallUserName;
        hstring ManifestFilePath;
        hstring RegistryPath;
    };

    PackageListSnapshot ReadPackageListSnapshot(Isolation::PackageModel const &model);
    PackageDetailsSnapshot ReadPackageDetailsSnapshot(Isolation::PackageModel const &model);

    struct PackageListItem : PackageListItemT<PackageListItem>
    {
        PackageListItem(uint32_t record_id, PackageListSnapshot data);

        uint32_t RecordId() const
        {
            return m_record_id;
        }

        hstring ListName();
        hstring ListIdentity();
        Visibility ListIdentityVisibility();
        hstring Identity();
        hstring ReleaseType();
        hstring State();
        hstring Description();
        bool IsApplicable();

      private:
        uint32_t m_record_id{};
        PackageListSnapshot m_data;
    };

    struct PackageDetails : PackageDetailsT<PackageDetails>
    {
        PackageDetails(PackageDetailsSnapshot data);

        hstring DetailName();
        hstring DetailIdentity();
        hstring Description();
        hstring RestartRequired();
        hstring ProductName();
        hstring ProductVersion();
        hstring Company();
        hstring Copyright();
        hstring SupportInformation();
        hstring CreationTime();
        hstring LastUpdateTime();
        hstring InstallTime();
        hstring InstallPackageName();
        hstring InstallLocation();
        hstring InstallClient();
        hstring InstallUserName();
        hstring ManifestFilePath();
        hstring RegistryPath();

      private:
        PackageDetailsSnapshot m_data;
    };
} // namespace winrt::UFCase::implementation
