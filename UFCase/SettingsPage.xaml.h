#pragma once

#include "SettingsPage.g.h"

namespace winrt::UFCase::implementation
{
    struct SettingsPage : SettingsPageT<SettingsPage>
    {
        SettingsPage();

        void InitializeComponent();

        IObservableVector<hstring> SettingsPath();
        void SettingsPath(IObservableVector<hstring> const &);
        void SettingsPathBar_ItemClicked(BreadcrumbBar const &sender,
                                         BreadcrumbBarItemClickedEventArgs const &args);
        void SubPageFrame_Navigated(IInspectable const &sender,
                                    Navigation::NavigationEventArgs const &args);

      private:
        hstring PackBreadcrumUri();
        void UnpackBreadcrumUri(hstring const &path);

        IObservableVector<hstring> m_path = multi_threaded_observable_vector<hstring>();

        std::map<hstring, Windows::UI::Xaml::Interop::TypeName> mapUriToTypeName{
            {L"Root", xaml_typename<RootSettingsPage>()},
            {L"Root/Template", xaml_typename<TemplateSettingsPage>()},
        };

        std::map<hstring, hstring> mapTypeNameToUri;
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct SettingsPage : SettingsPageT<SettingsPage, implementation::SettingsPage>
    {
    };
} // namespace winrt::UFCase::factory_implementation
