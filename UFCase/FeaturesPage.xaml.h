#pragma once

#include "FeaturesPage.g.h"
#include "FeatureTreeElement.g.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

namespace winrt {
    using namespace Windows::UI::Xaml::Interop;
}

namespace winrt::UFCase::implementation
{

    struct FeaturesPage : FeaturesPageT<FeaturesPage>
    {
        using source_t = IObservableVector<UFCase::FeatureTreeElement>;

        FeaturesPage();

        source_t FeatureDataSource();

        void OnNavigatedTo(const Navigation::NavigationEventArgs &e);
        void FeatureInstallCommand_ExecuteRequested(Input::XamlUICommand const& sender, Input::ExecuteRequestedEventArgs const& args);
        void FeatureStageCommand_ExecuteRequested(winrt::Microsoft::UI::Xaml::Input::XamlUICommand const& sender, winrt::Microsoft::UI::Xaml::Input::ExecuteRequestedEventArgs const& args);

    private:
        source_t m_source;

        void ConfigFeatureTreeElementUIElements(FeatureTreeElement ele);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPage : FeaturesPageT<FeaturesPage, implementation::FeaturesPage>
    {
    };
}
