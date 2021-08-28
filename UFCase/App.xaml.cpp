#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"

#include "CbsSessionManager.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace UFCase;
using namespace UFCase::implementation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
    InitializeComponent();

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
    {
        if (IsDebuggerPresent())
        {
            auto errorMessage = e.Message();
            __debugbreak();
        }
    });
#endif
}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used such as when the application is launched to open a specific file.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(LaunchActivatedEventArgs const&)
{
    // todo: use a setting manager to initialize session mgr.
    // defaultly servicing online image.
    THROW_IF_FAILED(CbsSessionManager::instance().BindStack(CbsSessionManager::StackSource::Online));
    //THROW_IF_FAILED(CbsSessionManager::instance().BindStack(CbsSessionManager::StackSource::Offline, L"D:\\MyCache\\Eb"));

    window = make<MainWindow>();
    window.Activate();
}
