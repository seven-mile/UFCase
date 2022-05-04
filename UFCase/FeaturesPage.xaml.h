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

        UFCase::FeaturesPageViewModel m_view_model{ nullptr };
        UFCase::FeaturesPageViewModel ViewModel() { return m_view_model; }

        IAsyncAction OnNavigatedTo(const Navigation::NavigationEventArgs &e);
        void FeatureEnableCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureDisableCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureOpenOFDialogCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureAddSourceUICommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);

        void OpenFileButton_Click(IInspectable const&, RoutedEventArgs const&);
        void OpenRegButton_Click(IInspectable const&, RoutedEventArgs const&);
        void OpenKBButton_Click(IInspectable const&, RoutedEventArgs const&);
        
        void FeatureTreeItem_DoubleTapped(IInspectable const& sender, Input::DoubleTappedRoutedEventArgs const& e);
        void FeatureTreeItem_RightTapped(IInspectable const& sender, Input::RightTappedRoutedEventArgs const& e);

        using vis_t = Microsoft::UI::Xaml::Visibility;
        vis_t ConvertUInt32ToVisibility(uint32_t value) { return value ? vis_t::Visible : vis_t::Collapsed; }
        void AppBarSubmitButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPage : FeaturesPageT<FeaturesPage, implementation::FeaturesPage>
    {
    };
}
