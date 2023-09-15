#include "pch.h"
#include "ImageModel.h"
#if __has_include("ImageModel.g.cpp")
#include "ImageModel.g.cpp"
#endif

#include "SessionModel.h"
#include "../UFCase/PathUtil.h"
#include "StoreModel.h"

#include <ranges>

namespace winrt::UFCase::Isolation::implementation
{
    void ImageModel::Initialize()
    {
        this->basic_sess = make<implementation::SessionModel>(*get_strong());
        this->sxs_store = nullptr;
        // ensure hive loaded
        try
        {
            basic_sess.PerformOperation(CbsOperationType::InitICSIStore);
        }
        catch (hresult_no_interface const &)
        {
            // use package loading instead, which is slower
            [[maybe_unused]] auto _ = basic_sess.ProductPackage();
        }
    }

    Isolation::SessionModel ImageModel::OpenSession(DWORD option)
    {
        return make<implementation::SessionModel>(*get_strong(), option);
    }

    Isolation::SessionModel ImageModel::BasicSession()
    {
        if (basic_sess)
        {
            return basic_sess;
        }
        else
        {
            return basic_sess = make<implementation::SessionModel>(*get_strong());
        }
    }

    Isolation::StoreModel ImageModel::SxsStore()
    {
        if (sxs_store)
        {
            return sxs_store;
        }
        else
        {
            return sxs_store = make<implementation::StoreModel>(*get_strong());
        }
    }

    hstring ImageModel::Bootdrive()
    {
        return m_bootdrive.c_str();
    }

    hstring ImageModel::WinDir()
    {
        return (m_bootdrive / L"Windows").c_str();
    }

    ImageType ImageModel::Type()
    {
        auto online_drive = GetOnlineBootdrive();
        return m_bootdrive == online_drive ? ImageType::Online : ImageType::Offline;
    }

    hstring ImageModel::Edition()
    {
        std::wstring name = BasicSession().ProductPackage().ProductName().c_str();
        assert(name.ends_with(L"Edition"));
        const auto idx = name.find_last_of(L'-') + 1;
        constexpr int suffix_len = 7;
        return name.substr(idx, name.size() - idx - suffix_len).c_str();
    }

    bool ImageModel::IsWinPE()
    {
        if (this->Type() == ImageType::Online)
        {
            wil::unique_hkey hkey;
            auto lst =
                ::RegOpenKey(HKEY_LOCAL_MACHINE, L"Microsoft\\Windows NT\\CurrentVersion\\WinPE",
                             wil::out_param(hkey));
            SetLastError(0);

            if (lst == ERROR_SUCCESS)
            {
                return true;
            }
            else if (lst == ERROR_FILE_NOT_FOUND)
            {
                return false;
            }
            else
            {
                throw winrt::hresult_error{HRESULT_FROM_WIN32(lst)};
            }
        }
        else
        {
            // todo: use offline reg
            return false;
        }
    }

    // Package Identity Format:
    // [Product]-[Feature]-Package~[PublicKeyToken]~[Architecture]~[Language]~[Version]

    ImageVersion ImageModel::Version()
    {
        ImageVersion ver;
        uint32_t *ptr = reinterpret_cast<uint32_t *>(&ver);
        constexpr int offset_ver = 4;
        auto ident_str = BasicSession().ProductPackage().Identity();
        for (auto &&rng :
             *std::next((ident_str | std::ranges::views::split('~')).begin(), offset_ver) |
                 std::ranges::views::split('.'))
        {
            std::wstring_view str{rng.begin(), rng.end()};
            *ptr++ = static_cast<uint32_t>(std::wcstol(str.data(), nullptr, 10));
        }
        return ver;
    }

    hstring ImageModel::Architecture()
    {
        const int offset_arch = 2;
        auto ident_str = BasicSession().ProductPackage().Identity();
        auto &&rng = *std::next((ident_str | std::ranges::views::split('~')).begin(), offset_arch);
        return hstring{std::wstring_view{rng.begin(), rng.end()}};
    }
} // namespace winrt::UFCase::Isolation::implementation
