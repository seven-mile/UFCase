#pragma once

#include <winrt/UFCase.h>

namespace winrt::UFCase
{
    namespace GlobalRes
    {
        void MainWnd(MainWindow mainWnd);
        MainWindow MainWnd();

        void MainNavServ(MainNavigationService mainNavServ);
        MainNavigationService MainNavServ();

        void MainProgServ(MainProgressService mainProgServ);
        MainProgressService MainProgServ();

        Media::FontFamily SymbolThemeFontFamily();

        void UIQueue(Microsoft::UI::Dispatching::DispatcherQueue uiQueue);
        Microsoft::UI::Dispatching::DispatcherQueue UIQueue();

        Microsoft::UI::Dispatching::DispatcherQueue WorkerQueue();

    } // namespace GlobalRes

} // namespace winrt::UFCase
