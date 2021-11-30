#pragma once

#include "PackagesPage.g.h"

namespace winrt {
    inline hstring to_hstring(UFCase::PackageState const& state) {
        switch (state) {
        case UFCase::PackageState::Absent: return L"Absent";
        case UFCase::PackageState::Resolving: return L"Resolving";
        case UFCase::PackageState::Resolved: return L"Resolved";
        case UFCase::PackageState::Staging: return L"Staging";
        case UFCase::PackageState::Staged: return L"Staged";
        case UFCase::PackageState::UninstallRequested: return L"UninstallRequested";
        case UFCase::PackageState::InstallRequested: return L"InstallRequested";
        case UFCase::PackageState::Installed: return L"Installed";
        case UFCase::PackageState::Permanent: return L"Permanent";
        case UFCase::PackageState::Unknown: return L"Unknown";
        default: return L"Invalid";
        }
    }
}

namespace winrt::UFCase::implementation
{
    struct PackagesPage : PackagesPageT<PackagesPage>
    {
        PackagesPage();

        void OnNavigatedTo(const Navigation::NavigationEventArgs& e);

        UFCase::PackagesProvider m_pkgProv{nullptr};
        UFCase::PackagesProvider PackageDataSource();
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPage : PackagesPageT<PackagesPage, implementation::PackagesPage>
    {
    };
}
