#include "pch.h"

#include "AppConfig.h"

#include "SysInfoPage.h"
#if __has_include("SysInfoPage.g.cpp")
#include "SysInfoPage.g.cpp"
#endif

namespace winrt::UFCase::implementation
{
    SysInfoPage::SysInfoPage()
    {
        InitializeComponent();

        auto imgProv = Application::Current().Resources().Lookup(box_value(L"ImageProviderInstance")).as<UFCase::ImageProvider>();
        m_static = UFCase::SysInfoStaticProvider(imgProv.Images().GetAt(imgProv.SelectedIndex()));

        this->AutoRefreshSwitch().IsOn(g_appConfig.GetNamedObject(L"sysInfo").GetNamedBoolean(L"autoRefresh"));
    }

    UFCase::SysInfoStaticProvider SysInfoPage::StaticInfo()
    {
        return m_static;
    }

    UFCase::SysInfoRealtimeProvider SysInfoPage::RealtimeInfo()
    {
        return m_realtime;
    }

    void SysInfoPage::ToggleSwitch_Toggled(IInspectable const& sender, RoutedEventArgs const&)
    {
        auto swch = sender.as<winrt::ToggleSwitch>();
        if (swch.IsOn())
            this->RealtimeInfo().Timer().Start();
        else this->RealtimeInfo().Timer().Stop();

        g_appConfig.GetNamedObject(L"sysInfo").SetNamedValue(L"autoRefresh", JsonValue::CreateBooleanValue(swch.IsOn()));
        WriteAppConfigToFile();
    }

}


