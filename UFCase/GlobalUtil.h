#pragma once

#include <winrt/UFCase.h>

namespace winrt::UFCase {
    namespace GlobalRes {
        void MainWnd(MainWindow mainWnd);
        MainWindow MainWnd();

        void MainNavServ(MainNavigationService mainNavServ);
        MainNavigationService MainNavServ();
    }
}
