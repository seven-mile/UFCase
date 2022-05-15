#pragma once

#include <winrt/UFCase.h>

namespace winrt::UFCase {
    namespace GlobalRes {
        void MainWnd(MainWindow mainWnd);
        MainWindow MainWnd();

        void MainNavServ(MainNavigationService mainNavServ);
        MainNavigationService MainNavServ();

        void MainProgServ(MainProgressService mainProgServ);
        MainProgressService MainProgServ();

        Media::FontFamily SymbolThemeFontFamily();

        Microsoft::UI::Dispatching::DispatcherQueue WorkerQueue();
    }
}
