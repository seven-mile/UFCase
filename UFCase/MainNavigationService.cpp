#include "pch.h"
#include "MainNavigationService.h"
#if __has_include("MainNavigationService.g.cpp")
#include "MainNavigationService.g.cpp"
#endif

#include "FeatureTreeHelper.h"
#include "PackageListHelper.h"

#include "ImageModel.h"
#include "AppConfig.h"

#include "GlobalUtil.h"

#include <winrt\Windows.UI.Xaml.Interop.h>

namespace winrt::UFCase::implementation
{
    MainNavigationService::MainNavigationService()
    {
        _stackNavItem.push(_unknownPageName);
    }

    hstring MainNavigationService::CurrentPage()
    {
        return _stackNavItem.top();
    }

    IInspectable MainNavigationService::CurrentViewModel()
    {
        return _currentPageVM;
    }

    IAsyncAction MainNavigationService::Initialize()
    {
        while (_stackNavItem.size()) _stackNavItem.pop();

        co_await this->NavigateTo(L"SysInfo");

        this->ContentFrame().BackStack().Clear();

        assert(!this->ContentFrame().CanGoBack());

        co_return;
    }

    IAsyncAction MainNavigationService::NavigateTo(hstring const& page_name)
    {
        _stackNavItem.push(page_name);
        this->MatchNavViewSelectedItem();
    try {
        auto cancel_token = co_await get_cancellation_token();
        auto frame = this->ContentFrame();
        if (page_name == L"Settings") {
            frame.Navigate(xaml_typename<SettingsPage>());

            co_return;
        } else if (page_name == L"SysInfo") {
            frame.Navigate(xaml_typename<SysInfoPage>());

            co_return;
        } else if (page_name == L"Features") {
            auto op = ConstructUpdateTree(*ImageModel::Current());
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
                        frame.Navigate(xaml_typename<FeaturesPage>(), box_value(info.GetResults()));
                    });
                }
                co_return;
            });

            frame.Navigate(xaml_typename<ProgressPage>(), box_value(op));
            co_return;
        } else if (page_name == L"Optionals") {
            // fall through
        } else if (page_name == L"Packages") {
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
    } catch (const hresult_error& e) {
        this->HandleHrError(e);
        co_return;
    }

    this->HandleHrError(hresult_not_implemented());
    }

    constexpr auto IsFrameLastToolPage = [](Frame frame) {
        if (frame.BackStack().Size() <= 0) return 0;
        auto lastPageType = frame.BackStack().GetAt(frame.BackStack().Size() - 1).SourcePageType();
        if (lastPageType.Name == xaml_typename<ProgressPage>().Name) return 1;
        if (lastPageType.Name == xaml_typename<ErrorPage>().Name) return 2;
        return 0;
    };

    auto DebugFrameBackStack = [](IVector<Navigation::PageStackEntry> stack) {
        OutputDebugString(std::format(L"{} size\n", stack.Size()).c_str());
        
        for (auto entry : stack) {
            OutputDebugString(entry.SourcePageType().Name.c_str());
            OutputDebugString(L" ");
        }
        OutputDebugString(L"\n");
    };

    IAsyncAction MainNavigationService::Refresh()
    {
        if (_stackNavItem.empty() || _stackNavItem.top() == L"Settings")
            co_return;

        co_await this->NavigateTo(_stackNavItem.top());
        _stackNavItem.pop();

        //OutputDebugString(L"Ref\n");
        //DebugFrameBackStack(this->ContentFrame().BackStack());
        
        co_return;
    }

    void MainNavigationService::GoBack()
    {
        //OutputDebugString(L"Before GoBack");
        //DebugFrameBackStack(this->ContentFrame().BackStack());
        int res = 0;
        while (this->ContentFrame().CanGoBack() && (res = IsFrameLastToolPage(this->ContentFrame()))) {
            // error page
            if (res == 2) _stackNavItem.pop();
            this->ContentFrame().BackStack().RemoveAtEnd();
        }

        //OutputDebugString(L"After GoBack");
        //DebugFrameBackStack(this->ContentFrame().BackStack());

        this->ContentFrame().GoBack();
        _stackNavItem.pop();

        this->MatchNavViewSelectedItem();
    }

    void MainNavigationService::HandleHrError(hresult_error err)
    {
        auto frame = this->ContentFrame();
        
        frame.DispatcherQueue().TryEnqueue([frame, err]() {
            UFCase::HrError hr_err{};
            hr_err.Code(err.code());
            hr_err.Message(err.message());

            frame.Navigate(xaml_typename<ErrorPage>(), box_value(hr_err));
        });
    }
    Frame MainNavigationService::ContentFrame()
    {
        return GlobalRes::MainWnd().ContentFrame();
    }

    void MainNavigationService::MatchNavViewSelectedItem()
    {
        auto navView = GlobalRes::MainWnd().NavView();
        auto cur_page = _stackNavItem.top();
        if (cur_page == L"Settings") {
            navView.SelectedItem(navView.SettingsItem());
        }

        for (auto rawitem : navView.MenuItems()) {
            auto item = rawitem.as<NavigationViewItem>();
            if (unbox_value_or<hstring>(item.Tag(), L"") == cur_page) {
                navView.SelectedItem(item);
                break;
            }
        }
    }
}
