﻿#pragma once
#include "MainWindow.g.h"

// For access to WindowId
#include <winrt/Microsoft.UI.h>
// For access to hwnd interop methods
#include <winrt/Microsoft.UI.Interop.h>
// For the WinRT windowing APIs
#include <winrt/Microsoft.UI.Windowing.h>

// This include file is needed for the XAML Native Window Interop.
#include "microsoft.ui.xaml.window.h"

namespace winrt
{
    using namespace Microsoft::UI::Windowing;
    using namespace Microsoft::UI;
    using Windows::UI::Color;
}

namespace winrt::UFCase::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        // Internal Functions
        winrt::AppWindow GetAppWindowForCurrentWindow();
        winrt::IAsyncAction NavigateTo(winrt::hstring page_name);
        void HandleHrError(winrt::hresult_error err);

        // Control Events
        void NavigationView_SelectionChanged(NavigationView const& sender, NavigationViewSelectionChangedEventArgs const& args);
        void NavView_DisplayModeChanged(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewDisplayModeChangedEventArgs const& args);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
