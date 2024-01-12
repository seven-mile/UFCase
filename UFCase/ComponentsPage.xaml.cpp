#include "pch.h"
#include "ComponentsPage.xaml.h"
#if __has_include("ComponentsPage.g.cpp")
#include "ComponentsPage.g.cpp"
#endif

#include "GlobalUtil.h"
#include "AsyncUtil.h"

namespace winrt::UFCase::implementation
{
    void ComponentsPage::OnNavigatedTo(const Navigation::NavigationEventArgs &e)
    {
        auto view_model = e.Parameter().as<UFCase::ComponentsPageViewModel>();
        auto lifetime = get_strong();

        m_navigated_revoker =
            view_model.Navigated(auto_revoke, [this, lifetime](auto &&, auto &&) -> void {
                // enqueue to the end for the listview to update
                RunUITask([=] {
                    if (auto item = lifetime->CompList().SelectedItem())
                    {
                        lifetime->CompList().ScrollIntoView(
                            item, Controls::ScrollIntoViewAlignment::Leading);
                    }
                });
            });

        m_view_model = view_model;
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

    void ComponentsPage::GotoSelectionButton_Click(IInspectable const &, RoutedEventArgs const &)
    {
        if (auto item = CompList().SelectedItem())
        {
            CompList().ScrollIntoView(item);
        }
    }

    void ComponentsPage::GotoTopButton_Click(IInspectable const &, RoutedEventArgs const &)
    {
        if (auto item = ViewModel().Components().GetAt(0))
        {
            CompList().ScrollIntoView(item);
        }
    }

    void ComponentsPage::CompList_SelectionChanged(IInspectable const &,
                                                   Controls::SelectionChangedEventArgs const &)
    {
        if (auto item = CompList().SelectedItem())
        {
            ViewModel().SelectedComponent(item.as<UFCase::ComponentViewModel>());
        }
    }
} // namespace winrt::UFCase::implementation
