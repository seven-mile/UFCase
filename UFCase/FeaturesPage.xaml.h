#pragma once

#include "FeaturesPage.g.h"
#include "FeatureViewModel.g.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

namespace winrt::UFCase::implementation
{

    struct FeaturesPage : FeaturesPageT<FeaturesPage>
    {
        using source_t = IObservableVector<UFCase::FeatureViewModel>;
        source_t m_source;

        FeaturesPage();

        source_t FeatureDataSource();

        void OnNavigatedTo(const Navigation::NavigationEventArgs &e);
        void FeatureEnableCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureDisableCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureOpenOFDialogCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureAddSourceUICommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);

        void OpenFileButton_Click(IInspectable const&, RoutedEventArgs const&);
        void OpenRegButton_Click(IInspectable const&, RoutedEventArgs const&);
        void OpenKBButton_Click(IInspectable const&, RoutedEventArgs const&);
        
        void FeatureTree_Loaded(IInspectable const&, RoutedEventArgs const&);
        void FeatureTreeItem_DoubleTapped(IInspectable const& sender, Input::DoubleTappedRoutedEventArgs const& e);

        using vis_t = Microsoft::UI::Xaml::Visibility;
        vis_t ConvertUInt32ToVisibility(uint32_t value) { return value ? vis_t::Visible : vis_t::Collapsed; }
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPage : FeaturesPageT<FeaturesPage, implementation::FeaturesPage>
    {
    };
}
