#pragma once

#include "PackagesPageViewModel.g.h"

namespace winrt::UFCase::implementation
{
    struct PackagesPageViewModel : PackagesPageViewModelT<PackagesPageViewModel>
    {
        PackagesPageViewModel(UFCase::ImageViewModel image): m_image(image) { }

        UFCase::ImageViewModel Image() { return m_image; }
        IObservableVector<UFCase::PackageViewModel> Packages() { return m_packages; }

        IAsyncActionWithProgress<uint32_t> PullData();

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

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_property_changed{};
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPageViewModel : PackagesPageViewModelT<PackagesPageViewModel, implementation::PackagesPageViewModel>
    {
    };
}
