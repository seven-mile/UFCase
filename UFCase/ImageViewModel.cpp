#include "pch.h"
#include "ImageViewModel.h"
#if __has_include("ImageViewModel.g.cpp")
#include "ImageViewModel.g.cpp"
#endif

#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>

namespace winrt::UFCase::implementation
{
    ImageViewModel::ImageViewModel(uint64_t hModel) :
        m_model(ImageModel::GetInstance(hModel))
    {

    }

    hstring ImageViewModel::Type()
    {
        return m_model.Type() == ImageType::Offline ? L"Offline" : L"Online";
    }

    hstring ImageViewModel::Version()
    {
        auto&& ver = m_model.Version();
        if (ver.major == 6) {
            // includes vista
            if (ver.minor <= 1) {
                return L"Win 7";
            } else {
                if (ver.minor == 2)
                    return L"Win 8";
                else
                    return L"Win 8.1";
            }
        } else if (ver.major == 10) {
            // win11 pre-release is less than 22000
            if (ver.build > 21900) {
                return L"Win 11";
            } else {
                return L"Win 10";
            }
        } else if (ver.major == 11) {
            return L"Win 11";
        } else {
            return L"Win Unk";
        }
    }

    hstring ImageViewModel::Edition()
    {
        return m_model.Edition();
    }

    hstring ImageViewModel::Bootdrive()
    {
        return m_model.Bootdrive().c_str();
    }

    Media::ImageSource ImageViewModel::Icon()
    {
        auto&& ver = m_model.Version();
        if (ver.major == 6) {
            // includes vista
            if (ver.minor <= 1) {
                return Media::Imaging::BitmapImage(Uri(L"ms-appx:///EmbedAssets/Windows7.png"));
            } else {
                return Media::Imaging::BitmapImage(Uri(L"ms-appx:///EmbedAssets/Windows8.png"));
            }
        } else if (ver.major == 10) {
            // win11 pre-release is less than 22000
            if (ver.build <= 21900) {
                return Media::Imaging::BitmapImage(Uri(L"ms-appx:///EmbedAssets/Windows10.png"));
            }
        }
        // major >= 11
        return Media::Imaging::BitmapImage(Uri(L"ms-appx:///EmbedAssets/Windows11.png"));
    }

    void ImageViewModel::Select()
    {
        // ...
        ::OutputDebugString(std::format(L"Select image {} {}", this->Version(), this->Edition()).c_str());
        ImageModel::Current(&m_model);
    }
}
