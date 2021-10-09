#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif


#include "SysInfoPage.g.h"

#include "FeaturesPage.g.h"
#include "FeatureTreeElement.g.h"
#include "FeatureTreeModel.h"

#include "ErrorPage.g.h"

#include <format>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        if (m_appw = GetAppWindowForCurrentWindow()) {
            m_appw.TitleBar().ExtendsContentIntoTitleBar(true);
            this->AppTitleBar().Height(m_appw.TitleBar().Height());
            m_appw.TitleBar().BackgroundColor(winrt::Colors::White());
            
        } else {
            this->ExtendsContentIntoTitleBar(true);
            this->SetTitleBar(this->AppTitleBar());
        }
        this->SizeChanged([&](auto &, WindowSizeChangedEventArgs const &e){
            m_appw.TitleBar().SetDragRectangles({
                winrt::Windows::Graphics::RectInt32{40, 0, std::max(0, static_cast<int>(e.Size().Width)-40), 40}
            });
        });
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

    void MainWindow::NavigationView_SelectionChanged(NavigationView const&, NavigationViewSelectionChangedEventArgs const& args)
    {
        if (const auto item = args.SelectedItem().as<NavigationViewItem>()) {
            this->NavigateTo(unbox_value<hstring>(item.Content()));
        }
    }

    winrt::IAsyncAction MainWindow::NavigateTo(winrt::hstring page_name)
    {
    try {
        winrt::apartment_context ui_thread;
        auto cancel_token = co_await winrt::get_cancellation_token();
        auto frame = this->ContentFrame();
        if (page_name == L"SysInfo") {
            frame.Navigate(xaml_typename<SysInfoPage>());

            co_return;
        }
        else if (page_name == L"Features") {
            co_await winrt::resume_background();

            // dynamic allocation to extend lifetime
            auto pModel = std::make_unique<FeatureTreeModel>();
            auto op = pModel->ConstructUpdateTree();

            cancel_token.callback([=](){ op.Cancel(); });

            // move model pointer and reserve thread context to extend lifetime
            op.Completed([pModel = std::move(pModel), ptr = this->get_strong(), frame]
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

            co_await ui_thread;

            frame.Navigate(xaml_typename<ProgressPage>(), box_value(op));

            co_return;
        }
        else if (page_name == L"Optionals") {
            
        }
        else if (page_name == L"Packages") {

        }
        else if (page_name == L"Settings") {
        
        }
    } catch (const winrt::hresult_error &e) {
        this->HandleHrError(e);
        co_return;
    }

        this->HandleHrError(winrt::hresult_not_implemented());
    }

}

