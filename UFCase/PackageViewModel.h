#pragma once

#include "CbsApi.h"
#include "PackageViewModel.g.h"

namespace winrt::UFCase::implementation
{
    struct PackageViewModel : PackageViewModelT<PackageViewModel>
    {
        hstring id;
        hstring displayName;
        hstring description;
        PackageState state = PackageState::Unknown;
        hstring reltype;

        hstring m_sessionClient;

        com_ptr<ICbsPackage> m_pPkg;

        com_ptr<ICbsSession> GetSession();
        com_ptr<ICbsPackage> GetPackage();

        // public in IDL:

        PackageViewModel(hstring sessionClient);
        
        static UFCase::PackageViewModel LoadFromIdentity(hstring const &sessionClient, hstring const &id);

        hstring Identity();
        void Identity(hstring const& val);
        hstring DisplayName();
        void DisplayName(hstring const& val);
        hstring Description();
        void Description(hstring const& val);
        PackageState State();
        void State(PackageState const& val);
        hstring ReleaseType();
        void ReleaseType(hstring const& val);

        hstring GetFSPath();
        hstring GetRegPath();
        hstring GetSupportUrl();
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackageViewModel : PackageViewModelT<PackageViewModel, implementation::PackageViewModel>
    {
    };
}
