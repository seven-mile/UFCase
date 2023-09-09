#pragma once

#include "PackagesPage.g.h"

namespace winrt::UFCase::implementation
{
    struct PackagesPage : PackagesPageT<PackagesPage>
    {
        PackagesPage();

        void OnNavigatedTo(const Navigation::NavigationEventArgs& e);

        UFCase::PackagesPageViewModel m_view_model{nullptr};
        UFCase::PackagesPageViewModel ViewModel() { return m_view_model; }

        void ListViewItem_RightTapped(IInspectable const& sender, Input::RightTappedRoutedEventArgs const& e);
        void
        Button_Click(winrt::Windows::Foundation::IInspectable const &sender,
                     winrt::Microsoft::UI::Xaml::RoutedEventArgs const &e);
        void PkgList_SelectionChanged(
            winrt::Windows::Foundation::IInspectable const &sender,
            winrt::Microsoft::UI::Xaml::Controls::
                SelectionChangedEventArgs const &e);
    };
    }

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPage : PackagesPageT<PackagesPage, implementation::PackagesPage>
    {
    };
}
