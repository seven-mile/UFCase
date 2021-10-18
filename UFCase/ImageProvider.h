#pragma once

#include "ImageProvider.g.h"
#include "ImageItem.g.h"

#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.Storage.h>

namespace winrt {
    using namespace Windows::Storage;
}

namespace winrt::UFCase::implementation
{
    struct ImageProvider : ImageProviderT<ImageProvider>
    {
        ImageProvider();

        IObservableVector<UFCase::ImageItem> Images();
        int32_t SelectedIndex();
        void SelectedIndex(int32_t);

        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value);
        void PropertyChanged(winrt::event_token const& token);

    private:
        static const int32_t Invalid_Index = -1;
        int32_t m_selectedIdx;

        int32_t ConfigOnlineImage();
        int32_t ConfigAppConfigImage();
        void ConfigWimImage();
        IObservableVector<UFCase::ImageItem> m_images = multi_threaded_observable_vector<UFCase::ImageItem>();

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_propertyChanged;

        // helpers
        IAsyncAction CompleteImageItem(UFCase::ImageItem);

        const Media::Imaging::BitmapImage Win7Icon = Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows7.png"));
        const Media::Imaging::BitmapImage Win8Icon = Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows8.png"));
        const Media::Imaging::BitmapImage Win10Icon = Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows10.png"));
        const Media::Imaging::BitmapImage Win11Icon = Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows11.png"));
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
