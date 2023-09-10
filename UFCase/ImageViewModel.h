#pragma once

#include "ImageViewModel.g.h"

#include "ImageModel.h"

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
            return m_info_loading;
        }

      private:
        ImageModel &m_model;
        hstring m_version, m_edition;
        Media::ImageSource m_icon{nullptr};
        bool m_icon_loading = false, m_info_loading = false;
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ImageViewModel : ImageViewModelT<ImageViewModel, implementation::ImageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
