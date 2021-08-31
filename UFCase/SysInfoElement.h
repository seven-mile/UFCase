#pragma once

#include "SysInfoStaticElement.g.h"
#include "SysInfoRealtimeElement.g.h"

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

        double CPUUtilization();

        uint64_t UsedMemoryInBytes();
        uint64_t AllMemoryInBytes();
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
