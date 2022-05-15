#pragma once

#include "pch.h"

#include "GlobalUtil.h"

#include <type_traits>
#include <coroutine>
#include <functional>

namespace winrt::UFCase {

    template<typename T, typename Promise = std::void_t<>>
    struct is_awaitable : std::false_type {};

    template<typename T>
    struct is_awaitable<T, std::void_t<typename std::coroutine_traits<T>::promise_type>> : std::true_type {};

    template<typename T>
    inline constexpr bool is_awaitable_v = is_awaitable<T>::value;

    template<typename T>
    inline fire_and_forget no_await(T t)
    {
        if constexpr (std::is_invocable_v<T>)
        {
            if constexpr (is_awaitable_v<decltype(t())>) {
                co_await t();
            } else {
                t();
            }
        }
        else
        {
            co_await t;
        }
        co_return;
    }

    inline void DispatchTask(
        Microsoft::UI::Dispatching::DispatcherQueue Q,
        std::function<void()> const &H) {

        auto* pH = new std::function<void()>{ H };

        Q.TryEnqueue([pH]() -> void {
            (*pH)();
            delete pH;
        });
    }

    inline IAsyncAction DispatchTaskAsync(
        Microsoft::UI::Dispatching::DispatcherQueue Q,
        std::function<IAsyncAction()> const &H) {

        HANDLE comp_event = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        auto* pH = new std::function<IAsyncAction()>{ H };

        Q.TryEnqueue([=]() -> IAsyncAction {
            // use it after the suspension point
            auto* copied_pH = pH;
            auto* copied_comp_event = comp_event;
            co_await (*pH)();
            SetEvent(copied_comp_event);
            CloseHandle(copied_comp_event);
            delete copied_pH;
        });

        co_await resume_on_signal(comp_event);
        co_return;
    }

    inline void RunUITask(std::function<void()> const &H) {
        DispatchTask(GlobalRes::MainWnd().DispatcherQueue(), H);
    }

    inline IAsyncAction RunUITaskAsync(std::function<IAsyncAction()> const& H) {
        co_await DispatchTaskAsync(GlobalRes::MainWnd().DispatcherQueue(), H);
        co_return;
    }

}
