#include "pch.h"
#include "SysInfoStaticProvider.h"
#if __has_include("SysInfoStaticProvider.g.cpp")
#include "SysInfoStaticProvider.g.cpp"
#endif

#include "MallocUtil.h"

#include <wil/resource.h>

#include <format>

#include "AppConfig.h"

namespace winrt {
    using namespace Windows::System::Diagnostics;
}

namespace winrt::UFCase::implementation
{
    // Static Part

    SysInfoStaticProvider::SysInfoStaticProvider(UFCase::ImageItem img) : m_img(img) { }
    winrt::hstring SysInfoStaticProvider::FirmwareType()
    {
        FIRMWARE_TYPE type{};
        winrt::check_bool(GetFirmwareType(&type));
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
    winrt::hstring SysInfoStaticProvider::OSArchitecture()
    {
        TryOpenProductPackage();
        std::wstring_view wv = m_strProdPkgId;
        const auto token_pos = wv.find_first_of(L'~') + 1;
        const auto arch_pos = wv.find_first_of(L'~', token_pos) + 1;
        return std::wstring(wv.substr(arch_pos, wv.substr(arch_pos).find_first_of(L'~'))).c_str();
    }
    winrt::hstring SysInfoStaticProvider::OSDisplayName()
    {
        TryOpenProductPackage();
        std::wstring_view wv = m_strProdPkgId;
        return std::wstring(wv.substr(0, wv.find_first_of(L'~'))).c_str();
    }
    winrt::hstring SysInfoStaticProvider::OSVersion()
    {
        TryOpenProductPackage();
        std::wstring_view wv = m_strProdPkgId;
        return std::wstring(wv.substr(wv.find_last_of(L'~')+1)).c_str();
    }
    bool SysInfoStaticProvider::IsWinPE()
    {
        TryInitCbsSession();
        // now the offline registry should
        // have been loaded.
        
        // option1: %WINDIR%\system32\winpeshl.exe
        // option2: HKLM\Microsoft\Windows NT\CurrentVersion\WinPE
        // option3: HKLM\SYSTEM\CurrentControlSet\Control\MiniNT
        if (CbsSessionManager::instance().GetCurrentSource() == CbsSessionManager::StackSource::Offline) {
            // todo: use offline registry
            throw winrt::hresult_not_implemented{};
        } else {
            // online, use option2
            wil::unique_hkey hkey;
            auto lst = RegOpenKey(HKEY_LOCAL_MACHINE, L"Microsoft\\Windows NT\\CurrentVersion\\WinPE", wil::out_param(hkey));
            SetLastError(0);

            if (lst == ERROR_SUCCESS) {
                return true;
            } else if (lst == ERROR_FILE_NOT_FOUND) {
                return false;
            } else {
                throw winrt::hresult_error{ HRESULT_FROM_WIN32(lst) };
            }
        }
    }
    void SysInfoStaticProvider::TryInitCbsSession()
    {
        if (!m_pSess) {
            // todo: use factory distribution
            if (m_img.Type() == L"Online") {
                try {
                    CbsSessionManager::instance().BindStack(CbsSessionManager::StackSource::Online);
                } catch (winrt::hresult_error const &) { }
            } else if (m_img.Type() == L"Offline") {
                try {
                    CbsSessionManager::instance().BindStack(
                        CbsSessionManager::StackSource::Offline,
                        m_img.Bootdrive().c_str()
                    );
                } catch (winrt::hresult_error const &) { }
            } else throw hresult_invalid_argument{};

            // warning: unexpected behavior when switching between images
            m_pSess = CbsSessionManager::instance().ApplyNew();
            // init corresponding session
            if (CbsSessionManager::GetCurrentSource() == CbsSessionManager::StackSource::Online) {
                winrt::check_hresult(m_pSess->Initialize(CbsSessionOptionNone, L"UFCase::SysInfoProvider", nullptr, nullptr));
            } else {
                winrt::check_hresult(m_pSess->Initialize(
                    CbsSessionOptionNone, L"UFCase::SysInfoProvider",
                    CbsSessionManager::GetCurrentBootdrive().c_str(),
                    CbsSessionManager::GetCurrentWindir().c_str()
                ));
            }
        }
    }
    void SysInfoStaticProvider::TryOpenProductPackage()
    {
        TryInitCbsSession();

        winrt::com_ptr<ICbsIdentity> pId;
        winrt::check_hresult(m_pSess->CreateCbsIdentity(pId.put()));
        winrt::check_hresult(pId->LoadFromStringId(L"@Product"));

        winrt::com_ptr<ICbsPackage> pRawPkg;
        m_pSess->OpenPackage(0, pId.get(), nullptr, pRawPkg.put());
        auto pProdPkg = pRawPkg.as<ICbsPackage>();

        unique_malloc_wstring strId;
        pProdPkg->GetProperty(CbsPackagePropertyIdentityString, wil::out_param(strId));

        m_strProdPkgId = strId.get();
    }
    winrt::hstring SysInfoStaticProvider::Manufacturer()
    {
        // HKLM\HARDWARE\DESCRIPTION\System\BIOS\SystemManufacturer
        wil::unique_hkey hkey;
        winrt::check_win32(RegOpenKey(HKEY_LOCAL_MACHINE,
            L"HARDWARE\\DESCRIPTION\\System\\BIOS", wil::out_param(hkey)));
        DWORD dwType, dwCnt{};
        winrt::check_win32(RegQueryValueEx(hkey.get(), L"SystemManufacturer", 0, &dwType, nullptr, &dwCnt));
        std::vector<BYTE> buffer; buffer.assign(dwCnt, 0);
        winrt::check_win32(RegQueryValueEx(hkey.get(), L"SystemManufacturer", 0, &dwType, buffer.data(), &dwCnt));
        return reinterpret_cast<LPWSTR>(buffer.data());
    }
    hstring SysInfoStaticProvider::CPUArchitecture()
    {
        SYSTEM_INFO sysinfo;
        // ignore WoW64 simulation
        GetNativeSystemInfo(&sysinfo);
        switch (sysinfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_INTEL            : return L"intel";
        case PROCESSOR_ARCHITECTURE_MIPS             : return L"mips";
        case PROCESSOR_ARCHITECTURE_ALPHA            : return L"alpha";
        case PROCESSOR_ARCHITECTURE_PPC              : return L"ppc";
        case PROCESSOR_ARCHITECTURE_SHX              : return L"shx";
        case PROCESSOR_ARCHITECTURE_ARM              : return L"arm";
        case PROCESSOR_ARCHITECTURE_IA64             : return L"ia64";
        case PROCESSOR_ARCHITECTURE_ALPHA64          : return L"alpha64";
        case PROCESSOR_ARCHITECTURE_MSIL             : return L"msil";
        case PROCESSOR_ARCHITECTURE_AMD64            : return L"amd64";
        case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64    : return L"ia32_win64";
        case PROCESSOR_ARCHITECTURE_NEUTRAL          : return L"neutral";
        case PROCESSOR_ARCHITECTURE_ARM64            : return L"arm64";
        case PROCESSOR_ARCHITECTURE_ARM32_ON_WIN64   : return L"arm32_win64";
        case PROCESSOR_ARCHITECTURE_IA32_ON_ARM64    : return L"ia32_arm64";
        default: return L"(null)";
        }
    }
    winrt::hstring SysInfoStaticProvider::CPUDisplayName()
    {
        // HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0\ProcessorNameString
        wil::unique_hkey hkey;
        winrt::check_win32(RegOpenKey(HKEY_LOCAL_MACHINE,
            L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", wil::out_param(hkey)));
        DWORD dwType, dwCnt{};
        winrt::check_win32(RegQueryValueEx(hkey.get(), L"ProcessorNameString", 0, &dwType, nullptr, &dwCnt));
        std::vector<BYTE> buffer; buffer.assign(dwCnt, 0);
        winrt::check_win32(RegQueryValueEx(hkey.get(), L"ProcessorNameString", 0, &dwType, buffer.data(), &dwCnt));
        return reinterpret_cast<LPWSTR>(buffer.data());
    }
}
