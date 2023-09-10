#pragma once

#include "SysInfoRealtimeProvider.g.h"

#include "PropChgUtil.h"

#include <winrt/Windows.System.Diagnostics.h>

namespace winrt
{
    using namespace Windows::System::Diagnostics;
}

namespace winrt::UFCase::implementation
{
    struct SysInfoRealtimeProvider : SysInfoRealtimeProviderT<SysInfoRealtimeProvider>,
                                     ImplPropertyChangedT<SysInfoRealtimeProvider>
    {
        SysInfoRealtimeProvider();
        ~SysInfoRealtimeProvider();

        winrt::DispatcherTimer Timer();

        double CPUUtilization();
        winrt::hstring CPUUtilizationComment();

        double MemoryUsage();
        winrt::hstring MemoryUsageComment();

      private:
        winrt::DispatcherTimer m_timer;
        winrt::event_token m_update_token;
        uint64_t UsedMemoryInBytes(winrt::SystemMemoryUsageReport rep);
        uint64_t AllMemoryInBytes(winrt::SystemMemoryUsageReport rep);
        winrt::hstring TextizeBytes(uint64_t val);
        double m_cpu_util = 0;
        uint64_t m_used_mem = 0, m_all_mem = 0;
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct SysInfoRealtimeProvider
        : SysInfoRealtimeProviderT<SysInfoRealtimeProvider, implementation::SysInfoRealtimeProvider>
    {
    };
} // namespace winrt::UFCase::factory_implementation
