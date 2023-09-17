#include "pch.h"
#include "ImageModel.h"

#include "SessionModel.h"
#include "StoreModel.h"

#include "ServicingApi/SSShimApi.h"

#include "Utils/PathUtil.h"

#include <ranges>

namespace winrt::UFCase::Isolation::implementation
{
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