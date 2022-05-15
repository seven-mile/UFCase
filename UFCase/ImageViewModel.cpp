#include "pch.h"
#include "ImageViewModel.h"
#if __has_include("ImageViewModel.g.cpp")
#include "ImageViewModel.g.cpp"
#endif

#include "SessionModel.h"
#include "AsyncUtil.h"

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
        if (m_version.empty()) {
            m_version = L"Loading";

            DispatchTask(GlobalRes::WorkerQueue(), [this]() -> void {
                auto&& ver = this->m_model.Version();
                if (ver.major == 6) {
                    // includes vista
                    if (ver.minor <= 1) {
                        this->m_version = L"Win 7";
                    } else {
                        if (ver.minor == 2)
                            this->m_version = L"Win 8";
                        else
                            this->m_version = L"Win 8.1";
                    }
                } else if (ver.major == 10) {
                    // win11 pre-release is less than 22000
                    if (ver.build > 21900) {
                        this->m_version = L"Win 11";
                    } else {
                        this->m_version = L"Win 10";
                    }
                } else if (ver.major == 11) {
                    this->m_version = L"Win 11";
                } else {
                    this->m_version = L"Win Unk";
                }

                RunUITask([this]() {
                    this->m_property_changed(*this, Data::PropertyChangedEventArgs{ L"Version" });
                });
            });
        }
        return m_version;
        
    }

    hstring ImageViewModel::Edition()
    {
        if (m_edition.empty()) {
            m_edition = L"Loading";

            DispatchTask(GlobalRes::WorkerQueue(), [this]() -> void {
                this->m_edition = this->m_model.Edition();
                RunUITask([this]() {
                    this->m_property_changed(*this, Data::PropertyChangedEventArgs{ L"Edition" });
                });
            });
        }
        return m_edition;
    }

    hstring ImageViewModel::Bootdrive()
    {
        return m_model.Bootdrive().c_str();
    }

    Media::ImageSource ImageViewModel::Icon()
    {
        static auto Icon7 = Media::Imaging::BitmapImage(Uri(L"ms-appx:///EmbedAssets/Windows7.png")),
            Icon8 = Media::Imaging::BitmapImage(Uri(L"ms-appx:///EmbedAssets/Windows8.png")),
            Icon10 = Media::Imaging::BitmapImage(Uri(L"ms-appx:///EmbedAssets/Windows10.png")),
            Icon11 = Media::Imaging::BitmapImage(Uri(L"ms-appx:///EmbedAssets/Windows11.png"));

        if (!m_icon) {
            if (!m_icon_loading) {
                m_icon_loading = true;

                DispatchTask(GlobalRes::WorkerQueue(), [this]() -> void {
                    if (!this->m_version.empty()) {
                        auto&& ver = this->m_model.Version();
                        if (ver.major == 6) {
                            // includes vista
                            if (ver.minor <= 1) {
                                this->m_icon = Icon7;
                            } else {
                                this->m_icon = Icon8;
                            }
                        } else if (ver.major == 10) {
                            // win11 pre-release is less than 22000
                            if (ver.build <= 21900) {
                                this->m_icon = Icon10;
                            }
                        }
                    }
                    // major >= 11
                    this->m_icon = Icon11;
                    RunUITask([this]() {
                        this->m_property_changed(*this, Data::PropertyChangedEventArgs{ L"Icon" });
                    });
                });
            }
        }
        return m_icon;
    }

    void ImageViewModel::Select()
    {
        // ...
        ::OutputDebugString(std::format(L"Select image {} {}", this->Version(), this->Edition()).c_str());
        ImageModel::Current(&m_model);
    }

    uint64_t ImageViewModel::OpenSession()
    {
        return m_model.OpenSession()->GetHandle();
    }

    void ImageViewModel::CloseSession(uint64_t handle)
    {
        m_model.CloseSession(handle);
    }
}
