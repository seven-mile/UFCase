#pragma once

#include <winrt/Windows.UI.Composition.h>

namespace winrt {
    using namespace Windows::Data::Json;
}

#include "SysInfoPage.g.h"

namespace winrt::UFCase::implementation
{
    struct SysInfoPage : SysInfoPageT<SysInfoPage>
    {
        SysInfoPage();

        UFCase::SysInfoStaticElement StaticInfo();
        UFCase::SysInfoRealtimeElement RealtimeInfo();
        IAsyncAction ToggleSwitch_Toggled(IInspectable const& sender, RoutedEventArgs const& e);

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
