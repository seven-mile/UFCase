#pragma once

#include "ImageProvider.g.h"
#include "ImageItem.g.h"

namespace winrt::UFCase::implementation
{
    struct ImageProvider : ImageProviderT<ImageProvider>
    {

        ImageProvider();

        IObservableVector<UFCase::ImageItem> Images();

    private:
        void ConfigOnlineImage();
        void ConfigWimImage();
        IObservableVector<UFCase::ImageItem> m_images = multi_threaded_observable_vector<UFCase::ImageItem>();
    };

    struct ImageItem : ImageItemT<ImageItem>
    {
        ImageItem() = default;

        ImageItem(hstring const &type, hstring const &ver, hstring const &bootdrv, Media::ImageSource const &icon);

        hstring Type();
        void Type(hstring const&);
        
        hstring Version();
        void Version(hstring const&);

        hstring Bootdrive();
        void Bootdrive(hstring const&);

        Media::ImageSource Icon();
        void Icon(Media::ImageSource const &);
    private:
        hstring m_type, m_ver, m_bootdrv;
        Media::ImageSource m_icon{nullptr};
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct ImageProvider : ImageProviderT<ImageProvider, implementation::ImageProvider>
    {
    };

    struct ImageItem : ImageItemT<ImageItem, implementation::ImageItem>
    {
    };
}
