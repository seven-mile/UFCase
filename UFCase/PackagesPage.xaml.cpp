#include "pch.h"
#include "PackagesPage.xaml.h"
#if __has_include("PackagesPage.g.cpp")
#include "PackagesPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    PackagesPage::PackagesPage()
    {
        InitializeComponent();
    }
    void PackagesPage::OnNavigatedTo(const Navigation::NavigationEventArgs& e)
    {
        this->m_pkgProv = UFCase::PackagesProvider();// e.Parameter().as<UFCase::PackagesProvider>();
    }
    UFCase::PackagesProvider PackagesPage::PackageDataSource()
    {
        return this->m_pkgProv;
    }
}
