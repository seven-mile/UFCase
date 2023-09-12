#pragma once

#include "ImageViewModel.g.h"

#include "ImageModel.h"
#include "StoreModel.h"

#include "PropChgUtil.h"

namespace winrt::UFCase::implementation
{
    struct ImageViewModel : ImageViewModelT<ImageViewModel>, ImplPropertyChangedT<ImageViewModel>
    {
        ImageViewModel(uint64_t hModel);

        hstring Type();
        hstring Version();
        hstring Edition();
        hstring Bootdrive();
        Media::ImageSource Icon();

        void Select();

        uint64_t OpenSession();
        void CloseSession(uint64_t handle);

        bool Selectable()
        {
            return m_state == LoadingState::Loaded;
        }

        uint64_t Store()
        {
            return m_model.SxsStore()->GetHandle();
        }

        IAsyncAction PullData();

      private:
        ImageModel &m_model;
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
