#pragma once
#include "MainWindow.g.h"

#include "ImageItem.g.h"
#include "ImageProvider.g.h"


// For access to WindowId
#include <winrt/Microsoft.UI.h>
// For access to hwnd interop methods
#include <winrt/Microsoft.UI.Interop.h>
// For the WinRT windowing APIs
#include <winrt/Microsoft.UI.Windowing.h>

// This include file is needed for the XAML Native Window Interop.
#include "microsoft.ui.xaml.window.h"

#include <winrt/Microsoft.UI.Xaml.Documents.h>
#include <winrt/Microsoft.UI.Composition.SystemBackdrops.h>

#include <stack>

namespace winrt
{
    using namespace Microsoft::UI::Windowing;
    using namespace Microsoft::UI;
    using Windows::UI::Color;

    using namespace Microsoft::UI::Composition::SystemBackdrops;
}

namespace winrt::UFCase::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        // Internal Functions
        winrt::AppWindow GetAppWindowForCurrentWindow();
        winrt::IAsyncAction NavigateTo(NavigationViewItemBase item);
        void HandleHrError(winrt::hresult_error err);

        void UpdateTitleByConfig();
        void ConfigWindowTitlebar();

        // Control Events
        void NavView_Loaded(IInspectable const& sender, RoutedEventArgs const& e);
        void NavView_ItemInvoked(NavigationView const& sender, NavigationViewItemInvokedEventArgs const& args);
        void NavView_DisplayModeChanged(NavigationView const& sender, NavigationViewDisplayModeChangedEventArgs const& args);
        void NavView_BackRequested(NavigationView const& sender, NavigationViewBackRequestedEventArgs const& args);

        UFCase::ImageProvider ImageProv();

    private:
        UFCase::ImageProvider m_imgprov;

        std::stack<NavigationViewItemBase> m_stackNavItem;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
