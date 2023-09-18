#pragma once

#include "CbsApi.h"
#include "PackageViewModel.g.h"

#include <winrt/UFCase.Isolation.h>

#include "CacheUtil.h"

namespace winrt::UFCase::implementation
{
    struct PackageViewModel : PackageViewModelT<PackageViewModel>
    {
        Isolation::PackageModel m_model;

        PackageViewModel(Isolation::PackageModel model);

        hstring ListNameRaw();
        hstring ListIdentityRaw();
        Visibility ListIdentityVisibilityRaw();
        hstring DetailNameRaw();
        hstring DetailIdentityRaw();
        hstring ReleaseTypeRaw();
        hstring StateRaw();
        hstring DescriptionRaw();
        hstring RestartRequiredRaw();
        hstring ProductNameRaw();
        hstring ProductVersionRaw();
        hstring CompanyRaw();
        hstring CopyrightRaw();
        hstring SupportInformationRaw();
        hstring CreationTimeRaw();
        hstring LastUpdateTimeRaw();
        hstring InstallTimeRaw();
        hstring InstallPackageNameRaw();
        hstring InstallLocationRaw();
        hstring InstallClientRaw();
        hstring InstallUserNameRaw();
        bool IsApplicableRaw();

        hstring ManifestFilePath();
        hstring RegistryPath();

        // clang-format off
        PropertyCache<hstring, PackageViewModel> ListName{ *this, &PackageViewModel::ListNameRaw };
        PropertyCache<hstring, PackageViewModel> ListIdentity{ *this, &PackageViewModel::ListIdentityRaw };
        PropertyCache<Visibility, PackageViewModel> ListIdentityVisibility{ *this, &PackageViewModel::ListIdentityVisibilityRaw };
        PropertyCache<hstring, PackageViewModel> DetailName{ *this, &PackageViewModel::DetailNameRaw };
        PropertyCache<hstring, PackageViewModel> DetailIdentity{ *this, &PackageViewModel::DetailIdentityRaw };
        PropertyCache<hstring, PackageViewModel> ReleaseType{ *this, &PackageViewModel::ReleaseTypeRaw };
        PropertyCache<hstring, PackageViewModel> State{ *this, &PackageViewModel::StateRaw };
        PropertyCache<hstring, PackageViewModel> Description{ *this, &PackageViewModel::DescriptionRaw };
        PropertyCache<hstring, PackageViewModel> RestartRequired{ *this, &PackageViewModel::RestartRequiredRaw };
        PropertyCache<hstring, PackageViewModel> ProductName{ *this, &PackageViewModel::ProductNameRaw };
        PropertyCache<hstring, PackageViewModel> ProductVersion{ *this, &PackageViewModel::ProductVersionRaw };
        PropertyCache<hstring, PackageViewModel> Company{ *this, &PackageViewModel::CompanyRaw };
        PropertyCache<hstring, PackageViewModel> Copyright{ *this, &PackageViewModel::CopyrightRaw };
        PropertyCache<hstring, PackageViewModel> SupportInformation{ *this, &PackageViewModel::SupportInformationRaw };
        PropertyCache<hstring, PackageViewModel> CreationTime{ *this, &PackageViewModel::CreationTimeRaw };
        PropertyCache<hstring, PackageViewModel> LastUpdateTime{ *this, &PackageViewModel::LastUpdateTimeRaw };
        PropertyCache<hstring, PackageViewModel> InstallTime{ *this, &PackageViewModel::InstallTimeRaw };
        PropertyCache<hstring, PackageViewModel> InstallPackageName{ *this, &PackageViewModel::InstallPackageNameRaw };
        PropertyCache<hstring, PackageViewModel> InstallLocation{ *this, &PackageViewModel::InstallLocationRaw };
        PropertyCache<hstring, PackageViewModel> InstallClient{ *this, &PackageViewModel::InstallClientRaw };
        PropertyCache<hstring, PackageViewModel> InstallUserName{ *this, &PackageViewModel::InstallUserNameRaw };
        PropertyCache<bool, PackageViewModel> IsApplicable{ *this, &PackageViewModel::IsApplicableRaw };
        // clang-format on

        void Prefetch()
        {
            ListName();
            ListIdentity();
            ListIdentityVisibility();
            DetailName();
            DetailIdentity();
            ReleaseType();
            State();
            Description();
            RestartRequired();
            ProductName();
            ProductVersion();
            Company();
            Copyright();
            SupportInformation();
            CreationTime();
            LastUpdateTime();
            InstallTime();
            InstallPackageName();
            InstallLocation();
            InstallClient();
            InstallUserName();
            IsApplicable();
        }
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct PackageViewModel : PackageViewModelT<PackageViewModel, implementation::PackageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
