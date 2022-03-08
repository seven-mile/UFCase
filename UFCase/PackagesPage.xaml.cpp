#include "pch.h"
#include "PackagesPage.xaml.h"
#if __has_include("PackagesPage.g.cpp")
#include "PackagesPage.g.cpp"
#endif

#include <winrt/Microsoft.UI.Xaml.Input.h>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    PackagesPage::PackagesPage()
    {
        InitializeComponent();
    }

    winrt::event_token PackagesPage::PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value)
    {
        return m_propertyChanged.add(value);
    }

    void PackagesPage::PropertyChanged(winrt::event_token const& token)
    {
        m_propertyChanged.remove(token);
    }

    void PackagesPage::OnNavigatedTo(const Navigation::NavigationEventArgs &e)
    {
        this->m_pkgProv = e.Parameter().as<IObservableVector<UFCase::PackageViewModel>>();
        this->m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"PackageDataSource"});

        if (this->m_pkgProv.Size())
            this->PkgList().SelectedIndex(0);
    }

    IObservableVector<UFCase::PackageViewModel> PackagesPage::PackageDataSource()
    {
        return this->m_pkgProv;
    }

    void PackagesPage::ListViewItem_RightTapped(IInspectable const& sender, Input::RightTappedRoutedEventArgs const& e)
    {
        auto item = sender.as<ListViewItem>();
        auto list = this->PkgList();
        list.SelectedItem(list.ItemFromContainer(item));
        item.IsSelected(true);

        e.Handled(false);
    }
}
