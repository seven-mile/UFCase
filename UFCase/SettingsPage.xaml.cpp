#include "pch.h"
#include "SettingsPage.xaml.h"
#if __has_include("SettingsPage.g.cpp")
#include "SettingsPage.g.cpp"
#endif

#include "TemplateSettingsPage.g.h"

#include <winrt/Windows.UI.Xaml.Interop.h>

#include <map>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{

    SettingsPage::SettingsPage()
    {
        InitializeComponent();

        // set-up inv-map
        for (auto &&[key, val] : mapUriToTypeName) {
            mapTypeNameToUri[val.Name] = key;
        }

        this->SubPageFrame().Navigate(xaml_typename<TemplateSettingsPage>());
        //this->SettingsPath().Append(L"Root");
        //this->SettingsPath().Append(L"Templates");
    }

    IObservableVector<hstring> SettingsPage::SettingsPath()
    {
        return m_path;
    }

    void SettingsPage::SettingsPath(IObservableVector<hstring> const &value)
    {
        m_path = value;
    }

    void SettingsPage::SettingsPathBar_ItemClicked(BreadcrumbBar const& sender, BreadcrumbBarItemClickedEventArgs const& args)
    {
        auto vec = sender.ItemsSource().as<IObservableVector<hstring>>();
        while (static_cast<int32_t>(vec.Size())-1 > args.Index())
            vec.RemoveAtEnd();
        this->SubPageFrame().Navigate(mapUriToTypeName[this->PackBreadcrumUri()]);
    }

    void SettingsPage::SubPageFrame_Navigated(IInspectable const&, Navigation::NavigationEventArgs const& args)
    {
        this->UnpackBreadcrumUri(mapTypeNameToUri[args.SourcePageType().Name]);
    }

    hstring SettingsPage::PackBreadcrumUri()
    {
        std::wstring res;
        for (auto &&part : this->SettingsPath()) {
            res += part + L"/";
        }
        // remove terminated-slash
        res.pop_back();
        return res.c_str();
    }

    void SettingsPage::UnpackBreadcrumUri(winrt::hstring const &hpath) {
        this->SettingsPath().Clear();
        std::wstring path = hpath.c_str();
        for (size_t off = 0, nxt_off = 0; nxt_off != std::wstring::npos && off < path.size(); off = nxt_off + 1) {
            this->SettingsPath().Append(path.substr(off, nxt_off = path.find_first_of(L'/', off)));
        }
    }

}
