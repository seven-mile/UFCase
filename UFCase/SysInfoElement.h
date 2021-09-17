#pragma once

#include "SysInfoStaticElement.g.h"
#include "SysInfoRealtimeElement.g.h"

#include <winrt/Windows.System.Diagnostics.h>

namespace winrt {
    using namespace Windows::System::Diagnostics;
}

namespace winrt::UFCase::implementation
{
    struct SysInfoStaticElement : SysInfoStaticElementT<SysInfoStaticElement>
    {
        SysInfoStaticElement();

        // Basic Env
        winrt::hstring FirmwareType();
        void FirmwareType(const winrt::hstring &val);
        winrt::hstring Architecture();
        void Architecture(const winrt::hstring &val);

        // OS
        winrt::hstring OSDisplayName();
        void OSDisplayName(const winrt::hstring &val);
        winrt::hstring OSVersion();
        void OSVersion(const winrt::hstring &val);
        bool IsWinPE();
        void IsWinPE(bool val);

        // Firmware
        winrt::hstring Manufacturer();
        void Manufacturer(const winrt::hstring &val);
        winrt::hstring CPUDisplayName();
        void CPUDisplayName(const winrt::hstring &val);

    private:
        winrt::hstring m_firmware, m_os, m_manu, m_cpu;
        winrt::hstring m_arch;
        winrt::hstring m_ver;
        bool m_ispe;
    };

    struct SysInfoRealtimeElement : SysInfoRealtimeElementT<SysInfoRealtimeElement>
    {
        SysInfoRealtimeElement();
        ~SysInfoRealtimeElement();

        winrt::DispatcherTimer Timer();

        double CPUUtilization();
        winrt::hstring CPUUtilizationComment();

        double MemoryUsage();
        winrt::hstring MemoryUsageComment();

        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value);
        void PropertyChanged(winrt::event_token const& token);

    private:
        winrt::DispatcherTimer m_timer;
        winrt::event_token m_update_token;
        winrt::event<winrt::Data::PropertyChangedEventHandler> m_propertyChanged;
        uint64_t UsedMemoryInBytes(winrt::SystemMemoryUsageReport rep);
        uint64_t AllMemoryInBytes(winrt::SystemMemoryUsageReport rep);
        winrt::hstring TextizeBytes(uint64_t val);
        double m_cpu_util = 0;
        uint64_t m_used_mem = 0, m_all_mem = 0;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct SysInfoStaticElement : SysInfoStaticElementT<SysInfoStaticElement, implementation::SysInfoStaticElement>
    {
    };

    struct SysInfoRealtimeElement : SysInfoRealtimeElementT<SysInfoRealtimeElement, implementation::SysInfoRealtimeElement>
    {
    };
}
