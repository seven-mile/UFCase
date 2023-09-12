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
} // namespace winrt

namespace winrt::UFCase::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow(UFCase::ImageSelectorViewModel vm);

        // Override InitializeComponent
        void InitializeComponent();

        void ConfigWindowTitlebar();

        // Control Events
        void NavView_ItemInvoked(NavigationView const &sender,
                                 NavigationViewItemInvokedEventArgs const &args);
        void NavView_DisplayModeChanged(NavigationView const &sender,
                                        NavigationViewDisplayModeChangedEventArgs const &args);
        void NavView_BackRequested(NavigationView const &sender,
                                   NavigationViewBackRequestedEventArgs const &args);

        UFCase::ImageSelectorViewModel ViewModel();

      private:
        winrt::DispatcherQueueController m_dispatcherQueueController{nullptr};
        UFCase::ImageSelectorViewModel m_view_model{nullptr};
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
} // namespace winrt::UFCase::factory_implementation
