#pragma once

#include "PackagesPage.g.h"

namespace winrt::UFCase::implementation
{
    struct PackagesPage : PackagesPageT<PackagesPage>
    {
        PackagesPage();

        fire_and_forget OnNavigatedTo(const Navigation::NavigationEventArgs &e);

        UFCase::PackagesPageViewModel m_view_model{nullptr};
        UFCase::PackagesPageViewModel ViewModel()
        {
            return m_view_model;
        }

        void ListViewItem_RightTapped(IInspectable const &sender,
                                      Input::RightTappedRoutedEventArgs const &e);
        void GotoSelectionButton_Click(IInspectable const &sender, RoutedEventArgs const &e);
        void GotoTopButton_Click(IInspectable const &sender, RoutedEventArgs const &e);
        void PkgList_SelectionChanged(
            IInspectable const &sender,
            Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const &e);
        void PkgList_Loaded(IInspectable const &sender, RoutedEventArgs const &e);

    private:
        UFCase::PackagesPageViewModel::Navigated_revoker m_navigated_revoker;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPage : PackagesPageT<PackagesPage, implementation::PackagesPage>
    {
    };
} // namespace winrt::UFCase::factory_implementation
