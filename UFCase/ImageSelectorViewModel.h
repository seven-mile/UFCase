#pragma once

#include "ImageSelectorViewModel.g.h"

#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.Storage.h>

namespace winrt
{
    using namespace Windows::Storage;
}

namespace winrt::UFCase::implementation
{
    struct ImageSelectorViewModel : ImageSelectorViewModelT<ImageSelectorViewModel>
    {
        ImageSelectorViewModel();

        IObservableVector<UFCase::ImageViewModel> Images();
        int32_t SelectedIndex();
        void SelectedIndex(int32_t);

        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const &value);
        void PropertyChanged(winrt::event_token const &token);

      private:
        static constexpr int32_t Invalid_Index = -1;
        int32_t m_selectedIdx = Invalid_Index;

        IObservableVector<UFCase::ImageViewModel> m_images;

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_property_changed;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ImageSelectorViewModel
        : ImageSelectorViewModelT<ImageSelectorViewModel, implementation::ImageSelectorViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
