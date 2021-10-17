#include "pch.h"
#include "ImageProvider.h"
#if __has_include("ImageProvider.g.cpp")
#include "ImageProvider.g.cpp"
#endif
#if __has_include("ImageItem.g.cpp")
#include "ImageItem.g.cpp"
#endif

#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>

#include <winrt/Windows.Storage.h>

namespace winrt::UFCase::implementation
{
    ImageProvider::ImageProvider()
    {
        this->ConfigOnlineImage();
        this->ConfigWimImage();
    }

    IObservableVector<UFCase::ImageItem> ImageProvider::Images()
    {
        return m_images;
    }

    void ImageProvider::ConfigOnlineImage()
    {
        UFCase::ImageItem res;

        // such as C:\\Windows\\System32
        std::wstring_view systemDir = Windows::Storage::SystemDataPaths::GetDefault().System();
        res.Bootdrive(systemDir.substr(0, systemDir.find_last_of(L'/')));
        res.Icon(Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows11.png")));
        res.Version(L"Windows 11 Build 22000.258");
        res.Type(L"Online");

        m_images.Append(res);
    }

    void ImageProvider::ConfigWimImage()
    {
        UFCase::ImageItem res, res2, res3;
        res.Bootdrive(L"D:\\MyCache\\Ws\\Windows");
        res.Icon(Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows10.png")));
        res.Type(L"Offline");
        res.Version(L"Windows 10 Build 19041.174");

        m_images.Append(res);

        res2.Bootdrive(L"D:\\MyCache\\Vx\\Windows");
        res2.Icon(Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows7.png")));
        res2.Type(L"Offline");
        res2.Version(L"Windows 7 Build 7601.92");

        m_images.Append(res2);

        res3.Bootdrive(L"D:\\MyCache\\Ck\\Windows");
        res3.Icon(Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows8.png")));
        res3.Type(L"Offline");
        res3.Version(L"Windows 8.1 Build 9600.384");

        m_images.Append(res3);
    }

    ImageItem::ImageItem(hstring const& type, hstring const& ver, hstring const& bootdrv, Media::ImageSource const& icon)
        : m_type(type), m_ver(ver), m_bootdrv(bootdrv), m_icon(icon) { }

    hstring ImageItem::Type()
    {
        return m_type;
    }
    void ImageItem::Type(hstring const &value)
    {
        m_type = value;
    }
    hstring ImageItem::Version()
    {
        return m_ver;
    }
    void ImageItem::Version(hstring const &value)
    {
        m_ver = value;
    }
    hstring ImageItem::Bootdrive()
    {
        return m_bootdrv;
    }
    void ImageItem::Bootdrive(hstring const &value)
    {
        m_bootdrv = value;
    }
    Media::ImageSource ImageItem::Icon()
    {
        return m_icon;
    }
    void ImageItem::Icon(Media::ImageSource const& value)
    {
        m_icon = value;
    }
}
