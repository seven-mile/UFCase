#include "pch.h"
#include "PackagesPage.xaml.h"
#if __has_include("PackagesPage.g.cpp")
#include "PackagesPage.g.cpp"
#endif

#include "GlobalUtil.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    PackagesPage::PackagesPage()
    {
        InitializeComponent();
    }

    IAsyncAction PackagesPage::OnNavigatedTo(const Navigation::NavigationEventArgs &e)
    {
        m_view_model = e.Parameter().as<UFCase::PackagesPageViewModel>();
        auto action = m_view_model.PullData();

        GlobalRes::MainProgServ().InsertTask(action, 100);

        co_await action;

        co_return;
    }

    void PackagesPage::ListViewItem_RightTapped(IInspectable const& sender, Input::RightTappedRoutedEventArgs const& e)
    {
        auto item = sender.as<ListViewItem>();
        auto list = PkgList();
        list.SelectedItem(list.ItemFromContainer(item));
        item.IsSelected(true);

        e.Handled(false);
    }
}
