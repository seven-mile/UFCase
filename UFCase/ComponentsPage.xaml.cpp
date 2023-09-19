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
        m_view_model = e.Parameter().as<UFCase::ComponentsPageViewModel>();

        if (m_view_model.State() == ComponentsPageViewModelState::Uninitialized)
        {
            no_await(GlobalRes::MainProgServ().InsertTask(m_view_model.PullData(), 100));
        }
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
