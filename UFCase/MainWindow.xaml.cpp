#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "GlobalUtil.h"

#include <ShlObj_core.h>
#include <dispatcherqueue.h>

#pragma comment(lib, "Shell32.lib")

namespace winrt::UFCase::implementation
{
    MainWindow::MainWindow()
    {
        GlobalRes::MainWnd(*this);

        InitializeComponent();

        // other ui config
        this->UpdateTitleByConfig();
        this->ConfigWindowTitlebar();

        SetBackdrop();

        m_closedRevoker = this->Closed(auto_revoke, [&](auto&&, auto&&) {
            if (nullptr != m_micaController) {
                m_micaController.Close();
                m_micaController = nullptr;
            }

            if (nullptr != m_dispatcherQueueController) {
                m_dispatcherQueueController.ShutdownQueueAsync();
                m_dispatcherQueueController = nullptr;
            }
        });
    }

    AppWindow MainWindow::GetAppWindowForCurrentWindow()
    {
        AppWindow appWindow = nullptr;

        {
            // Get the HWND for the XAML Window
            HWND hWnd;
            Window window = this->try_as<Window>();
            check_hresult(window.as<IWindowNative>()->get_WindowHandle(&hWnd));

            // Get the WindowId for the HWND
            
            if (auto windowId = GetWindowIdFromWindow(hWnd); windowId.Value)
            {
                // Get the AppWindow for the WindowId
                appWindow = AppWindow::GetFromWindowId(windowId);
            }
        }
        return appWindow;
    }

    void MainWindow::UpdateTitleByConfig()
    {
        auto admin_tip = ::IsUserAnAdmin() ? L"" : L"Non-";
        if (AppConfig::GetStackSource() == 0) {
            this->AppTitle().Text(std::format(L"UFCase [Online Image] [{}Admin]", admin_tip));
        } else {
            this->AppTitle().Text(std::format(L"UFCase [Offline Image, {}] [{}Admin]", AppConfig::GetStackArgBootdrive(), admin_tip));
        }
    }

    void MainWindow::ConfigWindowTitlebar()
    {
        try {
            if (auto appw = GetAppWindowForCurrentWindow()) {
                if (auto&& appt = appw.TitleBar()) {
                    appt.ExtendsContentIntoTitleBar(true);

                    appt.BackgroundColor(Colors::Transparent());
                    appt.ButtonBackgroundColor(Colors::Transparent());
                    appt.ButtonInactiveBackgroundColor(Colors::Transparent());
                    appt.ButtonHoverBackgroundColor(ColorHelper::FromArgb(48, 150, 150, 150));
                    appt.ButtonPressedBackgroundColor(ColorHelper::FromArgb(96, 150, 150, 150));

                    this->AppTitleBar().Height(appt.Height());

                    {
                        // pre-set drag rect
                        const int NavBarHeight = 48, NavBarWidth = IsDebuggerPresent() ? 948 : 48;
                        appt.SetDragRectangles({
                            { NavBarWidth, 0, std::max(0, static_cast<int>(appw.Size().Width) - NavBarWidth), NavBarHeight },
                            });

                        this->SizeChanged([appt, NavBarWidth](auto&, WindowSizeChangedEventArgs const& e) {
                            appt.SetDragRectangles({
                                { NavBarWidth, 0, std::max(0, static_cast<int>(e.Size().Width) - NavBarWidth), NavBarHeight},
                                });
                            });
                    }
                } else throw hresult_illegal_method_call{};
                
                // Config Window Min Size in future
                //if (auto&& pres = appw.Presenter().as<OverlappedPresenter>()) {
                //    pres.IsResizable(false);
                //} else throw hresult_illegal_method_call{};
            } else throw hresult_illegal_method_call{};;
        } catch (hresult_error const&) {
            // fallback for win10: just do nothing!
            //this->ExtendsContentIntoTitleBar(true);
            //this->SetTitleBar(this->AppTitleBar());
        }

    }

    void MainWindow::NavView_ItemInvoked(NavigationView const&, NavigationViewItemInvokedEventArgs const& args)
    {
        if (const auto itemCont = args.InvokedItemContainer().as<NavigationViewItem>()) {
            if (itemCont.IsSelected()) return;
            GlobalRes::MainNavServ().NavigateTo(
                args.IsSettingsInvoked() ? L"Settings" : unbox_value<hstring>(itemCont.Tag()));
        }
    }

    void MainWindow::NavView_DisplayModeChanged(NavigationView const&, NavigationViewDisplayModeChangedEventArgs const& args)
    {
        if (args.DisplayMode() == NavigationViewDisplayMode::Minimal) {
            this->AppTitleBar().Margin({96,8,0,0});
        } else {
            this->AppTitleBar().Margin({48,8,0,0});
        }
    }

    void MainWindow::NavView_BackRequested(NavigationView const &, NavigationViewBackRequestedEventArgs const&)
    {
        GlobalRes::MainNavServ().GoBack();
    }

    void MainWindow::SetBackdrop()
    {
        if (MicaController::IsSupported())
        {
            // We ensure that there is a Windows.System.DispatcherQueue on the current thread.
            // Always check if one already exists before attempting to create a new one.
            if (auto currentDQ = DispatcherQueue::GetForCurrentThread();
                nullptr == currentDQ &&
                nullptr == m_dispatcherQueueController)
            {
                m_dispatcherQueueController = CreateSystemDispatcherQueueController();
            }

            // Setup the SystemBackdropConfiguration object.
            SetupSystemBackdropConfiguration();

            // Setup Mica on the current Window.
            m_micaController = MicaController();
            m_micaController.SetSystemBackdropConfiguration(m_configuration);
            auto composition_abi = this->try_as<ICompositionSupportsSystemBackdrop>();
            if (!m_micaController.AddSystemBackdropTarget(composition_abi)) {
                OutputDebugString(L"Failed to set window backdrop!\n");
            }
        } else
        {
            // No Mica support.
        }
    }

    DispatcherQueueController MainWindow::CreateSystemDispatcherQueueController()
    {
        DispatcherQueueOptions options
        {
            sizeof(DispatcherQueueOptions),
            DQTYPE_THREAD_CURRENT,
            DQTAT_COM_NONE
        };

        ::ABI::Windows::System::IDispatcherQueueController* ptr{ nullptr };
        check_hresult(CreateDispatcherQueueController(options, &ptr));
        return { ptr, take_ownership_from_abi };
    }

    void MainWindow::SetupSystemBackdropConfiguration()
    {
        m_configuration = SystemBackdropConfiguration();

        // Activation state.
        m_activatedRevoker = this->Activated(auto_revoke,
            [&](auto&&, WindowActivatedEventArgs const& args) {
            m_configuration.IsInputActive(
                WindowActivationState::Deactivated != args.WindowActivationState());
        });

        // Initial state.
        m_configuration.IsInputActive(true);

        // Application theme.
        m_rootElement = this->Content().try_as<FrameworkElement>();
        if (nullptr != m_rootElement)
        {
            m_themeChangedRevoker = m_rootElement.ActualThemeChanged(auto_revoke,
                [&](auto&&, auto&&) {
                m_configuration.Theme(
                    ConvertToSystemBackdropTheme(m_rootElement.ActualTheme()));
            });

            // Initial state.
            m_configuration.Theme(
                ConvertToSystemBackdropTheme(m_rootElement.ActualTheme()));
        }
    }

    SystemBackdropTheme MainWindow::ConvertToSystemBackdropTheme(
        ElementTheme const& theme)
    {
        switch (theme)
        {
        case ElementTheme::Dark:
            return SystemBackdropTheme::Dark;
        case ElementTheme::Light:
            return SystemBackdropTheme::Light;
        default:
            return SystemBackdropTheme::Default;
        }
    }
}
