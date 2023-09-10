#include "pch.h"
#include "HardwareInfoModel.h"

#include <wil/resource.h>

namespace winrt::UFCase
{
    hstring HardwareInfoModel::GetFirmwareType()
    {
        FIRMWARE_TYPE type{};
        check_bool(::GetFirmwareType(&type));
        switch (type)
        {
        case FirmwareTypeBios:
            return L"BIOS";
            break;
        case FirmwareTypeUefi:
            return L"UEFI";
            break;
        default:
            return L"Unknown";
            break;
        }
    }

    hstring HardwareInfoModel::GetManufacturer()
    {
        // HKLM\HARDWARE\DESCRIPTION\System\BIOS\SystemManufacturer
        wil::unique_hkey hkey;
        winrt::check_win32(RegOpenKey(HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\BIOS",
                                      wil::out_param(hkey)));
        DWORD dwType, dwCnt{};
        winrt::check_win32(
            RegQueryValueEx(hkey.get(), L"SystemManufacturer", 0, &dwType, nullptr, &dwCnt));
        std::vector<BYTE> buffer;
        buffer.assign(dwCnt, 0);
        winrt::check_win32(
            RegQueryValueEx(hkey.get(), L"SystemManufacturer", 0, &dwType, buffer.data(), &dwCnt));
        return reinterpret_cast<LPWSTR>(buffer.data());
    }

    hstring HardwareInfoModel::GetCPUArchitecture()
    {
        SYSTEM_INFO sysinfo;
        // ignore WoW64 simulation
        GetNativeSystemInfo(&sysinfo);
        switch (sysinfo.wProcessorArchitecture)
        {
        case PROCESSOR_ARCHITECTURE_INTEL:
            return L"intel";
        case PROCESSOR_ARCHITECTURE_MIPS:
            return L"mips";
        case PROCESSOR_ARCHITECTURE_ALPHA:
            return L"alpha";
        case PROCESSOR_ARCHITECTURE_PPC:
            return L"ppc";
        case PROCESSOR_ARCHITECTURE_SHX:
            return L"shx";
        case PROCESSOR_ARCHITECTURE_ARM:
            return L"arm";
        case PROCESSOR_ARCHITECTURE_IA64:
            return L"ia64";
        case PROCESSOR_ARCHITECTURE_ALPHA64:
            return L"alpha64";
        case PROCESSOR_ARCHITECTURE_MSIL:
            return L"msil";
        case PROCESSOR_ARCHITECTURE_AMD64:
            return L"amd64";
        case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64:
            return L"ia32_win64";
        case PROCESSOR_ARCHITECTURE_NEUTRAL:
            return L"neutral";
        case PROCESSOR_ARCHITECTURE_ARM64:
            return L"arm64";
        case PROCESSOR_ARCHITECTURE_ARM32_ON_WIN64:
            return L"arm32_win64";
        case PROCESSOR_ARCHITECTURE_IA32_ON_ARM64:
            return L"ia32_arm64";
        default:
            return L"(null)";
        }
    }

    hstring HardwareInfoModel::GetCPUDisplayName()
    {
        // HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0\ProcessorNameString
        wil::unique_hkey hkey;
        winrt::check_win32(RegOpenKey(HKEY_LOCAL_MACHINE,
                                      L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                                      wil::out_param(hkey)));
        DWORD dwType, dwCnt{};
        winrt::check_win32(
            RegQueryValueEx(hkey.get(), L"ProcessorNameString", 0, &dwType, nullptr, &dwCnt));
        std::vector<BYTE> buffer;
        buffer.assign(dwCnt, 0);
        winrt::check_win32(
            RegQueryValueEx(hkey.get(), L"ProcessorNameString", 0, &dwType, buffer.data(), &dwCnt));
        return reinterpret_cast<LPWSTR>(buffer.data());
    }

} // namespace winrt::UFCase
