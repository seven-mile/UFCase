#pragma once

#include "MainNavigationService.g.h"

#include <stack>

namespace winrt::UFCase::implementation
{
    struct MainNavigationService : MainNavigationServiceT<MainNavigationService>
    {
        MainNavigationService();

        hstring CurrentPage();
        IInspectable CurrentViewModel();

        IAsyncAction Initialize();
        IAsyncAction NavigateTo(hstring const &pageName);
        IAsyncAction Refresh();
        void GoBack();
        void HandleHrError(hresult_error err);
        Frame ContentFrame();
        void MatchNavViewSelectedItem();

    private:
        static constexpr auto _unknownPageName = L"(unknown)";
        IInspectable _currentPageVM {nullptr};
        std::stack<hstring> _stackNavItem{};
        bool _isNavigating = false;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct MainNavigationService : MainNavigationServiceT<MainNavigationService, implementation::MainNavigationService>
    {
    };
}
