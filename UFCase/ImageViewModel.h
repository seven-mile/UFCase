#pragma once

#include "ImageViewModel.g.h"

#include "ImageModel.h"

namespace winrt::UFCase::implementation
{
    struct ImageViewModel : ImageViewModelT<ImageViewModel>
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

        event_token PropertyChanged(Data::PropertyChangedEventHandler const &handler)
        {
            return m_property_changed.add(handler);
        }

        void PropertyChanged(event_token const &token)
        {
            m_property_changed.remove(token);
        }

        bool Selectable()
        {
            return m_info_loading;
        }

      private:
        ImageModel &m_model;
        hstring m_version, m_edition;
        Media::ImageSource m_icon{nullptr};
        bool m_icon_loading = false, m_info_loading = false;

        event<Data::PropertyChangedEventHandler> m_property_changed{};
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ImageViewModel : ImageViewModelT<ImageViewModel, implementation::ImageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
