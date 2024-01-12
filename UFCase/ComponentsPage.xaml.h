#pragma once

#include "ComponentsPage.g.h"

namespace winrt::UFCase::implementation
{
    struct ComponentsPage : ComponentsPageT<ComponentsPage>
    {
        ComponentsPage()
        {
        }

        void OnNavigatedTo(const Navigation::NavigationEventArgs &e);

        UFCase::ComponentsPageViewModel m_view_model{nullptr};
        UFCase::ComponentsPageViewModel ViewModel()
        {
            return m_view_model;
        }

        void ListViewItem_RightTapped(IInspectable const &sender,
                                      Input::RightTappedRoutedEventArgs const &e);
        void GotoSelectionButton_Click(IInspectable const &sender, RoutedEventArgs const &e);
        void GotoTopButton_Click(IInspectable const &sender, RoutedEventArgs const &e);
        void CompList_SelectionChanged(IInspectable const &sender,
                                       Controls::SelectionChangedEventArgs const &e);

      private:
        UFCase::ComponentsPageViewModel::Navigated_revoker m_navigated_revoker;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ComponentsPage : ComponentsPageT<ComponentsPage, implementation::ComponentsPage>
    {
    };
} // namespace winrt::UFCase::factory_implementation
