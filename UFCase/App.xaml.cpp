﻿#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"

#include "CbsProviderManager.h"

#include "AppConfig.h"
#include "ImageSelectorHelper.h"
#include "PathUtil.h"

namespace winrt {
    using namespace Windows::Foundation;
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

        window = make<MainWindow>();
        this->Resources().Insert(box_value(L"MainWindowInstance"), window);

        window.Activate();

        co_return;
    }

}

