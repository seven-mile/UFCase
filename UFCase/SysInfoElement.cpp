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
			// init online session
			winrt::check_hresult(pSess->Initialize(CbsSessionOptionNone, L"UFCase", nullptr, nullptr));

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
	}
	double SysInfoRealtimeElement::CPUUtilization()
	{
		auto info = SystemDiagnosticInfo::GetForCurrentSystem();
		auto rep = info.CpuUsage().GetReport();

		return 1.0 - (rep.IdleTime() / (rep.KernelTime() + rep.IdleTime() + rep.UserTime()));
	}
	uint64_t SysInfoRealtimeElement::UsedMemoryInBytes()
	{
		auto info = SystemDiagnosticInfo::GetForCurrentSystem();
		auto rep = info.MemoryUsage().GetReport();

		return rep.CommittedSizeInBytes() + rep.TotalPhysicalSizeInBytes() - rep.AvailableSizeInBytes();
	}
	uint64_t SysInfoRealtimeElement::AllMemoryInBytes()
	{
		auto info = SystemDiagnosticInfo::GetForCurrentSystem();
		auto rep = info.MemoryUsage().GetReport();

		return rep.CommittedSizeInBytes() + rep.TotalPhysicalSizeInBytes();
	}
}
