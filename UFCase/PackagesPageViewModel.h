#pragma once

#include "PackagesPageNavigationContext.g.h"
#include "PackagesPageViewModel.g.h"

namespace winrt::UFCase::implementation
{

    struct PackagesPageNavigationContext : PackagesPageNavigationContextT<PackagesPageNavigationContext> {
        PackagesPageNavigationContext() = default;

        hstring SelectPkgId() { return m_sel_pkg; }
        void SelectPkgId(hstring value) { m_sel_pkg = value; }

        hstring m_sel_pkg;
    };

    struct PackagesPageViewModel : PackagesPageViewModelT<PackagesPageViewModel>
    {
        PackagesPageViewModel(UFCase::ImageViewModel image): m_image(image) { }
        PackagesPageViewModel(UFCase::ImageViewModel image, UFCase::PackagesPageNavigationContext nav_ctx)
            : m_image(image), m_nav_ctx(nav_ctx) { }

        UFCase::ImageViewModel Image() { return m_image; }
        IObservableVector<UFCase::PackageViewModel> Packages() { return m_packages; }
        UFCase::PackageViewModel SelectedPackage() { return m_selected; }
        void SelectedPackage(UFCase::PackageViewModel value) { m_selected = value; }

        UFCase::PackagesPageNavigationContext NavContext() { return m_nav_ctx; }

        IAsyncActionWithProgress<uint32_t> PullData(bool is_nav = true);

        // implement INotifyPropertyChanged
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value) {
            return m_property_changed.add(value);
        }
        void PropertyChanged(winrt::event_token const& token) {
            m_property_changed.remove(token);
        }

    private:
        UFCase::ImageViewModel m_image{nullptr};
        IObservableVector<UFCase::PackageViewModel> m_packages{nullptr};
        UFCase::PackageViewModel m_selected{nullptr};
        UFCase::PackagesPageNavigationContext m_nav_ctx;

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_property_changed{};
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPageViewModel : PackagesPageViewModelT<PackagesPageViewModel, implementation::PackagesPageViewModel>
    {
    };

    struct PackagesPageNavigationContext : PackagesPageNavigationContextT<PackagesPageNavigationContext, implementation::PackagesPageNavigationContext>
    {
    };
}
