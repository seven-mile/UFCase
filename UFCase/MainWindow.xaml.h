#pragma once
#include "MainWindow.g.h"

// For access to WindowId
#include <winrt/Microsoft.UI.h>
// For access to hwnd interop methods
#include <winrt/Microsoft.UI.Interop.h>
// For the WinRT windowing APIs
#include <winrt/Microsoft.UI.Windowing.h>

// This include file is needed for the XAML Native Window Interop.
#include "microsoft.ui.xaml.window.h"

#include <winrt/Microsoft.UI.Xaml.Documents.h>

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

        void UpdateTitleByConfig();
        void ConfigWindowTitlebar();

        // Control Events
        void NavView_ItemInvoked(NavigationView const& sender, NavigationViewItemInvokedEventArgs const& args);
        void NavView_DisplayModeChanged(NavigationView const& sender, NavigationViewDisplayModeChangedEventArgs const& args);
        void NavView_BackRequested(NavigationView const& sender, NavigationViewBackRequestedEventArgs const& args);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
