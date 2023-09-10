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

    Media::FontFamily SymbolThemeFontFamily()
    {
        return Application::Current()
            .Resources()
            .Lookup(box_value(L"SymbolThemeFontFamily"))
            .as<Media::FontFamily>();
    }

    Microsoft::UI::Dispatching::DispatcherQueue WorkerQueue()
    {
        static auto worker =
            Microsoft::UI::Dispatching::DispatcherQueueController::CreateOnDedicatedThread();
        return worker.DispatcherQueue();
    }

} // namespace winrt::UFCase::GlobalRes
