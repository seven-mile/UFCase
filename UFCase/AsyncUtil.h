#pragma once

#include "pch.h"
#include <type_traits>
#include <coroutine>

namespace winrt::UFCase {

    template<typename T, typename Promise = std::void_t<>>
    struct is_awaitable : std::false_type {};

    template<typename T>
    struct is_awaitable<T, std::void_t<typename std::coroutine_traits<T>::promise_type>> : std::true_type {};

    template<typename T>
    inline constexpr bool is_awaitable_v = is_awaitable<T>::value;

    template<typename T>
    fire_and_forget no_await(T t)
    {
        try {
            if constexpr (std::is_invocable_v<T>)
            {
                co_await t();
            }
            else
            {
                co_await t;
            }
        } catch (...) {
            auto hr = to_hresult();
            hresult_error err{ hr };
            OutputDebugString(err.message().c_str());
            OutputDebugString(L"\n");
            throw_hresult(hr);
        }
    }

}
