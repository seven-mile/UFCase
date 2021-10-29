#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"

#include "CbsSessionManager.h"

#include "AppConfig.h"

#include <ShlObj_core.h>

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
        std::filesystem::path pathAppData;
        {
            PWSTR path_tmp;
            auto get_folder_path_ret = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path_tmp);

            if (get_folder_path_ret != S_OK) {
                CoTaskMemFree(path_tmp);
                throw_hresult(HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND));
            }
            pathAppData = path_tmp;
            CoTaskMemFree(path_tmp);
        }

        pathAppData /= L".UFCase";

        constexpr wchar_t cfg_filename[] = L"Config.json";

        if (auto cfg_path = pathAppData / cfg_filename;
                std::filesystem::exists(cfg_path)) {
            ReadAppConfigFromFile(g_appConfigPath = cfg_path.c_str());
        } else {
            LoadDefaultAppConfig();
            if (!std::filesystem::exists(pathAppData))
                winrt::check_bool(std::filesystem::create_directories(pathAppData));
            WriteAppConfigToFile(g_appConfigPath = cfg_path.c_str());
        }

        window = make<MainWindow>();
        window.Activate();

        co_return;
    }

}

