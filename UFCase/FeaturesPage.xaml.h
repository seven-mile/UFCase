#pragma once

#include "FeaturesPage.g.h"
#include "FeatureViewModel.g.h"
#include "FeaturesPageViewModel.g.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

namespace winrt::UFCase::implementation
{

    struct FeaturesPage : FeaturesPageT<FeaturesPage>
    {
        FeaturesPage();

        UFCase::FeaturesPageViewModel m_view_model{nullptr};
        UFCase::FeaturesPageViewModel ViewModel()
        {
            return m_view_model;
        }

        void OnNavigatedTo(const Navigation::NavigationEventArgs &e);

        void FeatureTreeItem_DoubleTapped(IInspectable const &sender,
                                          Input::DoubleTappedRoutedEventArgs const &e);
        void FeatureTreeItem_RightTapped(IInspectable const &sender,
                                         Input::RightTappedRoutedEventArgs const &e);
        void FeatureTree_SelectionChanged(IInspectable const &sender,
                                          Controls::TreeViewSelectionChangedEventArgs const &args);

        Input::ICommand::CanExecuteChanged_revoker m_feature_enable_revoker;
        Input::ICommand::CanExecuteChanged_revoker m_feature_disable_revoker;
        Input::ICommand::CanExecuteChanged_revoker m_feature_goto_revoker;
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPage : FeaturesPageT<FeaturesPage, implementation::FeaturesPage>
    {
    };
} // namespace winrt::UFCase::factory_implementation
