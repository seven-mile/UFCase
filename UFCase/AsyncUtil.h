#pragma once

#include "pch.h"

#include "GlobalUtil.h"

#include <type_traits>
#include <coroutine>
#include <exception>
#include <functional>
#include <memory>
#include <mutex>
#include <wil/resource.h>

namespace winrt::UFCase
{

    template <typename T, typename Promise = std::void_t<>> struct is_awaitable : std::false_type
    {
    };

    template <typename T>
    struct is_awaitable<T, std::void_t<typename std::coroutine_traits<T>::promise_type>>
        : std::true_type
    {
    };

    template <typename T> inline constexpr bool is_awaitable_v = is_awaitable<T>::value;

    template <typename T> inline fire_and_forget no_await(T t)
    {
        if constexpr (std::is_invocable_v<T>)
        {
            if constexpr (is_awaitable_v<decltype(t())>)
            {
                co_await t();
            }
            else
            {
                t();
            }
        }
        else
        {
            co_await t;
        }
        co_return;
    }

    inline void DispatchTask(Microsoft::UI::Dispatching::DispatcherQueue Q,
                             std::function<void()> const &H,
                             Microsoft::UI::Dispatching::DispatcherQueuePriority P =
                                 Microsoft::UI::Dispatching::DispatcherQueuePriority::Normal)
    {
        if (!Q.TryEnqueue(P, H))
        {
            throw hresult_error(E_ABORT, L"The dispatcher queue is shutting down.");
        }
    }

    struct DispatchTaskState
    {
        explicit DispatchTaskState(std::function<IAsyncAction()> const &handler)
            : Handler(handler), Completion(wil::EventOptions::None)
        {
        }

        std::function<IAsyncAction()> Handler;
        wil::unique_event Completion;
        std::mutex Mutex;
        std::exception_ptr Error;
    };

    inline fire_and_forget DispatchTaskAsyncWorker(std::shared_ptr<DispatchTaskState> state)
    {
        try
        {
            co_await state->Handler();
        }
        catch (...)
        {
            std::scoped_lock lock(state->Mutex);
            state->Error = std::current_exception();
        }
        state->Completion.SetEvent();
    }

    inline IAsyncAction DispatchTaskAsync(
        Microsoft::UI::Dispatching::DispatcherQueue Q, std::function<IAsyncAction()> const &H,
        Microsoft::UI::Dispatching::DispatcherQueuePriority P =
            Microsoft::UI::Dispatching::DispatcherQueuePriority::Normal)
    {
        auto state = std::make_shared<DispatchTaskState>(H);

        if (!Q.TryEnqueue(P, [state]() { DispatchTaskAsyncWorker(state); }))
        {
            throw hresult_error(E_ABORT, L"The dispatcher queue is shutting down.");
        }

        co_await resume_on_signal(state->Completion.get());
        {
            std::scoped_lock lock(state->Mutex);
            if (state->Error)
            {
                std::rethrow_exception(state->Error);
            }
        }
    }
    inline void RunUITask(std::function<void()> const &H,
                          Microsoft::UI::Dispatching::DispatcherQueuePriority P =
                              Microsoft::UI::Dispatching::DispatcherQueuePriority::Normal)
    {
        DispatchTask(GlobalRes::UIQueue(), H, P);
    }

    inline IAsyncAction RunUITaskAsync(
        std::function<IAsyncAction()> const &H,
        Microsoft::UI::Dispatching::DispatcherQueuePriority P =
            Microsoft::UI::Dispatching::DispatcherQueuePriority::Normal)
    {
        co_await DispatchTaskAsync(GlobalRes::UIQueue(), H, P);
        co_return;
    }

} // namespace winrt::UFCase
