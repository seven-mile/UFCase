#include "pch.h"

#include "AppConfig.h"

#include "SysInfoPage.xaml.h"
#if __has_include("SysInfoPage.g.cpp")
#include "SysInfoPage.g.cpp"
#endif

#include "GlobalUtil.h"

namespace winrt::UFCase::implementation
{
    SysInfoPage::SysInfoPage()
    {
    }

    void SysInfoPage::InitializeComponent()
    {
        SysInfoPageT::InitializeComponent();

        auto ivm = GlobalRes::MainWnd().ViewModel();
        m_static = UFCase::SysInfoStaticViewModel(ivm.SelectedImageModel());

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

    void SysInfoPage::ToggleSwitch_Toggled(IInspectable const &sender, RoutedEventArgs const &)
    {
        auto swch = sender.as<ToggleSwitch>();
        if (swch.IsOn())
            this->RealtimeInfo().Timer().Start();
        else
            this->RealtimeInfo().Timer().Stop();

        AppConfig::SetSysinfoAutoRefresh(swch.IsOn());
        AppConfig::WriteAppConfigToFile();
    }

} // namespace winrt::UFCase::implementation
