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

    private:
        UFCase::SysInfoStaticElement m_static;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct SysInfoPage : SysInfoPageT<SysInfoPage, implementation::SysInfoPage>
    {
    };
}
