﻿#include "pch.h"
#include "StoreModel.h"
#if __has_include("StoreModel.g.cpp")
#include "StoreModel.g.cpp"
#endif

#include "ComponentModel.h"
#include "GeneratorIterable.h"

#include "Utils/ComUtil.h"
#include "Utils/StackUtil.h"
#include "ServicingApi/Isolation.h"
#include "ServicingApi/SSShimApi.h"

#include <wil/resource.h>
#include <wil/win32_helpers.h>
#include <wil/stl.h>

#include <filesystem>

namespace winrt::UFCase::Isolation::implementation
{
    namespace WcpUtil
    {
        WcpGuard::WcpGuard(com_ptr<IMalloc> pMalloc, hstring windir)
        {
            winrt::check_pointer(LoadLibrary(FindSStackDll(windir, WCP_DLL_FILENAME).c_str()));

            auto pfnWcpInitialize =
                GetFunction<PWCP_INITIALIZE_FUNCTION>(WCP_DLL_FILENAME, "WcpInitialize");
            winrt::check_hresult(pfnWcpInitialize(&pCookie));

            auto pfnSetIsolationIMalloc = GetFunction<PSET_ISOLATION_IMALLOC_FUNCTION>(
                WCP_DLL_FILENAME, "SetIsolationIMalloc");
            winrt::check_hresult(pfnSetIsolationIMalloc(pMalloc.get()));
        }

        WcpGuard::~WcpGuard()
        {
            auto pfnWcpShutdown =
                GetFunction<PWCP_SHUTDOWN_FUNCTION>(WCP_DLL_FILENAME, "WcpShutdown");
            winrt::check_hresult(pfnWcpShutdown(pCookie));

            FreeLibrary(winrt::check_pointer(GetModuleHandle(WCP_DLL_FILENAME)));
        }

        std::shared_ptr<WcpGuard> WcpGuard::GetStrong(hstring windir)
        {
            static std::weak_ptr<WcpGuard> weak;

            if (auto strong = weak.lock(); strong)
                return strong;

            // no available, renew
            com_ptr<IMalloc> pMalloc;
            check_hresult(::CoGetMalloc(1, pMalloc.put()));
            auto strong = std::make_shared<WcpGuard>(pMalloc, windir);
            weak = strong;
            return strong;
        }

        std::pair<com_ptr<IIdentityAuthority>, com_ptr<IAppIdAuthority>> GetStoreAuthorities()
        {
            winrt::com_ptr<IIdentityAuthority> pIdentAuth;
            const auto fnGetIdentityAuthority = GetFunction<PGET_IDENTITY_AUTHORITY_FUNCTION>(
                WCP_DLL_FILENAME, "GetIdentityAuthority");
            winrt::check_hresult(fnGetIdentityAuthority(pIdentAuth.put()));

            winrt::com_ptr<IAppIdAuthority> pAppIdAuth;
            const auto fnGetAppIdAuthority =
                GetFunction<PGET_APPID_AUTHORITY_FUNCTION>(WCP_DLL_FILENAME, "GetAppIdAuthority");
            winrt::check_hresult(fnGetAppIdAuthority(pAppIdAuth.put()));
            return {pIdentAuth, pAppIdAuth};
        }

        std::pair<com_ptr<IStore2>, com_ptr<ICSIStore>> LoadOnlineStores()
        {
            com_ptr<IStore2> pStore;
            com_ptr<ICSIStore> pCSIStore;

            auto pfnGetSystemStore =
                GetFunction<PGET_SYSTEM_STORE_FUNCTION>(WCP_DLL_FILENAME, "GetSystemStore");

            winrt::check_hresult(
                pfnGetSystemStore(0, __uuidof(IStore), (::IUnknown **)pStore.put()));
            winrt::check_hresult(
                pfnGetSystemStore(0, __uuidof(ICSIStore), (::IUnknown **)pCSIStore.put()));

            return {pStore, pCSIStore};
        }

        std::pair<com_ptr<IStore2>, com_ptr<ICSIStore>> LoadOfflineStores(
            std::filesystem::path windir)
        {
            using namespace std::literals::string_literals;

            com_ptr<IStore2> pStore;
            com_ptr<ICSIStore> pCSIStore;

            auto pfnOpenExistingOfflineStore = GetFunction<POPEN_EXISTING_OFFLINE_STORE_FUNCTION>(
                WCP_DLL_FILENAME, "OpenExistingOfflineStore");

            const std::wstring OFFLINE_HIVE_PREFIX = L"{bf1a281b-ad7b-4476-ac95-f47682990ce7}"s;

            auto fix_offline_hive_key_name = [](std::wstring &str) {
                // escape L'\\' for reg key path
                for (auto &c : str)
                {
                    if (c == L'\\')
                        c = L'/';
                }
            };

            auto bootdrive = windir.parent_path();
            auto reg_root = windir / L"System32" / L"config";
            const auto reg_hive_names = {
                L"SOFTWARE"s, L"SYSTEM"s, L"SECURITY"s, L"SAM"s, L"COMPONENTS"s, L"DEFAULT"s,
            };

            std::unordered_map<std::wstring, std::wstring> hive_offregs;

            for (auto &hive_name : reg_hive_names)
            {
                auto hive_path = reg_root / hive_name;
                auto offreg = OFFLINE_HIVE_PREFIX + hive_path.wstring();
                fix_offline_hive_key_name(offreg);
                hive_offregs[hive_name] = offreg;

                wil::unique_hkey hive;
                winrt::check_nt(RegOpenKey(HKEY_LOCAL_MACHINE, offreg.c_str(), hive.put()));

                // Get the path of default user profile from SOFTWARE
                if (hive_name == L"SOFTWARE")
                {
                    wil::unique_hkey hkProfileList;
                    winrt::check_nt(RegOpenKey(
                        hive.get(), LR"(Microsoft\Windows NT\CurrentVersion\ProfileList)",
                        hkProfileList.put()));
                    DWORD dwType = REG_SZ, dwLen = MAX_PATH;
                    wchar_t szProfileDir[MAX_PATH]{};
                    winrt::check_nt(RegQueryValueEx(hkProfileList.get(), L"ProfilesDirectory",
                                                    nullptr, &dwType, (LPBYTE)szProfileDir,
                                                    &dwLen));
                    wil::zwstring_view profile_dir{szProfileDir};
                    constexpr wil::zwstring_view SYSTEM_DRIVE_ENV = L"%SystemDrive%\\";
                    if (!profile_dir.starts_with(SYSTEM_DRIVE_ENV))
                    {
                        throw_hresult(E_INVALIDARG);
                    }

                    profile_dir.remove_prefix(SYSTEM_DRIVE_ENV.size());
                    auto ntuser_hive_path =
                        bootdrive / profile_dir.c_str() / L"Default" / L"ntuser.dat";
                    auto ntuser_offreg = OFFLINE_HIVE_PREFIX + ntuser_hive_path.wstring();
                    fix_offline_hive_key_name(ntuser_offreg);

                    wil::unique_hkey ntuser_hive;
                    winrt::check_nt(
                        RegOpenKey(HKEY_LOCAL_MACHINE, ntuser_offreg.c_str(), ntuser_hive.put()));

                    hive_offregs[L"NTUSER"s] = ntuser_offreg;
                }
            }

            {
                auto hive_path = windir / L"system32/smi/store/Machine/schema.dat";
                auto offreg = OFFLINE_HIVE_PREFIX + hive_path.wstring();
                fix_offline_hive_key_name(offreg);
                wil::unique_hkey hive;
                winrt::check_nt(RegOpenKey(HKEY_LOCAL_MACHINE, offreg.c_str(), hive.put()));
                hive_offregs[L"SCHEMA"s] = offreg;
            }

            for (auto &&[_, value] : hive_offregs)
            {
                value = L"HKEY_LOCAL_MACHINE\\" + value;
            }

            SYSTEM_INFO info;
            GetSystemInfo(&info);

            OFFLINE_STORE_CREATION_PARAMETERS params{
                .cbSize = sizeof(params),
                .dwFlags = 0,
                .pszHostSystemDrivePath = bootdrive.c_str(),
                .pszHostWindowsDirectoryPath = windir.c_str(),
                .pszTargetWindowsDirectoryPath = windir.c_str(),
                .pszHostRegistryMachineSoftwarePath = hive_offregs[L"SOFTWARE"s].c_str(),
                .pszHostRegistryMachineSystemPath = hive_offregs[L"SYSTEM"s].c_str(),
                .pszHostRegistryMachineSecurityPath = hive_offregs[L"SECURITY"s].c_str(),
                .pszHostRegistryMachineSAMPath = hive_offregs[L"SAM"s].c_str(),
                .pszHostRegistryMachineComponentsPath = hive_offregs[L"COMPONENTS"s].c_str(),
                .pszHostRegistryUserDotDefaultPath = hive_offregs[L"DEFAULT"s].c_str(),
                .pszHostRegistryDefaultUserPath = hive_offregs[L"NTUSER"s].c_str(),
                .ulProcessorArchitecture = info.wProcessorArchitecture,
                .pszHostRegistryMachineOfflineSchemaPath = hive_offregs[L"SCHEMA"s].c_str(),
            };

            DWORD dwDisp{};
            check_hresult(pfnOpenExistingOfflineStore(0, &params, __uuidof(IStore2),
                                                      (::IUnknown **)pStore.put(), &dwDisp));
            check_hresult(pfnOpenExistingOfflineStore(0, &params, __uuidof(ICSIStore),
                                                      (::IUnknown **)pCSIStore.put(), &dwDisp));

            return {pStore, pCSIStore};
        }

    } // namespace WcpUtil

    void StoreModel::Initialize()
    {
        wcp_guard = WcpUtil::WcpGuard::GetStrong(m_image.WinDir());

        std::tie(m_ident_auth, m_appid_auth) = WcpUtil::GetStoreAuthorities();

        if (m_image.Type() == ImageType::Online)
        {
            std::tie(m_sxs_store, m_csi_store) = WcpUtil::LoadOnlineStores();
        }
        else
        {
            std::tie(m_sxs_store, m_csi_store) =
                WcpUtil::LoadOfflineStores(m_image.WinDir().c_str());
        }
    }

    Isolation::ComponentModel StoreModel::OpenComponent(hstring id)
    {
        com_ptr<IDefinitionIdentity> asm_id;
        check_hresult(m_ident_auth->TextToDefinition(0, id.c_str(), asm_id.put()));
        return OpenComponent(asm_id);
    }

    Isolation::ComponentModel StoreModel::OpenComponent(com_ptr<IDefinitionIdentity> pDefIdent)
    {
        ULONGLONG hashkey{};
        check_hresult(m_ident_auth->HashDefinition(0, pDefIdent.get(), &hashkey));

        return make<implementation::ComponentModel>(*get_strong(), pDefIdent);
    }

    Generator<Isolation::ComponentModel> StoreModel::CreateModelsFromIEnumASM(
        com_ptr<IEnumSTORE_ASSEMBLY> pEnum)
    {

        for (auto &store_asm : GetIEnumStructVector<STORE_ASSEMBLY, SIZE_T>(pEnum))
        {
            com_ptr<IDefinitionIdentity> asm_id;
            asm_id.attach(store_asm.pIDefinitionIdentity);

            if (auto p = OpenComponent(asm_id))
                co_yield p;
        }

        co_return;
    }

    Windows::Foundation::Collections::IIterable<Windows::Foundation::IInspectable> StoreModel::
        GetComponentCollection()
    {
        winrt::com_ptr<::IUnknown> pRawAssemblies;
        check_hresult(m_sxs_store->EnumAssemblies(0, NULL, __uuidof(IEnumSTORE_ASSEMBLY),
                                                  pRawAssemblies.put()));

        auto g = std::make_shared<Generator<Isolation::ComponentModel>>(
            CreateModelsFromIEnumASM(pRawAssemblies.as<IEnumSTORE_ASSEMBLY>()));
        return make<UFCase::Host::implementation::GeneratorIterable>(g);
    }

    Windows::Foundation::Collections::IIterable<Windows::Foundation::IInspectable> StoreModel::
        GetComponentCollection(hstring ref_id)
    {
        com_ptr<IReferenceIdentity> asm_id;
        check_hresult(m_ident_auth->TextToReference(0, ref_id.c_str(), asm_id.put()));

        winrt::com_ptr<::IUnknown> pRawAssemblies;
        check_hresult(m_sxs_store->EnumAssemblies(0, asm_id.get(), __uuidof(IEnumSTORE_ASSEMBLY),
                                                  pRawAssemblies.put()));

        auto g = std::make_shared<Generator<Isolation::ComponentModel>>(
            CreateModelsFromIEnumASM(pRawAssemblies.as<IEnumSTORE_ASSEMBLY>()));
        return make<UFCase::Host::implementation::GeneratorIterable>(g);
    }

} // namespace winrt::UFCase::Isolation::implementation
