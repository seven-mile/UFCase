#include "pch.h"
#include "ImageProvider.h"
#if __has_include("ImageProvider.g.cpp")
#include "ImageProvider.g.cpp"
#endif
#if __has_include("ImageItem.g.cpp")
#include "ImageItem.g.cpp"
#endif

#include "AppConfig.hpp"
#include "CbsSessionManager.h"

#include <filesystem>

#pragma comment(lib, "Version.lib")

namespace winrt::UFCase::implementation
{
    
    ImageProvider::ImageProvider()
    {
        auto cfgIndex = this->ConfigAppConfigImage(),
             onlineIndex = this->ConfigOnlineImage();
        this->SelectedIndex(cfgIndex == Invalid_Index ? onlineIndex : cfgIndex);
        this->ConfigWimImage();
    }

    IObservableVector<UFCase::ImageItem> ImageProvider::Images()
    {
        return m_images;
    }

    int32_t ImageProvider::SelectedIndex()
    {
        return m_selectedIdx;
    }

    void ImageProvider::SelectedIndex(int32_t value)
    {
        m_selectedIdx = value;

        auto img = m_images.GetAt(value);
        auto stackObj = g_appConfig.GetNamedObject(L"stack");
        using Windows::Data::Json::JsonValue;
        if (img.Type() == L"Online") {
            THROW_IF_FAILED(CbsSessionManager::instance().BindStack(CbsSessionManager::StackSource::Online));        
            stackObj.SetNamedValue(L"source", JsonValue::CreateNumberValue(0));
            stackObj.SetNamedValue(L"argBootdrive", JsonValue::CreateStringValue(L""));
        } else if (img.Type() == L"Offline") {
            THROW_IF_FAILED(CbsSessionManager::instance().BindStack(
                CbsSessionManager::StackSource::Offline,
                img.Bootdrive().c_str()
            ));
            stackObj.SetNamedValue(L"source", JsonValue::CreateNumberValue(1));
            stackObj.SetNamedValue(L"argBootdrive", JsonValue::CreateStringValue(img.Bootdrive()));
        } else throw hresult_invalid_argument{};

        this->m_propertyChanged(*this, winrt::Data::PropertyChangedEventArgs{L"SelectedIndex"});
    }

    winrt::event_token ImageProvider::PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value)
    {
        return this->m_propertyChanged.add(value);
    }

    void ImageProvider::PropertyChanged(winrt::event_token const& token)
    {
        this->m_propertyChanged.remove(token);
    }

    int32_t ImageProvider::ConfigOnlineImage()
    {
        try {
            UFCase::ImageItem res;

            // such as C:\Windows\System32
            std::wstring_view systemDir = Windows::Storage::SystemDataPaths::GetDefault().System();
            auto winDir = systemDir.substr(0, systemDir.find_last_of(L'/'));
            res.Bootdrive(winDir.substr(0, winDir.find_last_of(L'/')));
            res.Type(L"Online");
            res.Icon(Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows11.png")));
            res.Version(L"Windows 11 Build 22000.258");

            m_images.Append(res);
            return m_images.Size()-1;
        } catch (hresult_error const &) {  }
        return Invalid_Index;
    }

    int32_t ImageProvider::ConfigAppConfigImage()
    {
        try {
            if (CbsSessionManager::GetCurrentSource() == CbsSessionManager::StackSource::Offline) {
                UFCase::ImageItem res;
                res.Bootdrive(CbsSessionManager::GetCurrentBootdrive());
                res.Type(L"Offline");
                CompleteImageItem(res);

                m_images.Append(res);
                return m_images.Size()-1;
            }
        } catch (hresult_error const &) {  }

        return Invalid_Index;
    }

    void ImageProvider::ConfigWimImage()
    {
        return;

        // todo: WimGetMountedImages & unique with appConfig
        UFCase::ImageItem res, res2, res3;
        res.Bootdrive(L"D:\\MyCache\\Ws");
        res.Icon(Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows10.png")));
        res.Type(L"Offline");
        res.Version(L"Windows 10 Build 19041.174");

        m_images.Append(res);

        res2.Bootdrive(L"D:\\MyCache\\Vx");
        res2.Icon(Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows7.png")));
        res2.Type(L"Offline");
        res2.Version(L"Windows 7 Build 7601.92");

        m_images.Append(res2);

        res3.Bootdrive(L"D:\\MyCache\\Ck");
        res3.Icon(Media::Imaging::BitmapImage(Uri(L"ms-appx:///Assets/Windows8.png")));
        res3.Type(L"Offline");
        res3.Version(L"Windows 8.1 Build 9600.384");

        m_images.Append(res3);
    }

    // complete image from type & bootdrive
    IAsyncAction ImageProvider::CompleteImageItem(UFCase::ImageItem item) {
        if (item.Type() == L"Online") {
            // todo
        } else if (item.Type() == L"Offline") {
            auto pathWinver = std::filesystem::path(item.Bootdrive().c_str()) / L"Windows" / L"System32" / L"winver.exe";
            auto cbFileVer = GetFileVersionInfoSize(pathWinver.c_str(), 0);
            auto yFileVer = reinterpret_cast<void*>(new std::byte[cbFileVer]);
            GetFileVersionInfo(pathWinver.c_str(), 0, cbFileVer, yFileVer);
            VS_FIXEDFILEINFO *pFileInfo; UINT uLen;
            winrt::check_bool(VerQueryValue(yFileVer, L"\\", reinterpret_cast<void**>(&pFileInfo), &uLen));
            item.Version(std::format(L"Build {}.{}.{}.{}",
                HIWORD(pFileInfo->dwProductVersionMS),
                LOWORD(pFileInfo->dwProductVersionMS),
                HIWORD(pFileInfo->dwProductVersionLS),
                LOWORD(pFileInfo->dwProductVersionLS)).c_str());
            {
                auto major = HIWORD(pFileInfo->dwProductVersionMS), minor = LOWORD(pFileInfo->dwProductVersionMS),
                     build = HIWORD(pFileInfo->dwProductVersionLS);
                if (major == 6) {
                    // includes vista
                    if (minor <= 1) {
                        item.Icon(Win7Icon);
                        item.Version(L"Windows 7 " + item.Version());
                    } else {
                        item.Icon(Win8Icon);
                        if (minor == 2)
                            item.Version(L"Windows 8 " + item.Version());
                        else
                            item.Version(L"Windows 8.1 " + item.Version());
                    }
                } else if (major == 10) {
                    // win11 pre-release is under 22000
                    if (build > 21900) {
                        item.Icon(Win11Icon);
                        item.Version(L"Windows 11 " + item.Version());
                    } else {
                        item.Icon(Win10Icon);
                        item.Version(L"Windows 10 " + item.Version());
                    }
                }
            }
        } else throw winrt::hresult_invalid_argument{};
        co_return;
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
