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
        winrt::IAsyncAction NavigateTo(winrt::hstring page_name);
        void HandleHrError(winrt::hresult_error err);

        void UpdateTitleByConfig();
        void ConfigWindowTitlebar();

        // Control Events
        void NavigationView_SelectionChanged(NavigationView const& sender, NavigationViewSelectionChangedEventArgs const& args);
        void NavView_DisplayModeChanged(NavigationView const& sender, NavigationViewDisplayModeChangedEventArgs const& args);

        UFCase::ImageProvider ImageProv();

    private:
        UFCase::ImageProvider m_imgprov;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
