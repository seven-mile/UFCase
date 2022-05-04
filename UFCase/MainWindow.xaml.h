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

#include <winrt/Microsoft.UI.Composition.SystemBackdrops.h>
#include <winrt/Windows.System.h>
#include <winrt/Microsoft.UI.Xaml.Documents.h>

namespace winrt
{
    using namespace Microsoft::UI::Windowing;
    using namespace Microsoft::UI;
    using Windows::UI::Color;

    using namespace Microsoft::UI::Composition;
    using namespace Microsoft::UI::Composition::SystemBackdrops;
    using namespace Microsoft::UI::Xaml;
    using namespace Windows::System;
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

        // Mica helpers
        void SetBackdrop();
        winrt::DispatcherQueueController CreateSystemDispatcherQueueController();
        void SetupSystemBackdropConfiguration();
        winrt::SystemBackdropTheme ConvertToSystemBackdropTheme(winrt::ElementTheme const& theme);

    private:
        winrt::SystemBackdropConfiguration m_configuration{ nullptr };
        winrt::MicaController m_micaController{ nullptr };
        winrt::Window::Activated_revoker m_activatedRevoker;
        winrt::Window::Closed_revoker m_closedRevoker;
        winrt::FrameworkElement::ActualThemeChanged_revoker m_themeChangedRevoker;
        winrt::FrameworkElement m_rootElement{ nullptr };
        winrt::DispatcherQueueController m_dispatcherQueueController{ nullptr };
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
