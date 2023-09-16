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

        auto img = host.Image();
        auto &&[major, minor, build, revision] = img.Version();
        wprintf(winrt::format(L"Image: {}.{}.{}.{} [{}]\n", major, minor, build, revision,
                              img.Edition())
                    .c_str());
        wprintf(winrt::format(L"\t{} {}\n", img.Architecture(), img.IsWinPE()).c_str());

        for (auto obj : img.SxsStore().GetComponentCollection(L"HyperV-Worker-Control"))
        {
            auto comp = obj.as<Isolation::ComponentModel>();
            wprintf(winrt::format(L"Component: {}\n\t{}\n", comp.TextForm(), comp.PayloadPath())
                        .c_str());
        }

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
