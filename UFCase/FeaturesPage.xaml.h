#pragma once

#include "FeaturesPage.g.h"
#include "FeatureTreeElement.g.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

namespace winrt {
    using namespace Windows::UI::Xaml::Interop;

    inline hstring to_hstring(UFCase::FeatureState const& state) {
        switch (state) {
        case UFCase::FeatureState::Enabled: return L"Enabled";
        case UFCase::FeatureState::Disabled: return L"Disabled";
        case UFCase::FeatureState::PartiallyEnabled: return L"Partially Enabled";
        case UFCase::FeatureState::Unavailable: return L"Unavailable";
        default: return L"Invalid";
        }
    }
}

namespace winrt::UFCase::implementation
{

    struct FeaturesPage : FeaturesPageT<FeaturesPage>
    {
        using source_t = IObservableVector<UFCase::FeatureTreeElement>;
        source_t m_source;

        void ConfigFeatureTreeElementUIElements(FeatureTreeElement ele);

        FeaturesPage();

        source_t FeatureDataSource();

        void OnNavigatedTo(const Navigation::NavigationEventArgs &e);
        void FeatureInstallCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureStageCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureOpenOFDialogCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureAddSourceUICommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);

        bool IsFeatureStateCheckBoxEnabled(FeatureState const& state);
        Windows::Foundation::IReference<bool> IsFeatureStateCheckBoxCheckd(FeatureState const& state);

        void OpenFileButton_Click(IInspectable const&, RoutedEventArgs const&);
        void OpenRegButton_Click(IInspectable const&, RoutedEventArgs const&);
        void OpenKBButton_Click(IInspectable const&, RoutedEventArgs const&);
        
        void FeatureTree_Loaded(IInspectable const&, RoutedEventArgs const&);
        void FeatureTreeItem_DoubleTapped(IInspectable const& sender, Input::DoubleTappedRoutedEventArgs const& e);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPage : FeaturesPageT<FeaturesPage, implementation::FeaturesPage>
    {
    };
}
