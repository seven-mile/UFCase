#pragma once

#include "RootSettingsPage.g.h"

namespace winrt::UFCase::implementation
{
    struct RootSettingsPage : RootSettingsPageT<RootSettingsPage>
    {
        RootSettingsPage();
        void Group4Row1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct RootSettingsPage : RootSettingsPageT<RootSettingsPage, implementation::RootSettingsPage>
    {
    };
}
