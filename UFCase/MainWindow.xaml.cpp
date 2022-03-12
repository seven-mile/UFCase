#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "FeatureTreeHelper.h"
#include "PackageListHelper.h"

#include "ImageModel.h"
#include "AppConfig.h"

#include <ShlObj_core.h>


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

    void MainWindow::HandleHrError(hresult_error err)
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

    IAsyncAction MainWindow::NavigateTo(NavigationViewItemBase item, bool isSetting)
    {
        this->m_stackNavItem.push(item);
        hstring page_name = item.Name();
    try {
        auto cancel_token = co_await get_cancellation_token();
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
                    (const decltype(op) &info, const AsyncStatus &status) -> IAsyncAction {
                if (status != AsyncStatus::Completed) {
                    ptr->HandleHrError(hresult_error(
                            status == AsyncStatus::Canceled ?
                            HRESULT_FROM_WIN32(ERROR_CANCELLED)
                            : info.ErrorCode().value));
                } else {
                    frame.DispatcherQueue().TryEnqueue([frame, info](){
                        frame.Navigate(xaml_typename<FeaturesPage>(), box_value(info.GetResults()));
                    });
                }
                co_return;
            });

            frame.Navigate(xaml_typename<ProgressPage>(), box_value(op));
            co_return;
        }
        else if (page_name == L"OptionalsNavViewItem") {
            // fall through
        }
        else if (page_name == L"PackagesNavViewItem") {
            auto op = ConstructPackageList(*ImageModel::Current());
            cancel_token.callback([=]() { op.Cancel(); });

            op.Completed([ptr = this->get_strong(), frame]
            (const decltype(op)& info, const AsyncStatus& status)->IAsyncAction {
                if (status != AsyncStatus::Completed) {
                    ptr->HandleHrError(hresult_error(
                        status == AsyncStatus::Canceled ?
                        HRESULT_FROM_WIN32(ERROR_CANCELLED)
                        : info.ErrorCode().value));
                } else {
                    frame.DispatcherQueue().TryEnqueue([frame, info]() {
                        frame.Navigate(xaml_typename<PackagesPage>(), box_value(info.GetResults()));
                    });
                }
                co_return;
            });

            frame.Navigate(xaml_typename<ProgressPage>(), box_value(op));
            co_return;
        }
    } catch (const hresult_error &e) {
        this->HandleHrError(e);
        co_return;
    }

        this->HandleHrError(hresult_not_implemented());
    }

}
