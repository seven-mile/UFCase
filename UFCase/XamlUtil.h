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

    inline Microsoft::UI::Xaml::Input::XamlUICommand CreateXamlUICommand(
        hstring const &label, hstring const &icon,
        std::function<void(IInspectable)> const &execution,
        std::function<bool(IInspectable)> const &can_exec = [](IInspectable) { return true; })
    {

        Microsoft::UI::Xaml::Input::XamlUICommand cmd{};

        cmd.Label(label);
        if (!icon.empty())
        {
            FontIconSource font_icon{};
            font_icon.FontFamily(GlobalRes::SymbolThemeFontFamily());
            font_icon.Glyph(icon);
            cmd.IconSource(font_icon);
        }

        cmd.Command(make<implementation::RelayCommand>(execution, can_exec));

        return cmd;
    }

    inline Microsoft::UI::Xaml::Input::XamlUICommand CreateXamlUICommand(
        hstring const &label, Symbol const &icon,
        std::function<void(IInspectable)> const &execution,
        std::function<bool(IInspectable)> const &can_exec = [](IInspectable) { return true; })
    {

        Microsoft::UI::Xaml::Input::XamlUICommand cmd{};

        cmd.Label(label);
        SymbolIconSource sym_icon{};
        sym_icon.Symbol(icon);

        cmd.IconSource(sym_icon);

        cmd.Command(make<implementation::RelayCommand>(execution, can_exec));

        return cmd;
    }

#define HandleCommand(name, label, icon)                                                           \
    Microsoft::UI::Xaml::Input::XamlUICommand name##_cmd = CreateXamlUICommand(                    \
        label, icon, [this](IInspectable) { GeneratedCommandHandler_##name(); });                  \
    Microsoft::UI::Xaml::Input::XamlUICommand name##Command()                                      \
    {                                                                                              \
        return name##_cmd;                                                                         \
    }                                                                                              \
    void GeneratedCommandHandler_##name()

#define HandleCommandAsync(name, label, icon)                                                      \
    Microsoft::UI::Xaml::Input::XamlUICommand name##_cmd = CreateXamlUICommand(                    \
        label, icon, [this](IInspectable) { no_await(GeneratedCommandHandler_##name()); });        \
    Microsoft::UI::Xaml::Input::XamlUICommand name##Command()                                      \
    {                                                                                              \
        return name##_cmd;                                                                         \
    }                                                                                              \
    IAsyncAction GeneratedCommandHandler_##name()

#define HandleCommandEx(name, label, icon, can_exec)                                               \
    Microsoft::UI::Xaml::Input::XamlUICommand name##_cmd = CreateXamlUICommand(                    \
        label, icon, [this](IInspectable) { GeneratedCommandHandler_##name(); }, can_exec);        \
    Microsoft::UI::Xaml::Input::XamlUICommand name##Command()                                      \
    {                                                                                              \
        return name##_cmd;                                                                         \
    }                                                                                              \
    void GeneratedCommandHandler_##name()

#define HandleCommandExAsync(name, label, icon, can_exec)                                          \
    Microsoft::UI::Xaml::Input::XamlUICommand name##_cmd = CreateXamlUICommand(                    \
        label, icon, [this](IInspectable) { no_await(GeneratedCommandHandler_##name()); },         \
        can_exec);                                                                                 \
    Microsoft::UI::Xaml::Input::XamlUICommand name##Command()                                      \
    {                                                                                              \
        return name##_cmd;                                                                         \
    }                                                                                              \
    IAsyncAction GeneratedCommandHandler_##name()

} // namespace winrt::UFCase
