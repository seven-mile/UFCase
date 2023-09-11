#include "pch.h"

#include "ImageModel.h"
#include "SessionModel.h"
#include "StoreModel.h"

#include "PathUtil.h"

#include <ranges>
#include <wil/registry.h>

namespace winrt::UFCase
{

    static ImageModel *current = nullptr;

    ImageModel::ImageModel(std::filesystem::path const &bootdrive) : bootdrive(bootdrive)
    {
        this->basic_sess = SessionModel::Create(this);
        this->sxs_store = nullptr;
        // ensure hive loaded
        try {
            basic_sess->PerformOperation(CbsOperationTypeInitICSIStore);
        } catch (hresult_no_interface const&) {
            // use package loading instead, which is slower
            basic_sess->ProductPackage();
        }

        if (!current && this->Type() == ImageType::Online)
        {
            current = this;
        }
    }

    ImageModel::~ImageModel()
    {
        delete sxs_store;

        for (auto val : sessions)
        {
            ModelManager<SessionModel>::Erase(val);
        }
        ModelManager<SessionModel>::Erase(basic_sess->GetHandle());
        sessions.clear();
    }

    ImageModel *ImageModel::Create(std::filesystem::path const &bootdrive)
    {
        static std::map<std::wstring, uint64_t> images;
        auto canonical_path = std::filesystem::canonical(bootdrive);
        if (auto it = images.find(canonical_path); it != images.end())
            return &ImageModel::GetInstance(it->second);
        auto res = new ImageModel{canonical_path};
        images[canonical_path] = res->GetHandle();
        return res;
    }

    ImageModel *ImageModel::Current()
    {
        assert(current);
        return current;
    }

    void ImageModel::Current(ImageModel *value)
    {
        current = value;
    }

    SessionModel *ImageModel::OpenSession(_CbsSessionOption option)
    {
        auto &&res = SessionModel::Create(this, option);
        sessions.insert(res->GetHandle());
        return res;
    }

    void ImageModel::CloseSession(uint64_t hSess)
    {
        if (sessions.count(hSess))
        {
            ModelManager<SessionModel>::Erase(hSess);
            sessions.erase(hSess);
        }
        else
        {
            assert(false && "the session to close does not exist");
        }
    }

    StoreModel *ImageModel::SxsStore()
    {
        if (sxs_store)
        {
            return sxs_store;
        }
        else
        {
            return sxs_store = StoreModel::Create(this);
        }
    }

    std::filesystem::path ImageModel::Bootdrive()
    {
        return bootdrive;
    }

    std::filesystem::path ImageModel::WinDir()
    {
        return bootdrive / L"Windows";
    }

    ImageType ImageModel::Type()
    {
        return this->bootdrive == GetOnlineBootdrive() ? ImageType::Online : ImageType::Offline;
    }

    hstring ImageModel::Edition()
    {
        std::wstring name = basic_sess->ProductPackage()->ProductName().c_str();
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

    FOUR_PART_VERSION ImageModel::Version()
    {
        FOUR_PART_VERSION ver;
        short *ptr = reinterpret_cast<short *>(&ver);
        constexpr int offset_ver = 4;
        for (auto &&rng :
             *std::next((basic_sess->ProductPackage()->Identity() | std::ranges::views::split('~'))
                            .begin(),
                        offset_ver) |
                 std::ranges::views::split('.'))
        {
            std::wstring_view str{rng.begin(), rng.end()};
            *ptr++ = static_cast<short>(std::wcstol(str.data(), nullptr, 10));
        }
        std::reverse(ptr - 4, ptr);
        return ver;
    }

    hstring ImageModel::Architecture()
    {
        const int offset_arch = 2;
        auto &&rng = *std::next(
            (basic_sess->ProductPackage()->Identity() | std::ranges::views::split('~')).begin(),
            offset_arch);
        return hstring{std::wstring_view{rng.begin(), rng.end()}};
    }

} // namespace winrt::UFCase
