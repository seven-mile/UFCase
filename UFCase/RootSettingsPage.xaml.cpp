#include "pch.h"
#include "RootSettingsPage.xaml.h"
#if __has_include("RootSettingsPage.g.cpp")
#include "RootSettingsPage.g.cpp"
#endif

#include "MainWindow.g.h"
#include "SettingsPage.g.h"
#include "TemplateSettingsPage.g.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    RootSettingsPage::RootSettingsPage()
    {
    }

    void RootSettingsPage::Group4Row1_Click(IInspectable const &, RoutedEventArgs const &)
    {
        this->Frame().Navigate(xaml_typename<TemplateSettingsPage>());
    }

} // namespace winrt::UFCase::implementation
