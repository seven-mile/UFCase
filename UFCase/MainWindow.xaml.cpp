#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

//#include "SysInfoPage.g.h"
//#include "SettingsPage.g.h"
//
//#include "FeaturesPage.g.h"
//#include "FeatureViewModel.g.h"

#include "FeatureTreeHelper.h"


#include "ErrorPage.g.h"

#include "ImageModel.h"
#include "AppConfig.h"


namespace winrt::UFCase::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        // other ui config
        this->UpdateTitleByConfig();
        this->ConfigWindowTitlebar();

        // navigate to the home page
        this->NavView().SelectedItem(this->NavView().MenuItems().GetAt(0));
        this->NavigateTo(this->NavView().SelectedItem().as<NavigationViewItemBase>());
    }

    winrt::AppWindow MainWindow::GetAppWindowForCurrentWindow()
    {
        winrt::AppWindow appWindow = nullptr;

        {
            // Get the HWND for the XAML Window
            HWND hWnd;
            Window window = this->try_as<Window>();
            winrt::check_hresult(window.as<IWindowNative>()->get_WindowHandle(&hWnd));

            // Get the WindowId for the HWND
            
            if (auto windowId = GetWindowIdFromWindow(hWnd); windowId.Value)
            {
                // Get the AppWindow for the WindowId
                appWindow = winrt::AppWindow::GetFromWindowId(windowId);
            }
        }
        return appWindow;
    }

    void MainWindow::HandleHrError(winrt::hresult_error err)
    {
        auto frame = this->ContentFrame();
        frame.DispatcherQueue().TryEnqueue([frame, err](){
            UFCase::HrError hr_err{};
            hr_err.Code(err.code());
            hr_err.Message(err.message());

            frame.Navigate(xaml_typename<ErrorPage>(), box_value(hr_err));
        });
    }

    void MainWindow::UpdateTitleByConfig()
    {
        if (AppConfig::GetStackSource() == 0) {
            this->AppTitle().Text(L"UFCase [Online Image] [Non-Admin]");
        } else {
            this->AppTitle().Text(std::format(L"UFCase [Offline Image, {}] [Non-Admin]", AppConfig::GetStackArgBootdrive()).c_str());
        }
    }

    void MainWindow::ConfigWindowTitlebar()
    {
        try {
            if (auto appw = GetAppWindowForCurrentWindow()) {
                if (auto&& appt = appw.TitleBar()) {
                    appt.ExtendsContentIntoTitleBar(true);

                    appt.BackgroundColor(winrt::Colors::Transparent());
                    appt.ButtonBackgroundColor(winrt::Colors::Transparent());
                    appt.ButtonInactiveBackgroundColor(winrt::Colors::Transparent());
                    appt.ButtonHoverBackgroundColor(winrt::ColorHelper::FromArgb(48, 150, 150, 150));
                    appt.ButtonPressedBackgroundColor(winrt::ColorHelper::FromArgb(96, 150, 150, 150));

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
                } else throw winrt::hresult_illegal_method_call{};
                
                // Config Window Min Size in future
                //if (auto&& pres = appw.Presenter().as<OverlappedPresenter>()) {
                //    pres.IsResizable(false);
                //} else throw winrt::hresult_illegal_method_call{};
            } else throw winrt::hresult_illegal_method_call{};;
        } catch (winrt::hresult_error const&) {
            // fallback for win10: just do nothing!
            //this->ExtendsContentIntoTitleBar(true);
            //this->SetTitleBar(this->AppTitleBar());
        }

    }

    void MainWindow::NavView_ItemInvoked(NavigationView const&, NavigationViewItemInvokedEventArgs const& args)
    {
        if (const auto itemCont = args.InvokedItemContainer().as<NavigationViewItem>()) {
            if (itemCont.IsSelected()) return;
            this->NavigateTo(itemCont, args.IsSettingsInvoked());
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

    void MainWindow::NavView_BackRequested(NavigationView const &sender, NavigationViewBackRequestedEventArgs const&)
    {
        auto IsFrameLastToolPage = [](Frame frame) {
            if (frame.BackStack().Size() <= 0) return false;
            auto lastPageType = frame.BackStack().GetAt(frame.BackStack().Size() - 1).SourcePageType();
            return lastPageType.Name == xaml_typename<ProgressPage>().Name
                //|| lastPageType.Name == xaml_typename<>(ErrorPage).Name
                ;
        };

        while (this->ContentFrame().CanGoBack() && IsFrameLastToolPage(this->ContentFrame()))
            this->ContentFrame().BackStack().RemoveAtEnd();
        this->ContentFrame().GoBack();
        this->m_stackNavItem.pop();
        sender.SelectedItem(this->m_stackNavItem.top());
    }

    winrt::IAsyncAction MainWindow::NavigateTo(NavigationViewItemBase item, bool isSetting)
    {
        this->m_stackNavItem.push(item);
        winrt::hstring page_name = item.Name();
    try {
        winrt::apartment_context ui_thread;
        auto cancel_token = co_await winrt::get_cancellation_token();
        auto frame = this->ContentFrame();
        if (isSetting) {
            frame.Navigate(xaml_typename<SettingsPage>());

            co_return;
        }
        else if (page_name == L"SysInfoNavViewItem") {
            frame.Navigate(xaml_typename<SysInfoPage>());

            co_return;
        }
        else if (page_name == L"FeaturesNavViewItem") {
            auto op = ConstructUpdateTree(*ImageModel::Current());

            cancel_token.callback([=](){ op.Cancel(); });

            op.Completed([ptr = this->get_strong(), frame]
                    (const decltype(op) &info, const winrt::AsyncStatus &status) -> winrt::IAsyncAction {
                if (status != winrt::AsyncStatus::Completed) {
                    ptr->HandleHrError(winrt::hresult_error(
                            status == winrt::AsyncStatus::Canceled ?
                            HRESULT_FROM_WIN32(ERROR_CANCELLED)
                            : info.ErrorCode().value));
                } else {
                    frame.DispatcherQueue().TryEnqueue([frame, info](){
                        frame.Navigate(xaml_typename<FeaturesPage>(), box_value(info.GetResults()));
                    });
                }
                co_return;
            });

            //co_await ui_thread;

            frame.Navigate(xaml_typename<ProgressPage>(), box_value(op));

            co_return;
        }
        else if (page_name == L"OptionalsNavViewItem") {
            // fall through
        }
        else if (page_name == L"PackagesNavViewItem") {
            auto session = ImageModel::Current()->OpenSession();
            auto res = single_threaded_observable_vector<UFCase::PackageViewModel>();

            for (auto&& pkg : session->Packages())
                res.Append(UFCase::PackageViewModel(pkg->GetHandle()));

            frame.Navigate(xaml_typename<PackagesPage>(), res);

            co_return;
        }
    } catch (const winrt::hresult_error &e) {
        this->HandleHrError(e);
        co_return;
    }

        this->HandleHrError(winrt::hresult_not_implemented());
    }

}
