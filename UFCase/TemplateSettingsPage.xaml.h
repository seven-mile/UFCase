#pragma once

#include "TemplateSettingsPage.g.h"

namespace winrt::UFCase::implementation
{
    struct TemplateSettingsPage : TemplateSettingsPageT<TemplateSettingsPage>
    {
        TemplateSettingsPage();
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct TemplateSettingsPage : TemplateSettingsPageT<TemplateSettingsPage, implementation::TemplateSettingsPage>
    {
    };
}
