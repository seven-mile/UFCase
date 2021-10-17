#include "pch.h"
#include "TemplateSettingsPage.xaml.h"
#if __has_include("TemplateSettingsPage.g.cpp")
#include "TemplateSettingsPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    TemplateSettingsPage::TemplateSettingsPage()
    {
        InitializeComponent();
    }
}
