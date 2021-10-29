#include "pch.h"
#include "ImageProvider.h"
#if __has_include("ImageProvider.g.cpp")
#include "ImageProvider.g.cpp"
#endif
#if __has_include("ImageItem.g.cpp")
#include "ImageItem.g.cpp"
#endif

#include "SysInfoStaticProvider.g.h"

#include "AppConfig.h"
#include "CbsSessionManager.h"

#include <filesystem>

#pragma comment(lib, "Version.lib")

namespace winrt::UFCase::implementation
{
    
    ImageProvider::ImageProvider()
    {
        auto onlineIndex = this->ConfigOnlineImage();
        this->SelectedIndex(onlineIndex);
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
        if (m_selectedIdx == value)
            return;

        m_selectedIdx = value;
        //CbsSessionManager::instance().ReleaseStack();

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
            std::filesystem::path systemDir = Windows::Storage::SystemDataPaths::GetDefault().System().c_str();
            
            res.Bootdrive(systemDir.parent_path().parent_path().c_str());
            res.Type(L"Online");

            auto prov = SysInfoStaticProvider(res);
            int major, minor, build, revision;
            if (swscanf_s(prov.OSVersion().c_str(), L"%d.%d.%d.%d", &major, &minor, &build, &revision) < 0)
                throw_hresult(E_FAIL);

            this->CompleteImageItem(res, major, minor, build);
            res.Version(res.Version() + L"Build " + prov.OSVersion());

            m_images.Append(res);
            return m_images.Size()-1;
        } catch (hresult_error const &) {  }
        return Invalid_Index;
    }

    void ImageProvider::ConfigWimImage()
    {
        // todo: WimGetMountedImages & unique with appConfig
    }

    // complete image from type & bootdrive
    void ImageProvider::CompleteImageItem(UFCase::ImageItem item, int major, int minor, int build) {
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
            // win11 pre-release is less than 22000
            if (build > 21900) {
                item.Icon(Win11Icon);
                item.Version(L"Windows 11 " + item.Version());
            } else {
                item.Icon(Win10Icon);
                item.Version(L"Windows 10 " + item.Version());
            }
        }
    }


    ImageItem::ImageItem(hstring const& type, hstring const& ver, hstring const& bootdrv, Media::ImageSource const& icon)
        : m_type(type), m_ver(ver), m_bootdrv(bootdrv), m_icon(icon) { }

    ImageItem::ImageItem(hstring const& type, hstring const& ver, hstring const& bootdrv, guid const& wimGuid, Media::ImageSource const& icon)
        : m_type(type), m_ver(ver), m_bootdrv(bootdrv), m_wimGuid(wimGuid), m_icon(icon) { }

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
    guid ImageItem::WimGuid()
    {
        return m_wimGuid;
    }
    void ImageItem::WimGuid(guid const& value)
    {
        m_wimGuid = value;
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
