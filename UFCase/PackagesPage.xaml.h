#pragma once

#include "PackagesPage.g.h"

namespace winrt {
    inline hstring to_hstring(UFCase::PackageState const& state) {
        switch (state) {
        case UFCase::PackageState::PartiallyInstalled: return L"PartiallyInstalled";
        case UFCase::PackageState::Cancel: return L"Cancel";
        case UFCase::PackageState::Superseded: return L"Superseded";
        case UFCase::PackageState::Default: return L"Default";
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
        winrt::event<winrt::Data::PropertyChangedEventHandler> m_propertyChanged;

        PackagesPage();

        // implement INotifyPropertyChanged
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value);
        void PropertyChanged(winrt::event_token const& token);

        void OnNavigatedTo(const Navigation::NavigationEventArgs& e);

        IObservableVector<UFCase::PackageViewModel> m_pkgProv{nullptr};
        IObservableVector<UFCase::PackageViewModel> PackageDataSource();
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPage : PackagesPageT<PackagesPage, implementation::PackagesPage>
    {
    };
}
