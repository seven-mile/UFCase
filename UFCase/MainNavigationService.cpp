#include "pch.h"
#include "MainNavigationService.h"
#if __has_include("MainNavigationService.g.cpp")
#include "MainNavigationService.g.cpp"
#endif

#include "AppConfig.h"

#include "ErrorDialog.g.h"

#include "GlobalUtil.h"
#include "AsyncUtil.h"

#include <winrt/Windows.UI.Xaml.Interop.h>
#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    MainNavigationService::MainNavigationService()
    {
        GlobalRes::MainNavServ(*this);
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
        while (_stackNavItem.size())
            _stackNavItem.pop();

        co_await this->NavigateTo(L"SysInfo");

        this->ContentFrame().BackStack().Clear();

        assert(!this->ContentFrame().CanGoBack());

        co_return;
    }

    IAsyncAction MainNavigationService::NavigateTo(hstring const &page_name,
                                                   IInspectable nav_ctx)
    {
        _isNavigating = true;
        auto $scope{wil::scope_exit([this]() { _isNavigating = false; })};

        _stackNavItem.push(page_name);
        this->MatchNavViewSelectedItem();
        try
        {
            auto cancel_token = co_await get_cancellation_token();
            auto frame = this->ContentFrame();
            if (page_name == L"Settings")
            {
                frame.Navigate(xaml_typename<SettingsPage>());

                co_return;
            }
            else if (page_name == L"SysInfo")
            {
                frame.Navigate(xaml_typename<SysInfoPage>());

                co_return;
            }
            else if (page_name == L"Features")
            {
                auto ivm = GlobalRes::MainWnd().ViewModel();
                auto fpvm = ivm.SelectedImageViewModel().FeaturesPageViewModel();

                frame.Navigate(xaml_typename<FeaturesPage>(), box_value(fpvm));

                co_return;
            }
            else if (page_name == L"Optionals")
            {
                // fall through
            }
            else if (page_name == L"Packages")
            {
                auto ivm = GlobalRes::MainWnd().ViewModel();
                auto ppvm = ivm.SelectedImageViewModel().PackagesPageViewModel();
                if (auto ctx = nav_ctx.try_as<UFCase::PackagesPageNavigationContext>())
                {
                    ppvm.Navigate(ctx);
                }
                else
                {
                    ppvm.Navigate(UFCase::PackagesPageNavigationContext());
                }

                frame.Navigate(xaml_typename<PackagesPage>(), box_value(ppvm));
                co_return;
            }
            else if (page_name == L"Components")
            {
                auto ivm = GlobalRes::MainWnd().ViewModel();
                auto cpvm = ivm.SelectedImageViewModel().ComponentsPageViewModel();
                if (auto ctx = nav_ctx.try_as<UFCase::ComponentsPageNavigationContext>())
                {
                    cpvm.Navigate(ctx);
                }
                else
                {
                    cpvm.Navigate(UFCase::ComponentsPageNavigationContext());
                }
                frame.Navigate(xaml_typename<ComponentsPage>(), box_value(cpvm));
                co_return;
            }
        }
        catch (const hresult_error &e)
        {
            this->HandleHrError(e);
            co_return;
        }

        this->HandleHrError(hresult_not_implemented());
    }

    IAsyncAction MainNavigationService::Refresh()
    {
        if (_stackNavItem.empty() || _stackNavItem.top() == L"Settings")
            co_return;

        co_await this->NavigateTo(_stackNavItem.top());
        _stackNavItem.pop();

        // OutputDebugString(L"Ref\n");
        // DebugFrameBackStack(this->ContentFrame().BackStack());

        co_return;
    }

    void MainNavigationService::GoBack()
    {
        // OutputDebugString(L"Before GoBack");
        // DebugFrameBackStack(this->ContentFrame().BackStack());

        this->ContentFrame().GoBack();
        _stackNavItem.pop();

        this->MatchNavViewSelectedItem();
    }

    void MainNavigationService::HandleHrError(hresult_error err)
    {
        if (_isNavigating)
        {
            // roll back NavView state
            _stackNavItem.pop();
            this->MatchNavViewSelectedItem();
        }

        RunUITaskAsync([err]() -> IAsyncAction {
            UFCase::HrError hr_err{};
            hr_err.Code(err.code());
            hr_err.Message(err.message());

            UFCase::ErrorDialog err_dialog{hr_err};
            err_dialog.XamlRoot(GlobalRes::MainWnd().Content().XamlRoot());

            co_await err_dialog.ShowAsync();
            co_return;
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
        if (cur_page == L"Settings")
        {
            navView.SelectedItem(navView.SettingsItem());
        }

        for (auto rawitem : navView.MenuItems())
        {
            auto item = rawitem.as<NavigationViewItem>();
            if (unbox_value_or<hstring>(item.Tag(), L"") == cur_page)
            {
                navView.SelectedItem(item);
                break;
            }
        }
    }
} // namespace winrt::UFCase::implementation
