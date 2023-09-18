#pragma once
#include "pch.h"
#include "GlobalUtil.h"
#include "AsyncUtil.h"

#include "RelayCommand.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>

#include <functional>

namespace winrt::UFCase
{

    inline UFCase::RelayCommand CreateRelayCommand(
        std::function<void(IInspectable)> const &execution,
        std::function<bool(IInspectable)> const &can_exec = [](IInspectable) { return true; })
    {
        return make<implementation::RelayCommand>(execution, can_exec);
    }

#define HandleCommand(name)                                                                        \
    UFCase::RelayCommand name##_cmd = CreateRelayCommand(                                          \
        [self = get_strong()](IInspectable) { self->GeneratedCommandHandler_##name(); });          \
    UFCase::RelayCommand name##Relay()                                                             \
    {                                                                                              \
        return name##_cmd;                                                                         \
    }                                                                                              \
    void GeneratedCommandHandler_##name()

#define HandleCommandAsync(name)                                                                   \
    UFCase::RelayCommand name##_cmd = CreateRelayCommand([self = get_strong()](IInspectable) {     \
        no_await(self->GeneratedCommandHandler_##name());                                          \
    });                                                                                            \
    UFCase::RelayCommand name##Relay()                                                             \
    {                                                                                              \
        return name##_cmd;                                                                         \
    }                                                                                              \
    IAsyncAction GeneratedCommandHandler_##name()

#define HandleCommandEx(name, can_exec)                                                            \
    UFCase::RelayCommand name##_cmd = CreateRelayCommand(                                          \
        [self = get_strong()](IInspectable) { self->GeneratedCommandHandler_##name(); },           \
        can_exec);                                                                                 \
    UFCase::RelayCommand name##Relay()                                                             \
    {                                                                                              \
        return name##_cmd;                                                                         \
    }                                                                                              \
    void GeneratedCommandHandler_##name()

#define HandleCommandExAsync(name, can_exec)                                                       \
    UFCase::RelayCommand name##_cmd = CreateRelayCommand(                                          \
        [self = get_strong()](IInspectable) { no_await(self->GeneratedCommandHandler_##name()); }, \
        can_exec);                                                                                 \
    UFCase::RelayCommand name##Relay()                                                             \
    {                                                                                              \
        return name##_cmd;                                                                         \
    }                                                                                              \
    IAsyncAction GeneratedCommandHandler_##name()

} // namespace winrt::UFCase
