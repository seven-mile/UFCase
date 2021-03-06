#include "pch.h"

#include "AppConfig.h"

#include "SysInfoPage.h"
#if __has_include("SysInfoPage.g.cpp")
#include "SysInfoPage.g.cpp"
#endif

#include "ImageModel.h"

namespace winrt::UFCase::implementation
{
    SysInfoPage::SysInfoPage()
    {
        InitializeComponent();
        m_static = UFCase::SysInfoStaticViewModel(ImageModel::Current()->GetHandle());

        this->AutoRefreshSwitch().IsOn(AppConfig::GetSysinfoAutoRefresh());
    }

    UFCase::SysInfoStaticViewModel SysInfoPage::StaticInfo()
    {
        return m_static;
    }

    UFCase::SysInfoRealtimeProvider SysInfoPage::RealtimeInfo()
    {
        return m_realtime;
    }

    void SysInfoPage::ToggleSwitch_Toggled(IInspectable const& sender, RoutedEventArgs const&)
    {
        auto swch = sender.as<ToggleSwitch>();
        if (swch.IsOn())
            this->RealtimeInfo().Timer().Start();
        else this->RealtimeInfo().Timer().Stop();

        AppConfig::SetSysinfoAutoRefresh(swch.IsOn());
        AppConfig::WriteAppConfigToFile();
    }

}


