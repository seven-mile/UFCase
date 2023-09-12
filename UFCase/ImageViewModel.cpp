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

    enum class WindowsVersions
    {
        Vista,
        Win7,
        Win8,
        WinBlue,
        Win10,
        Win11,
    };

    WindowsVersions ConvertVersion(FOUR_PART_VERSION raw_ver)
    {
        if (raw_ver.major < 6)
        {
            throw hresult_not_implemented{};
        }

        if (raw_ver.major == 6)
        {
            // includes vista
            if (raw_ver.minor <= 1)
            {
                return WindowsVersions::Win7;
            }
            else
            {
                if (raw_ver.minor == 2)
                    return WindowsVersions::Win8;
                else
                    return WindowsVersions::WinBlue;
            }
        }
        else if (raw_ver.major == 10)
        {
            // win11 pre-release is less than 22000
            if (raw_ver.build > 21900)
            {
                return WindowsVersions::Win11;
            }
            else
            {
                return WindowsVersions::Win10;
            }
        }
        // other >= 10
        return WindowsVersions::Win11;
    }

    ImageViewModel::ImageViewModel(uint64_t hModel) : m_model(ImageModel::GetInstance(hModel))
    {
    }

    hstring ImageViewModel::Type()
    {
        return m_model.Type() == ImageType::Offline ? L"Offline" : L"Online";
    }

    hstring ImageViewModel::Version()
    {
        if (m_state == LoadingState::Uninitialized)
        {
            PullData();
        }
        return m_version;
    }

    hstring ImageViewModel::Edition()
    {
        return m_edition;
    }

    hstring ImageViewModel::Bootdrive()
    {
        return m_model.Bootdrive().c_str();
    }

    Media::ImageSource ImageViewModel::Icon()
    {
        return m_icon;
    }

    void ImageViewModel::Select()
    {
        ::OutputDebugString(
            std::format(L"Select image {} {}", this->Version(), this->Edition()).c_str());
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

    IAsyncAction ImageViewModel::PullData()
    {
        apartment_context ui_thread;

        m_state = LoadingState::Loading;

        co_await resume_background();

        this->m_edition = m_model.Edition();

        auto ver = m_model.Version();

        co_await ui_thread;

        switch (ConvertVersion(ver))
        {
        case WindowsVersions::Vista:
            this->m_version = L"Vista";
            break;
        case WindowsVersions::Win7:
            this->m_version = L"Win 7";
            break;
        case WindowsVersions::Win8:
            this->m_version = L"Win 8";
            break;
        case WindowsVersions::WinBlue:
            this->m_version = L"Win 8.1";
            break;
        case WindowsVersions::Win10:
            this->m_version = L"Win 10";
            break;
        case WindowsVersions::Win11:
            this->m_version = L"Win 11";
            break;
        default:
            this->m_version = L"Win Unk";
            break;
        }

        auto get_icon = [](hstring name) {
            return Application::Current()
                .Resources()
                .Lookup(box_value(name))
                .as<Media::Imaging::SvgImageSource>();
        };

        switch (ConvertVersion(ver))
        {
        case WindowsVersions::Vista:
        case WindowsVersions::Win7:
            this->m_icon = get_icon(L"WinAeroIcon");
            break;
        case WindowsVersions::Win8:
        case WindowsVersions::WinBlue:
        case WindowsVersions::Win10:
            this->m_icon = get_icon(L"WinModernIcon");
            break;
        case WindowsVersions::Win11:
        default:
            this->m_icon = get_icon(L"WinFluentIcon");
            break;
        }

        this->m_state = LoadingState::Loaded;

        NotifyPropChange(L"Version");
        NotifyPropChange(L"Edition");
        NotifyPropChange(L"Icon");
        NotifyPropChange(L"Selectable");
    }

} // namespace winrt::UFCase::implementation
