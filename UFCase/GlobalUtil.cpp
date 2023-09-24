#include "pch.h"
#include "GlobalUtil.h"

namespace winrt::UFCase::GlobalRes
{

    constexpr auto _MainWindowId = L"MainWindow";
    constexpr auto _MainNavServId = L"MainNavigationService";
    constexpr auto _MainProgServId = L"MainProgressService";

    static MainWindow refMainWnd{nullptr};
    static MainNavigationService refMainNav{nullptr};
    static MainProgressService refMainProg{nullptr};
    static WindowService refWndServ{nullptr};
    static Microsoft::UI::Dispatching::DispatcherQueue refUIQueue{nullptr};

    void MainWnd(MainWindow mainWnd)
    {
        refMainWnd = mainWnd;
    }

    MainWindow MainWnd()
    {
        assert(refMainWnd);
        return refMainWnd;
    }

    void MainNavServ(MainNavigationService mainNavServ)
    {
        refMainNav = mainNavServ;
    }

    MainNavigationService MainNavServ()
    {
        assert(refMainNav);
        return refMainNav;
    }

    void MainProgServ(MainProgressService mainProgServ)
    {
        refMainProg = mainProgServ;
    }

    MainProgressService MainProgServ()
    {
        assert(refMainProg);
        return refMainProg;
    }

    void WindowServ(WindowService wndServ)
    {
        refWndServ = wndServ;
    }

    WindowService WindowServ()
    {
        assert(refWndServ);
        return refWndServ;
    }

    Media::FontFamily SymbolThemeFontFamily()
    {
        return Application::Current()
            .Resources()
            .Lookup(box_value(L"SymbolThemeFontFamily"))
            .as<Media::FontFamily>();
    }

    void UIQueue(Microsoft::UI::Dispatching::DispatcherQueue uiQueue)
    {
        refUIQueue = uiQueue;
    }

    Microsoft::UI::Dispatching::DispatcherQueue UIQueue()
    {
        assert(refUIQueue);
        return refUIQueue;
    }

    Microsoft::UI::Dispatching::DispatcherQueue WorkerQueue()
    {
        static auto worker =
            Microsoft::UI::Dispatching::DispatcherQueueController::CreateOnDedicatedThread();
        return worker.DispatcherQueue();
    }

} // namespace winrt::UFCase::GlobalRes
