#include "pch.h"
#include "SysInfoPage.h"
#if __has_include("SysInfoPage.g.cpp")
#include "SysInfoPage.g.cpp"
#endif

#include <winrt/Microsoft.UI.Xaml.Hosting.h>

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UFCase::implementation
{
    SysInfoPage::SysInfoPage()
    {
        InitializeComponent();

        InitializeComposition();
    }

    void SysInfoPage::InitializeComposition()
    {
        { // StaticInfoPane
            // not working???
            // todo: new drop shadow
            //auto comp = Hosting::ElementCompositionPreview::GetElementVisual(StaticInfoPane()).Compositor();
            //auto shad = comp.CreateDropShadow();
            //shad.BlurRadius(5);
            //shad.Offset({0,0,0});
            //shad.Color(winrt::Windows::UI::Colors::DarkGray());
            //auto sprit = comp.CreateSpriteVisual();
            //sprit.Shadow(shad);
            //sprit.Size(StaticInfoPane().ActualSize());
            //Hosting::ElementCompositionPreview::SetElementChildVisual(StaticInfoPane(), sprit);
        }
    }

    UFCase::SysInfoStaticElement SysInfoPage::StaticInfo()
    {
        return m_static;
    }

    UFCase::SysInfoRealtimeElement SysInfoPage::RealtimeInfo()
    {
        return m_realtime;
    }

    void SysInfoPage::ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        auto swch = sender.as<winrt::ToggleSwitch>();
        if (swch.IsOn())
            this->RealtimeInfo().Timer().Start();
        else this->RealtimeInfo().Timer().Stop();
    }

}


