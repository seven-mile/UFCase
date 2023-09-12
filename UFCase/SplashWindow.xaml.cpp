#include "pch.h"

#include "SplashWindow.xaml.h"
#if __has_include("SplashWindow.g.cpp")
#include "SplashWindow.g.cpp"
#endif
#if __has_include("AppInitializeContext.g.cpp")
#include "AppInitializeContext.g.cpp"
#endif

#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Interop.h>

#include "AsyncUtil.h"

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    SplashWindow::SplashWindow()
    {
        m_status = L"Working in progress";

        AppWindow().SetPresenter(Microsoft::UI::Windowing::AppWindowPresenterKind::CompactOverlay);

        // center the window
        {
            auto sz = AppWindow().Size();
            auto x = (GetSystemMetrics(SM_CXSCREEN) - sz.Width) / 2;
            auto y = (GetSystemMetrics(SM_CYSCREEN) - sz.Height) / 2;
            AppWindow().Move({x, y});
        }

        AppWindow().TitleBar().ExtendsContentIntoTitleBar(true);
        AppWindow().TitleBar().ButtonBackgroundColor(Windows::UI::Colors::Transparent());
        AppWindow().TitleBar().ButtonInactiveBackgroundColor(Windows::UI::Colors::Transparent());

        auto update_dragable_rect = [this] {
            auto sz = AppWindow().Size();
            AppWindow().TitleBar().SetDragRectangles({{0, 0, sz.Width, sz.Height}});
        };
        update_dragable_rect();
        this->SizeChanged([=](auto &&, auto &&) { update_dragable_rect(); });
    }

    void SplashWindow::InitializeComponent()
    {
        SplashWindowT::InitializeComponent();
    }

    IAsyncOperation<UFCase::AppInitializeContext> SplashWindow::InitializeAsync()
    {
        co_await resume_background();

        auto vm = ImageSelectorViewModel();

        auto op = vm.PullData();

        op.Progress([self = get_strong()](auto &&, hstring status) {
            RunUITask([self, status] {
                self->m_status = status;
                self->NotifyPropChange(L"Status");
            });
        });

        co_await op;

        UFCase::AppInitializeContext result{};
        result.ImagesViewModel(vm);

        co_return result;
    }

} // namespace winrt::UFCase::implementation
