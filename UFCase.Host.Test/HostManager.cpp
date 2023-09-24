#include "pch.h"
#include "HostManager.h"
#if __has_include("HostManager.g.cpp")
#include "HostManager.g.cpp"
#endif

#include <winrt/UFCase.Host.Manifest.h>

#include <wil/cppwinrt_wrl.h>
#include <numeric>

namespace winrt::UFCase::Isolation::implementation
{

    hstring to_hstring(UFCase::Host::Manifest::RegistryValueType type)
    {
        /*
        enum class RegistryValueType : int32_t
        {
            RegNone = 0,
            RegSz = 1,
            RegExpandSz = 2,
            RegBinary = 3,
            RegDword = 4,
            RegDwordBigEndian = 5,
            RegLink = 6,
            RegMultiSz = 7,
            RegResourceList = 8,
            RegFullResourceDescriptor = 9,
            RegResourceRequirementsList = 10,
            RegQword = 11,
        };
        */

        switch (type)
        {
        case UFCase::Host::Manifest::RegistryValueType::RegNone:
            return L"REG_NONE";
        case UFCase::Host::Manifest::RegistryValueType::RegSz:
            return L"REG_SZ";
        case UFCase::Host::Manifest::RegistryValueType::RegExpandSz:
            return L"REG_EXPAND_SZ";
        case UFCase::Host::Manifest::RegistryValueType::RegBinary:
            return L"REG_BINARY";
        case UFCase::Host::Manifest::RegistryValueType::RegDword:
            return L"REG_DWORD";
        case UFCase::Host::Manifest::RegistryValueType::RegDwordBigEndian:
            return L"REG_DWORD_BIG_ENDIAN";
        case UFCase::Host::Manifest::RegistryValueType::RegLink:
            return L"REG_LINK";
        case UFCase::Host::Manifest::RegistryValueType::RegMultiSz:
            return L"REG_MULTI_SZ";
        case UFCase::Host::Manifest::RegistryValueType::RegResourceList:
            return L"REG_RESOURCE_LIST";
        case UFCase::Host::Manifest::RegistryValueType::RegFullResourceDescriptor:
            return L"REG_FULL_RESOURCE_DESCRIPTOR";
        case UFCase::Host::Manifest::RegistryValueType::RegResourceRequirementsList:
            return L"REG_RESOURCE_REQUIREMENTS_LIST";
        case UFCase::Host::Manifest::RegistryValueType::RegQword:
            return L"REG_QWORD";
        default:
            return L"Unknown";
        }
    }

    hstring to_hstring(UFCase::Host::Manifest::RegistryValue val)
    {
        switch (val.Type())
        {
        case UFCase::Host::Manifest::RegistryValueType::RegNone:
            return L"";
        case UFCase::Host::Manifest::RegistryValueType::RegSz:
        case UFCase::Host::Manifest::RegistryValueType::RegExpandSz:
        case UFCase::Host::Manifest::RegistryValueType::RegLink:
            return unbox_value_or<hstring>(val.Data(), L"type error");
        case UFCase::Host::Manifest::RegistryValueType::RegBinary: {
            std::wstring hex;
            auto list = unbox_value<com_array<uint8_t>>(val.Data());
            for (auto &&b : list)
            {
                hex += winrt::format(L"{:02X} ", b).c_str();
            }
            return hex.c_str();
        }
        case UFCase::Host::Manifest::RegistryValueType::RegDword:
        case UFCase::Host::Manifest::RegistryValueType::RegDwordBigEndian:
            return winrt::to_hstring(unbox_value<int32_t>(val.Data()));
        case UFCase::Host::Manifest::RegistryValueType::RegMultiSz: {
            std::wstring result;
            auto list = unbox_value<com_array<hstring>>(val.Data());

            return std::accumulate(list.begin(), list.end(), hstring{},
                                   [](auto &&a, auto &&b) { return a + L" | " + b; });
        }
        case UFCase::Host::Manifest::RegistryValueType::RegResourceList:
            return L"Resource list data";
        case UFCase::Host::Manifest::RegistryValueType::RegFullResourceDescriptor:
            return L"Full resource descriptor data";
        case UFCase::Host::Manifest::RegistryValueType::RegResourceRequirementsList:
            return L"Resource requirements list data";
        case UFCase::Host::Manifest::RegistryValueType::RegQword:
            return winrt::to_hstring(unbox_value<int64_t>(val.Data()));
        default:
            return L"Unknown";
        }
    }

    void TestManifest(UFCase::Host::Manifest::Assembly assembly)
    {
        wprintf(L"%s",
                winrt::format(L"{} v{}\n", assembly.Identity().Name(), assembly.Version().Value())
                    .c_str());

        for (auto &file : assembly.Files())
        {
            wprintf(L"%s", winrt::format(L"file: [{}] {} {} {}\n", file.DestinationName(),
                                         file.DestinationPath(), file.Hash(), file.SizeInByte())
                               .c_str());
        }

        for (auto &key : assembly.Keys())
        {
            wprintf(
                L"%s",
                winrt::format(L"key: [{}] {} values\n", key.Name(), key.Values().size()).c_str());

            for (auto &value : key.Values())
            {
                wprintf(L"%s", winrt::format(L"key value: [{}] {} {}\n", value.Name(),
                                             to_hstring(value.Type()), to_hstring(value))
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

        for (auto obj : img.SxsStore().GetComponentCollection(L"dual_c_fscopyprotection.inf"))
        {
            auto comp = obj.as<Isolation::ComponentModel>();
            wprintf(winrt::format(L"Component: {}\n\t{}\n", comp.TextForm(), comp.PayloadPath())
                        .c_str());

            wprintf(L"  Manifest: %s\n", comp.Manifest().c_str());

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
