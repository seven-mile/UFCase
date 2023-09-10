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

        this->SystemBackdrop(Media::MicaBackdrop());
    }

    void MainWindow::UpdateTitleByConfig()
    {
        auto admin_tip = ::IsUserAnAdmin() ? L"" : L"Non-";
        if (AppConfig::GetStackSource() == 0)
        {
            this->AppTitle().Text(std::format(L"UFCase [Online Image] [{}Admin]", admin_tip));
        }
        else
        {
            this->AppTitle().Text(std::format(L"UFCase [Offline Image, {}] [{}Admin]",
                                              AppConfig::GetStackArgBootdrive(), admin_tip));
        }
    }

    void MainWindow::ConfigWindowTitlebar()
    {
        try
        {
            if (auto appw = AppWindow())
            {
                if (auto &&appt = appw.TitleBar())
                {
                    appt.ExtendsContentIntoTitleBar(true);

                    appt.BackgroundColor(Colors::Transparent());
                    appt.ButtonBackgroundColor(Colors::Transparent());
                    appt.ButtonInactiveBackgroundColor(Colors::Transparent());
                    appt.ButtonHoverBackgroundColor(ColorHelper::FromArgb(48, 150, 150, 150));
                    appt.ButtonPressedBackgroundColor(ColorHelper::FromArgb(96, 150, 150, 150));

                    this->AppTitleBar().Height(appt.Height());

                    // clang-format off
                    {
                        // pre-set drag rect
                        const int NavBarHeight = 48, NavBarWidth = IsDebuggerPresent() ? 948 : 48;
                        appt.SetDragRectangles({{
                            NavBarWidth, 0, std::max(0, static_cast<int>(appw.Size().Width) - NavBarWidth), NavBarHeight
                        },});

                        this->SizeChanged([appt, NavBarWidth](auto&, WindowSizeChangedEventArgs const& e) {
                            appt.SetDragRectangles({{
                                NavBarWidth, 0, std::max(0, static_cast<int>(e.Size().Width) - NavBarWidth), NavBarHeight
                            },});
                        });
                    }
                    // clang-format on
                }
                else
                    throw hresult_illegal_method_call{};

                // Config Window Min Size in future
                // if (auto&& pres = appw.Presenter().as<OverlappedPresenter>()) {
                //    pres.IsResizable(false);
                //} else throw hresult_illegal_method_call{};
            }
            else
                throw hresult_illegal_method_call{};
            ;
        }
        catch (hresult_error const &)
        {
            // fallback for win10: just do nothing!
            // this->ExtendsContentIntoTitleBar(true);
            // this->SetTitleBar(this->AppTitleBar());
        }
    }

    void MainWindow::NavView_ItemInvoked(NavigationView const &,
                                         NavigationViewItemInvokedEventArgs const &args)
    {
        if (const auto itemCont = args.InvokedItemContainer().as<NavigationViewItem>())
        {
            if (itemCont.IsSelected())
                return;
            GlobalRes::MainNavServ().NavigateTo(
                args.IsSettingsInvoked() ? L"Settings" : unbox_value<hstring>(itemCont.Tag()));
        }
    }

    void MainWindow::NavView_DisplayModeChanged(
        NavigationView const &, NavigationViewDisplayModeChangedEventArgs const &args)
    {
        if (args.DisplayMode() == NavigationViewDisplayMode::Minimal)
        {
            this->AppTitleBar().Margin({96, 8, 0, 0});
        }
        else
        {
            this->AppTitleBar().Margin({48, 8, 0, 0});
        }
    }

    void MainWindow::NavView_BackRequested(NavigationView const &,
                                           NavigationViewBackRequestedEventArgs const &)
    {
        GlobalRes::MainNavServ().GoBack();
    }

} // namespace winrt::UFCase::implementation
