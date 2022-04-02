#include "pch.h"
#include "GlobalUtil.h"

namespace winrt::UFCase::GlobalRes {

    constexpr auto _MainWindowId = L"MainWindow";
    constexpr auto _MainNavServId = L"MainNavigationService";

    void MainWnd(MainWindow mainWnd)
    {
        Application::Current().Resources().Insert(box_value(_MainWindowId), mainWnd);
    }

    MainWindow MainWnd() {
        auto&& res = Application::Current().Resources().TryLookup(box_value(_MainWindowId));
        assert(res);
        auto&& mainWnd = res.try_as<MainWindow>();
        assert(mainWnd);
        return mainWnd;
    }

    void MainNavServ(MainNavigationService mainNavServ) {
        Application::Current().Resources().Insert(box_value(_MainNavServId), mainNavServ);
    }

    MainNavigationService MainNavServ() {
        auto&& res = Application::Current().Resources().TryLookup(box_value(_MainNavServId));
        assert(res);
        auto&& mainNavServ = res.try_as<MainNavigationService>();
        assert(mainNavServ);
        return mainNavServ;
    }
}
