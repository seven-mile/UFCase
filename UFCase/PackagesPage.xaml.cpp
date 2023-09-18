#include "pch.h"

#include "PackagesPage.xaml.h"
#if __has_include("PackagesPage.g.cpp")
#include "PackagesPage.g.cpp"
#endif

#include "AsyncUtil.h"
#include "GlobalUtil.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{

    PackagesPage::PackagesPage()
    {
    }

    void PackagesPage::OnNavigatedTo(const Navigation::NavigationEventArgs &e)
    {

        m_view_model = e.Parameter().as<UFCase::PackagesPageViewModel>();

        auto proc_sel = [self = get_strong()] {
            if (auto item = self->PkgList().SelectedItem())
            {
                self->PkgList().ScrollIntoView(item, Controls::ScrollIntoViewAlignment::Leading);
            }
        };

        if (m_view_model.State() == PackagesPageViewModelState::Uninitialized)
        {
            no_await([self = get_strong(), proc_sel]() -> IAsyncAction {
                auto proc_sel_ = proc_sel;
                co_await GlobalRes::MainProgServ().InsertTask(self->m_view_model.PullData(), 100);
                RunUITask(proc_sel_);
            });
        }
        else
        {
            proc_sel();
        }

        return;
    }

    void PackagesPage::ListViewItem_RightTapped(IInspectable const &sender,
                                                Input::RightTappedRoutedEventArgs const &e)
    {
        auto item = sender.as<ListViewItem>();
        auto list = PkgList();
        list.SelectedItem(list.ItemFromContainer(item));
        item.IsSelected(true);

        e.Handled(false);
    }

} // namespace winrt::UFCase::implementation
