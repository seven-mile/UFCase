#pragma once

#include "ImageSelectorViewModel.g.h"

#include "PropChgUtil.h"

#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.Storage.h>

namespace winrt
{
    using namespace Windows::Storage;
}

namespace winrt::UFCase::implementation
{
    struct ImageSelectorViewModel : ImageSelectorViewModelT<ImageSelectorViewModel>,
                                    ImplPropertyChangedT<ImageSelectorViewModel>
    {
        ImageSelectorViewModel();

        IObservableVector<UFCase::ImageViewModel> Images();

        int32_t SelectedIndex();
        void SelectedIndex(int32_t);

        UFCase::ImageViewModel SelectedImageViewModel()
        {
            if (m_selected_idx < 0)
                return nullptr;
            return m_images.GetAt(m_selected_idx);
        }

        Isolation::ImageModel SelectedImageModel()
        {
            return SelectedImageViewModel().Model();
        }

        IAsyncActionWithProgress<hstring> PullData();

      private:
        int32_t m_selected_idx = -1;

        IObservableVector<UFCase::ImageViewModel> m_images;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ImageSelectorViewModel
        : ImageSelectorViewModelT<ImageSelectorViewModel, implementation::ImageSelectorViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
