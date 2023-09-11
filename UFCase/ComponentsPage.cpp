#include "pch.h"
#include "ComponentsPage.h"
#if __has_include("ComponentsPage.g.cpp")
#include "ComponentsPage.g.cpp"
#endif

#include "GlobalUtil.h"
#include "AsyncUtil.h"

namespace winrt::UFCase::implementation
{
    void ComponentsPage::OnNavigatedTo(const Navigation::NavigationEventArgs &e)
    {
        m_view_model = e.Parameter().as<UFCase::ComponentsPageViewModel>();
        no_await([self = get_strong()]() -> IAsyncAction {
            co_await GlobalRes::MainProgServ().InsertTask(self->m_view_model.PullData(), 100);
            RunUITask([self] {
                if (auto item = self->CompList().SelectedItem())
                {
                    self->CompList().ScrollIntoView(item,
                                                    Controls::ScrollIntoViewAlignment::Leading);
                }
            });
        });
    }

    void ComponentsPage::ListViewItem_RightTapped(IInspectable const &sender,
                                                  Input::RightTappedRoutedEventArgs const &e)
    {
        auto item = sender.as<ListViewItem>();
        auto list = CompList();
        list.SelectedItem(list.ItemFromContainer(item));
        item.IsSelected(true);

        e.Handled(false);
    }
} // namespace winrt::UFCase::implementation
