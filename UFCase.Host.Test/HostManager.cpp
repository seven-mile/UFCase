#include "pch.h"
#include "HostManager.h"
#if __has_include("HostManager.g.cpp")
#include "HostManager.g.cpp"
#endif

#include <wil/cppwinrt_wrl.h>

namespace winrt::UFCase::Isolation::implementation
{
    void HostManager::RegisterHost(Isolation::Host host)
    {
        std::unique_lock g{m_mtx};
        wprintf(winrt::format(L"host connecting: {} [{}]\n", winrt::to_hstring(host.Id()),
                              host.Bootdrive())
                    .c_str());
        host.Ping();
    }
    void HostManager::UnregisterHost(Isolation::Host host)
    {
        std::unique_lock g{m_mtx};
        wprintf(winrt::format(L"host disconnecting: {} [{}]\n", winrt::to_hstring(host.Id()),
                              host.Bootdrive())
                    .c_str());
        host.Ping();
    }
} // namespace winrt::UFCase::Isolation::implementation
