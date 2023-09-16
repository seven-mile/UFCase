#pragma once

#include <memory>

namespace winrt::UFCase
{
    inline auto GetGlobalMalloc()
    {
        static IMalloc *pMalloc = nullptr;
        if (!pMalloc)
            THROW_IF_FAILED(CoGetMalloc(1, &pMalloc));
        return pMalloc;
    }

    template <class T> constexpr auto malloc_deleter = [](T *ptr) { GetGlobalMalloc()->Free(ptr); };

    template <class T> using unique_malloc = std::unique_ptr<T, decltype(malloc_deleter<T>)>;

    template <class T> inline constexpr unique_malloc<T> make_malloc(T *&raw)
    {
        // auto &&val = std::make_unique<T, decltype(malloc_deleter<T>)>(*raw);
        auto val = unique_malloc<T>(static_cast<T *>(raw), malloc_deleter<T>);
        raw = nullptr;
        return std::move(val);
    }

    using unique_malloc_wstring = unique_malloc<wchar_t>;

} // namespace winrt::UFCase
