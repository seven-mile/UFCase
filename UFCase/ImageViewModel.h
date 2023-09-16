#pragma once

#include "ImageViewModel.g.h"

#include <winrt/UFCase.Isolation.h>

#include "PropChgUtil.h"

namespace winrt::UFCase::implementation
{
    struct ImageViewModel : ImageViewModelT<ImageViewModel>, ImplPropertyChangedT<ImageViewModel>
    {
        ImageViewModel(Isolation::ImageModel model);

        hstring Type();
        hstring Version();
        hstring Edition();
        hstring Bootdrive();
        Media::ImageSource Icon();

        Isolation::SessionModel OpenSession();

        bool Selectable()
        {
            return m_state == LoadingState::Loaded;
        }

        Isolation::ImageModel Model()
        {
            return m_model;
        }

        Isolation::StoreModel Store()
        {
            return m_model.SxsStore();
        }

        IAsyncAction PullData();

      private:
        Isolation::ImageModel m_model;
        hstring m_version{L"Loading"}, m_edition;
        Media::ImageSource m_icon{nullptr};

        enum class LoadingState
        {
            Uninitialized,
            Loading,
            Loaded,
        } m_state = LoadingState::Uninitialized;
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ImageViewModel : ImageViewModelT<ImageViewModel, implementation::ImageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
