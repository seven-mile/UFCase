#include "pch.h"

#include "PackagesPage.xaml.h"
#if __has_include("PackagesPage.g.cpp")
#include "PackagesPage.g.cpp"
#endif

#include "AsyncUtil.h"
#include "GlobalUtil.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/UFCase.Isolation.h>

namespace winrt::UFCase::implementation
{

    fire_and_forget PackagesPage::OnNavigatedTo(const Navigation::NavigationEventArgs &e)
    {
        apartment_context ui_thread;

        auto lifetime = get_strong();

        auto view_model = e.Parameter().as<UFCase::PackagesPageViewModel>();

        // subscribe for scrolling
        m_navigated_revoker =
            view_model.Navigated(auto_revoke, [this, lifetime](auto &&, auto &&) -> void {
                // enqueue to the end for the listview to update
                RunUITask([=] {
                    if (auto item = lifetime->PkgList().SelectedItem())
                    {
                        lifetime->PkgList().ScrollIntoView(
                            item, Controls::ScrollIntoViewAlignment::Leading);
                    }
                });
            });

        m_view_model = view_model;

        co_return;
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

    void PackagesPage::GotoSelectionButton_Click(IInspectable const &, RoutedEventArgs const &)
    {
        if (auto item = PkgList().SelectedItem())
        {
            PkgList().ScrollIntoView(item);
        }
    }

    void PackagesPage::GotoTopButton_Click(IInspectable const &, RoutedEventArgs const &)
    {
        if (auto item = ViewModel().Packages().GetAt(0))
        {
            PkgList().ScrollIntoView(item);
        }
    }

    void PackagesPage::PkgList_SelectionChanged(
        IInspectable const &, Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const &)
    {
        if (auto item = PkgList().SelectedItem())
        {
            ViewModel().SelectedPackage(item.as<UFCase::PackageViewModel>());
        }
    }

    void PackagesPage::PkgList_Loaded(IInspectable const &, RoutedEventArgs const &)
    {
        if (auto item = PkgList().SelectedItem())
        {
            PkgList().ScrollIntoView(item, Controls::ScrollIntoViewAlignment::Leading);
        }
    }

} // namespace winrt::UFCase::implementation
