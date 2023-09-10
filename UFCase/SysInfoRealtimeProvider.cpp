#include "pch.h"
#include "SysInfoRealtimeProvider.h"
#if __has_include("SysInfoRealtimeProvider.g.cpp")
#include "SysInfoRealtimeProvider.g.cpp"
#endif

namespace winrt::UFCase::implementation
{
    SysInfoRealtimeProvider::SysInfoRealtimeProvider()
    {
        using namespace std::chrono_literals;
        m_timer.Interval(1s);
        m_update_token = m_timer.Tick([this](auto &, auto &) {
            NotifyPropChange(L"CPUUtilization");
            NotifyPropChange(L"MemoryUsage");
        });
    }

    SysInfoRealtimeProvider::~SysInfoRealtimeProvider()
    {
        m_timer.Tick(m_update_token);
    }

    winrt::DispatcherTimer SysInfoRealtimeProvider::Timer()
    {
        return m_timer;
    }

    double SysInfoRealtimeProvider::CPUUtilization()
    {
        // thread local variable means
        // you can't calculate it util
        // the last calculation in this thread completes
        thread_local winrt::TimeSpan old_all{}, old_idle{};
        auto rep = SystemDiagnosticInfo::GetForCurrentSystem().CpuUsage().GetReport();
        auto cur_all = rep.KernelTime() + rep.UserTime();
        auto dur_all = cur_all - old_all;
        auto cur_idle = rep.IdleTime();
        auto dur_idle = cur_idle - old_idle;

        old_all = cur_all;
        old_idle = cur_idle;

        m_cpu_util = 100 * (1.0 - 1.0 * dur_idle.count() / dur_all.count());

        // update comment
        NotifyPropChange(L"CPUUtilizationComment");

        return m_cpu_util;
    }

    winrt::hstring SysInfoRealtimeProvider::CPUUtilizationComment()
    {
        return std::format(L"{:.1f}%", m_cpu_util).c_str();
    }

    double SysInfoRealtimeProvider::MemoryUsage()
    {
        auto rep = winrt::SystemDiagnosticInfo::GetForCurrentSystem().MemoryUsage().GetReport();
        auto usg = 100.0 * UsedMemoryInBytes(rep) / AllMemoryInBytes(rep);

        // update comment
        NotifyPropChange(L"MemoryUsageComment");

        return usg;
    }

    winrt::hstring SysInfoRealtimeProvider::MemoryUsageComment()
    {
        auto rep = winrt::SystemDiagnosticInfo::GetForCurrentSystem().MemoryUsage().GetReport();
        return std::format(L"{}/{}", TextizeBytes(m_used_mem).c_str(),
                           TextizeBytes(m_all_mem).c_str())
            .c_str();
    }

    uint64_t SysInfoRealtimeProvider::UsedMemoryInBytes(winrt::SystemMemoryUsageReport rep)
    {
        return m_used_mem = rep.CommittedSizeInBytes();
    }

    uint64_t SysInfoRealtimeProvider::AllMemoryInBytes(winrt::SystemMemoryUsageReport rep)
    {
        return m_all_mem = rep.CommittedSizeInBytes() + rep.AvailableSizeInBytes();
    }

    winrt::hstring SysInfoRealtimeProvider::TextizeBytes(uint64_t val)
    {
        double fv = static_cast<double>(val);
        static const wchar_t *unit[] = {L"B", L"KB", L"MB", L"GB", L"TB", L"PB"};

        for (auto &str : unit)
        {
            if (fv <= 1024)
                return std::format(L"{:.1f}{}", fv, str).c_str();
            fv /= 1024.0;
        }
        throw std::invalid_argument("value in bytes is too large!");
    }

} // namespace winrt::UFCase::implementation
