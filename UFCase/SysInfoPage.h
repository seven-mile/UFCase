#pragma once

#include <winrt/Windows.UI.Composition.h>

namespace winrt {
    using namespace Windows::UI::Composition;
}

#include "SysInfoPage.g.h"

namespace winrt::UFCase::implementation
{
    struct SysInfoPage : SysInfoPageT<SysInfoPage>
    {
        SysInfoPage();

        void InitializeComposition();

        UFCase::SysInfoStaticElement StaticInfo();
        UFCase::SysInfoRealtimeElement RealtimeInfo();
        void ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        UFCase::SysInfoStaticElement m_static;
        UFCase::SysInfoRealtimeElement m_realtime;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct SysInfoPage : SysInfoPageT<SysInfoPage, implementation::SysInfoPage>
    {
    };
}
