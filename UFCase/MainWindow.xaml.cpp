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
    MainWindow::MainWindow(ImageSelectorViewModel vm) : m_view_model(vm)
    {
        GlobalRes::MainWnd(*this);

        // center the window
        {
            auto sz = AppWindow().Size();
            auto x = (GetSystemMetrics(SM_CXSCREEN) - sz.Width) / 2;
            auto y = (GetSystemMetrics(SM_CYSCREEN) - sz.Height) / 2;
            AppWindow().Move({x, y});
        }
    }

    void MainWindow::InitializeComponent()
    {
        MainWindowT::InitializeComponent();

        // other ui config
        this->ConfigWindowTitlebar();
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
                    appt.PreferredHeightOption(Windowing::TitleBarHeightOption::Tall);

                    appt.BackgroundColor(Colors::Transparent());
                    appt.ButtonBackgroundColor(Colors::Transparent());
                    appt.ButtonInactiveBackgroundColor(Colors::Transparent());
                    appt.ButtonHoverBackgroundColor(ColorHelper::FromArgb(48, 150, 150, 150));
                    appt.ButtonPressedBackgroundColor(ColorHelper::FromArgb(96, 150, 150, 150));
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

    ImageSelectorViewModel MainWindow::ViewModel()
    {
        return m_view_model;
    }

} // namespace winrt::UFCase::implementation
