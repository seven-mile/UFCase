#pragma once
#include "SysInfoPage.g.h"

#include <winrt/Windows.Data.Json.h>

namespace winrt {
    using namespace Windows::Data::Json;
}


namespace winrt::UFCase::implementation
{
    struct SysInfoPage : SysInfoPageT<SysInfoPage>
    {
        SysInfoPage();

        UFCase::SysInfoStaticProvider StaticInfo();
        UFCase::SysInfoRealtimeProvider RealtimeInfo();
        void ToggleSwitch_Toggled(IInspectable const& sender, RoutedEventArgs const& e);

    private:
        UFCase::SysInfoStaticProvider m_static{nullptr};
        UFCase::SysInfoRealtimeProvider m_realtime;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct SysInfoPage : SysInfoPageT<SysInfoPage, implementation::SysInfoPage>
    {
    };
}
