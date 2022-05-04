#pragma once

#include "FeaturesPageViewModel.g.h"
#include "ImageViewModel.g.h"

namespace winrt::UFCase::implementation
{
    struct FeaturesPageViewModel : FeaturesPageViewModelT<FeaturesPageViewModel>
    {
        FeaturesPageViewModel(ImageViewModel image): m_image(image) { }

        ImageViewModel Image() { return m_image; }
        IObservableVector<FeatureViewModel> RootFeatures() { return m_features; }

        IAsyncActionWithProgress<uint32_t> PullData();

        // implement INotifyPropertyChanged
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value) {
            return m_property_changed.add(value);
        }
        void PropertyChanged(winrt::event_token const& token) {
            m_property_changed.remove(token);
        }

    private:
        ImageViewModel m_image{nullptr};
        IObservableVector<FeatureViewModel> m_features{nullptr};

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_property_changed{};
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPageViewModel : FeaturesPageViewModelT<FeaturesPageViewModel, implementation::FeaturesPageViewModel>
    {
    };
}
