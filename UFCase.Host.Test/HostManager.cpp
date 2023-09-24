#include "pch.h"
#include "HostManager.h"
#if __has_include("HostManager.g.cpp")
#include "HostManager.g.cpp"
#endif

#include <winrt/UFCase.Host.Manifest.h>

#include <wil/cppwinrt_wrl.h>

namespace winrt::UFCase::Isolation::implementation
{

    void TestManifest(UFCase::Host::Manifest::Assembly assembly)
    {
        wprintf(L"%s", winrt::format(L"{} v{}\n", assembly.Name(), assembly.Version()).c_str());

        for (auto &file : assembly.Files())
        {
            wprintf(L"%s", winrt::format(L"file: [{}] {} {}\n", file.DestinationName(), file.Hash(),
                                         file.SizeInByte())
                               .c_str());
        }

        for (auto &key : assembly.Keys())
        {
            wprintf(
                L"%s",
                winrt::format(L"key: [{}] {} values\n", key.Name(), key.Values().size()).c_str());

            for (auto &value : key.Values())
            {
                wprintf(L"%s",
                        winrt::format(
                            L"key value: [{}] {} {}\n", value.Name(), (int)value.Type(),
                            winrt::unbox_value_or<winrt::hstring>(value.Data(), L"unsupported"))
                            .c_str());
            }
        }

        for (auto &dep : assembly.Dependencies())
        {
            wprintf(L"%s",
                    winrt::format(L"dep: [{}] {}\n", dep.Identity().KeyForm(), dep.Type()).c_str());
        }
    }

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

            TestManifest(comp.CookedManifest());
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
