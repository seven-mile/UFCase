#pragma once

#include "FeaturesPage.g.h"
#include "FeatureTreeElement.g.h"

namespace winrt::UFCase::implementation
{
    struct FeaturesPage : FeaturesPageT<FeaturesPage>
    {
        using source_t = IObservableVector<UFCase::FeatureTreeElement>;

        FeaturesPage();

        source_t FeatureDataSource();

        void OnNavigatedTo(const winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs &e);

    private:
        source_t m_source;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPage : FeaturesPageT<FeaturesPage, implementation::FeaturesPage>
    {
    };
}
