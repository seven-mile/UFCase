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

    fire_and_forget PackagesPage::OnNavigatedTo(const Navigation::NavigationEventArgs &e)
    {
        apartment_context ui_thread;

        auto lifetime = get_strong();

        m_view_model = e.Parameter().as<UFCase::PackagesPageViewModel>();

        if (m_view_model.State() == PackagesPageViewModelState::Uninitialized)
        {
            co_await GlobalRes::MainProgServ().InsertTask(m_view_model.PullData(), 100);
            co_await ui_thread;
        }
        else
        {
            co_await resume_background();

            // find the matching package
            auto pvm = [&]() -> UFCase::PackageViewModel {
                for (auto pkg : m_view_model.Packages())
                {
                    if (pkg.DetailIdentity() == m_view_model.NavContext().SelectPkgId())
                    {
                        return pkg;
                    }
                }
                return nullptr;
            }();

            co_await ui_thread;

            m_view_model.SelectedPackage(pvm);
        }

        if (auto item = PkgList().SelectedItem())
        {
            PkgList().ScrollIntoView(item, Controls::ScrollIntoViewAlignment::Leading);
        }

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
