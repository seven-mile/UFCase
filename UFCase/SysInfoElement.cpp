#include "pch.h"
#include "SysInfoElement.h"
#if __has_include("SysInfoStaticElement.g.cpp")
#include "SysInfoStaticElement.g.cpp"
#endif
#if __has_include("SysInfoRealtimeElement.g.cpp")
#include "SysInfoRealtimeElement.g.cpp"
#endif

#include "CbsSessionManager.h"
#include "MallocUtil.h"

#include <wil/resource.h>

#include <format>

#include "AppConfig.hpp"

namespace winrt {
    using namespace Windows::System::Diagnostics;
}

namespace winrt::UFCase::implementation
{
    // Static Part

    SysInfoStaticElement::SysInfoStaticElement()
    {
        { // m_firm
            FIRMWARE_TYPE type{};
            winrt::check_bool(GetFirmwareType(&type));
            switch (type)
            {
            case FirmwareTypeBios:
                this->m_firmware = L"BIOS";
                break;
            case FirmwareTypeUefi:
                this->m_firmware = L"UEFI";
                break;
            default:
                this->m_firmware = L"Unknown";
                break;
            }
        }
        //{ // m_arch
        //	using namespace Windows::ApplicationModel;
        //	using namespace Windows::System;

        //	switch (Package::Current().Id().Architecture()) {
        //	case ProcessorArchitecture::Arm: this->m_arch = L"Arm"; break;
        //	case ProcessorArchitecture::Arm64: this->m_arch = L"Arm64"; break;
        //	case ProcessorArchitecture::X86: this->m_arch = L"X86"; break;
        //	case ProcessorArchitecture::X64: this->m_arch = L"X64"; break;
        //	case ProcessorArchitecture::Neutral: this->m_arch = L"Neutral"; break;
        //	case ProcessorArchitecture::X86OnArm64: this->m_arch = L"X86OnArm64"; break;
        //	default: this->m_arch = L"Unknown"; break;
        //	}
        //}
        { // CBS Product Info
            auto pSess = CbsSessionManager::instance().ApplyNew();
            // init corresponding session
            if (CbsSessionManager::GetCurrentSource() == CbsSessionManager::StackSource::Online) {
                winrt::check_hresult(pSess->Initialize(CbsSessionOptionNone, L"UFCase", nullptr, nullptr));
            } else {
                winrt::check_hresult(pSess->Initialize(
                    CbsSessionOptionNone, L"UFCase",
                    CbsSessionManager::GetCurrentBootdrive().c_str(),
                    CbsSessionManager::GetCurrentWindir().c_str()
                ));
            }

            winrt::com_ptr<ICbsIdentity> pId;
            winrt::check_hresult(pSess->CreateCbsIdentity(pId.put()));
            winrt::check_hresult(pId->LoadFromStringId(L"@Product"));

            winrt::com_ptr<ICbsPackage> pRawPkg;
            pSess->OpenPackage(0, pId.get(), nullptr, pRawPkg.put());
            auto pPkg = pRawPkg.as<ICbsPackage>();

            unique_malloc_wstring strId;
            pPkg->GetProperty(CbsPackagePropertyIdentityString, wil::out_param(strId));
            
            // ref: [Product]-[Feature]-Package~[PublicKeyToken]~[Architecture]~[Language]~[Version]
            std::wstring_view wv = strId.get();

            // OSDisplayName
            this->m_os = std::wstring(wv.substr(0, wv.find_first_of(L'~')));
            // OSVersion
            this->m_ver = std::wstring(wv.substr(wv.find_last_of(L'~')+1));

            // OSArchitechture
            const auto token_pos = wv.find_first_of(L'~') + 1;
            const auto arch_pos = wv.find_first_of(L'~', token_pos) + 1;
            this->m_arch = std::wstring(wv.substr(arch_pos, wv.substr(arch_pos).find_first_of(L'~')));
        }
        { // WinPE
            this->m_ispe = false;
            // option1: %WINDIR%\system32\winpeshl.exe
            // option2: HKLM\Microsoft\Windows NT\CurrentVersion\WinPE
            // option3: HKLM\SYSTEM\CurrentControlSet\Control\MiniNT

            // use option2
            wil::unique_hkey hkey;
            auto lst = RegOpenKey(HKEY_LOCAL_MACHINE, L"Microsoft\\Windows NT\\CurrentVersion\\WinPE", wil::out_param(hkey));
            if (lst == ERROR_SUCCESS) {
                this->m_ispe = true;
            } else if (lst == ERROR_FILE_NOT_FOUND) {
                this->m_ispe = false;
            } else {
                // throw
                winrt::check_win32(lst);
            }
            // clear LE
            SetLastError(0);
        }
        { // Manufacturer
            // HKLM\HARDWARE\DESCRIPTION\System\BIOS\SystemManufacturer
            wil::unique_hkey hkey;
            winrt::check_win32(RegOpenKey(HKEY_LOCAL_MACHINE,
                L"HARDWARE\\DESCRIPTION\\System\\BIOS", wil::out_param(hkey)));
            DWORD dwType, dwCnt{};
            winrt::check_win32(RegQueryValueEx(hkey.get(), L"SystemManufacturer", 0, &dwType, nullptr, &dwCnt));
            std::vector<BYTE> buffer; buffer.assign(dwCnt, 0);
            winrt::check_win32(RegQueryValueEx(hkey.get(), L"SystemManufacturer", 0, &dwType, buffer.data(), &dwCnt));
            this->m_manu = reinterpret_cast<LPWSTR>(buffer.data());
        }
        { // CPUDisplayName
            // HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0\ProcessorNameString
            wil::unique_hkey hkey;
            winrt::check_win32(RegOpenKey(HKEY_LOCAL_MACHINE,
                L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", wil::out_param(hkey)));
            DWORD dwType, dwCnt{};
            winrt::check_win32(RegQueryValueEx(hkey.get(), L"ProcessorNameString", 0, &dwType, nullptr, &dwCnt));
            std::vector<BYTE> buffer; buffer.assign(dwCnt, 0);
            winrt::check_win32(RegQueryValueEx(hkey.get(), L"ProcessorNameString", 0, &dwType, buffer.data(), &dwCnt));
            this->m_cpu = reinterpret_cast<LPWSTR>(buffer.data());
        }
    }
    winrt::hstring SysInfoStaticElement::FirmwareType()
    {
        return m_firmware;
    }
    void SysInfoStaticElement::FirmwareType(const winrt::hstring& val)
    {
        m_firmware = val;
    }
    winrt::hstring SysInfoStaticElement::Architecture()
    {
        return m_arch;
    }
    void SysInfoStaticElement::Architecture(const winrt::hstring& val)
    {
        m_arch = val;
    }
    winrt::hstring SysInfoStaticElement::OSDisplayName()
    {
        return m_os;
    }
    void SysInfoStaticElement::OSDisplayName(const winrt::hstring& val)
    {
        m_os = val;
    }
    winrt::hstring SysInfoStaticElement::OSVersion()
    {
        return m_ver;
    }
    void SysInfoStaticElement::OSVersion(const winrt::hstring& val)
    {
        m_ver = val;
    }
    bool SysInfoStaticElement::IsWinPE()
    {
        return m_ispe;
    }
    void SysInfoStaticElement::IsWinPE(bool val)
    {
        m_ispe = val;
    }
    winrt::hstring SysInfoStaticElement::Manufacturer()
    {
        return m_manu;
    }
    void SysInfoStaticElement::Manufacturer(const winrt::hstring& val)
    {
        m_manu = val;
    }
    winrt::hstring SysInfoStaticElement::CPUDisplayName()
    {
        return m_cpu;
    }
    void SysInfoStaticElement::CPUDisplayName(const winrt::hstring& val)
    {
        m_cpu = val;
    }

    // Realtime Part

    SysInfoRealtimeElement::SysInfoRealtimeElement()
    {
        using namespace std::chrono_literals;
        m_timer.Interval(1s);
        m_update_token = m_timer.Tick([this, &chg = this->m_propertyChanged]
            (auto &/*sender*/, auto &/*args*/){
            chg(*this, winrt::Data::PropertyChangedEventArgs{L"CPUUtilization"});
            chg(*this, winrt::Data::PropertyChangedEventArgs{L"MemoryUsage"});
        });
    }
    SysInfoRealtimeElement::~SysInfoRealtimeElement()
    {
        m_timer.Tick(m_update_token);
    }
    winrt::DispatcherTimer SysInfoRealtimeElement::Timer()
    {
        return m_timer;
    }
    double SysInfoRealtimeElement::CPUUtilization()
    {
        // thread local variable means
        // you can't calculate it util
        // the last calculation in this thread completes
        thread_local winrt::TimeSpan old_all{}, old_idle{};
        auto rep = SystemDiagnosticInfo::GetForCurrentSystem()
            .CpuUsage().GetReport();
        auto cur_all = rep.KernelTime() + rep.UserTime();
        auto dur_all = cur_all - old_all;
        auto cur_idle = rep.IdleTime();
        auto dur_idle = cur_idle - old_idle;

        old_all = cur_all;
        old_idle = cur_idle;

        m_cpu_util = 100 * (1.0 - 1.0 * dur_idle.count() / dur_all.count());

        // update comment
        this->m_propertyChanged(*this, winrt::Data::PropertyChangedEventArgs{L"CPUUtilizationComment"});

        return m_cpu_util;
    }
    winrt::hstring SysInfoRealtimeElement::CPUUtilizationComment()
    {
        return std::format(L"{:.1f}%", m_cpu_util).c_str();
    }
    double SysInfoRealtimeElement::MemoryUsage()
    {
        auto rep = winrt::SystemDiagnosticInfo::GetForCurrentSystem()
            .MemoryUsage().GetReport();
        auto usg = 100.0 * UsedMemoryInBytes(rep) / AllMemoryInBytes(rep);

        // update comment
        this->m_propertyChanged(*this, winrt::Data::PropertyChangedEventArgs{L"MemoryUsageComment"});

        return usg;
    }
    winrt::hstring SysInfoRealtimeElement::MemoryUsageComment()
    {
        auto rep = winrt::SystemDiagnosticInfo::GetForCurrentSystem()
            .MemoryUsage().GetReport();
        return std::format(L"{}/{}",
            TextizeBytes(m_used_mem).c_str(), TextizeBytes(m_all_mem).c_str()).c_str();
    }
    winrt::event_token SysInfoRealtimeElement::PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value)
    {
        return m_propertyChanged.add(value);
    }
    void SysInfoRealtimeElement::PropertyChanged(winrt::event_token const& token)
    {
        m_propertyChanged.remove(token);
    }
    uint64_t SysInfoRealtimeElement::UsedMemoryInBytes(winrt::SystemMemoryUsageReport rep)
    {
        return m_used_mem = rep.CommittedSizeInBytes();
    }
    uint64_t SysInfoRealtimeElement::AllMemoryInBytes(winrt::SystemMemoryUsageReport rep)
    {
        return m_all_mem = rep.CommittedSizeInBytes() + rep.AvailableSizeInBytes();
    }
    winrt::hstring SysInfoRealtimeElement::TextizeBytes(uint64_t val)
    {
        double fv = static_cast<double>(val);
        static const wchar_t *unit[] = {
            L"B", L"KB", L"MB", L"GB", L"TB", L"PB"
        };

        for (auto &str : unit) {
            if (fv <= 1024)
                return std::format(L"{:.1f}{}", fv, str).c_str();
            fv /= 1024.0;
        }
        throw std::invalid_argument("value in bytes is too large!");
    }
}
