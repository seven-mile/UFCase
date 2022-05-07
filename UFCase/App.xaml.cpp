#include "pch.h"

#include "App.xaml.h"

#include "AppConfig.h"
#include "ImageSelectorHelper.h"
#include "PathUtil.h"
#include "GlobalUtil.h"


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
        // Allow server to impersonate client, init default COM security
        //LOG_IF_FAILED(CoInitializeSecurity(nullptr, -1, nullptr, nullptr,
        //    RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr));


        std::filesystem::path pathAppData = GetOnlineRoamingAppDataDir();

        pathAppData /= L".UFCase";

        constexpr wchar_t cfg_filename[] = L"Config.json";

        if (auto cfg_path = pathAppData / cfg_filename;
                std::filesystem::exists(cfg_path)) {
            AppConfig::ReadAppConfigFromFile(cfg_path.c_str());
        } else {
            if (!std::filesystem::exists(pathAppData))
                winrt::check_bool(std::filesystem::create_directories(pathAppData));
            AppConfig::WriteAppConfigToFile(cfg_path.c_str());
        }

        co_await SearchImages();

        window = UFCase::MainWindow();

        window.Activate();

        co_return;
    }

}

