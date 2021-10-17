#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"

#include "CbsSessionManager.h"

#include "AppConfig.hpp"

#include <winrt/Windows.Storage.h>

using namespace winrt;
namespace winrt {
    using namespace Windows::Foundation;
    using namespace Windows::Storage;
    using namespace Microsoft::UI::Xaml;
    using namespace Microsoft::UI::Xaml::Controls;
    using namespace Microsoft::UI::Xaml::Navigation;
}

namespace winrt::UFCase::implementation
{
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
    IAsyncAction App::OnLaunched(LaunchActivatedEventArgs const&)
    {
        // todo: use a setting manager to initialize session mgr.
        // defaultly servicing online image.

        auto pathRoaming = AppDataPaths::GetDefault().RoamingAppData();
        constexpr wchar_t cfg_filename[] = L"Config.json";

        if (auto cfg_path = std::filesystem::path(pathRoaming.c_str()) / cfg_filename;
                std::filesystem::exists(cfg_path)) {
            co_await ReadAppConfigFromFile(g_appConfigPath = cfg_path.c_str());
        } else {
            co_await ApplicationData::Current().RoamingFolder().CreateFileAsync(cfg_filename);

            co_await ReadAppConfigFromFile(L"ms-appx:///Configs/DefaultAppConfig.json");
            co_await WriteAppConfigToFile(g_appConfigPath = cfg_path.c_str());
        }

        if (static_cast<CbsSessionManager::StackSource>(g_appConfig.GetNamedObject(L"stack").GetNamedNumber(L"source"))
            == CbsSessionManager::StackSource::Online) {
            THROW_IF_FAILED(CbsSessionManager::instance().BindStack(CbsSessionManager::StackSource::Online));        
        } else {
            THROW_IF_FAILED(CbsSessionManager::instance().BindStack(CbsSessionManager::StackSource::Offline,
                g_appConfig.GetNamedObject(L"stack").GetNamedString(L"argBootdrive").c_str()));
        }


        window = make<MainWindow>();
        window.Activate();
        co_return;
    }

}

