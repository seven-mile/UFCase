#include "pch.h"
#include "ImageModel.h"
#if __has_include("ImageModel.g.cpp")
#include "ImageModel.g.cpp"
#endif

#include "SessionModel.h"
#include "StoreModel.h"

#include "ServicingApi/SSShimApi.h"

#include "Utils/PathUtil.h"

#include <ranges>
#include <wil/stl.h>

namespace winrt::UFCase::Isolation::implementation
{

    void ImageModel::ConstructOnlineRegistryHives()
    {
        using namespace std::string_literals;

        m_hive_offregs[L"SOFTWARE"s] = L"HKEY_LOCAL_MACHINE\\SOFTWARE"s;
        m_hive_offregs[L"SYSTEM"s] = L"HKEY_LOCAL_MACHINE\\SYSTEM"s;
        m_hive_offregs[L"SECURITY"s] = L"HKEY_LOCAL_MACHINE\\SECURITY"s;
        m_hive_offregs[L"SAM"s] = L"HKEY_LOCAL_MACHINE\\SAM"s;
        m_hive_offregs[L"COMPONENTS"s] = L"HKEY_LOCAL_MACHINE\\COMPONENTS"s;
        m_hive_offregs[L"DEFAULT"s] = L"HKEY_USERS\\.DEFAULT"s;
        // not loaded defaultly
        // m_hive_offregs[L"NTUSER"s] = L""s;
        m_hive_offregs[L"SCHEMA"s] = L"HKEY_LOCAL_MACHINE\\SCHEMA"s;
    }

    void ImageModel::ConstructOfflineRegistryHives()
    {
        using namespace std::string_literals;
        std::filesystem::path windir = m_bootdrive / L"Windows";

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

        for (auto &hive_name : reg_hive_names)
        {
            auto hive_path = reg_root / hive_name;
            auto offreg = OFFLINE_HIVE_PREFIX + hive_path.wstring();
            fix_offline_hive_key_name(offreg);
            m_hive_offregs[hive_name] = offreg;

            wil::unique_hkey hive;
            winrt::check_nt(RegOpenKey(HKEY_LOCAL_MACHINE, offreg.c_str(), hive.put()));

            // Get the path of default user profile from SOFTWARE
            if (hive_name == L"SOFTWARE")
            {
                wil::unique_hkey hkProfileList;
                winrt::check_nt(RegOpenKey(hive.get(),
                                           LR"(Microsoft\Windows NT\CurrentVersion\ProfileList)",
                                           hkProfileList.put()));
                DWORD dwType = REG_SZ, dwLen = MAX_PATH;
                wchar_t szProfileDir[MAX_PATH]{};
                winrt::check_nt(RegQueryValueEx(hkProfileList.get(), L"ProfilesDirectory", nullptr,
                                                &dwType, (LPBYTE)szProfileDir, &dwLen));
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

                m_hive_offregs[L"NTUSER"s] = ntuser_offreg;
            }
        }

        {
            auto hive_path = windir / L"system32/smi/store/Machine/schema.dat";
            auto offreg = OFFLINE_HIVE_PREFIX + hive_path.wstring();
            fix_offline_hive_key_name(offreg);
            wil::unique_hkey hive;
            winrt::check_nt(RegOpenKey(HKEY_LOCAL_MACHINE, offreg.c_str(), hive.put()));
            m_hive_offregs[L"SCHEMA"s] = offreg;
        }

        for (auto &&[_, value] : m_hive_offregs)
        {
            value = L"HKEY_LOCAL_MACHINE\\" + value;
        }
    }

    void ImageModel::Initialize()
    {
        this->basic_sess = make<implementation::SessionModel>(*get_strong());
        this->sxs_store = nullptr;
        // ensure hive loaded
        try
        {
            basic_sess.PerformOperation(CbsOperationType::InitICSIStore);
        }
        catch (hresult_no_interface const &)
        {
            // use package loading instead, which is slower
            [[maybe_unused]] auto _ = basic_sess.ProductPackage();
        }

        if (Type() == ImageType::Online)
        {
            ConstructOnlineRegistryHives();
        }
        else
        {
            ConstructOfflineRegistryHives();
        }
    }

    Isolation::SessionModel ImageModel::OpenSession(DWORD option)
    {
        return make<implementation::SessionModel>(*get_strong(), option);
    }

    Isolation::SessionModel ImageModel::BasicSession()
    {
        if (basic_sess)
        {
            return basic_sess;
        }
        else
        {
            return basic_sess = make<implementation::SessionModel>(*get_strong());
        }
    }

    Isolation::StoreModel ImageModel::SxsStore()
    {
        if (sxs_store)
        {
            return sxs_store;
        }
        else
        {
            return sxs_store = make<implementation::StoreModel>(*get_strong());
        }
    }

    hstring ImageModel::Bootdrive()
    {
        return m_bootdrive.c_str();
    }

    hstring ImageModel::WinDir()
    {
        return (m_bootdrive / L"Windows").c_str();
    }

    hstring ImageModel::GetRegistryHive(hstring hive_id)
    {
        if (auto it = m_hive_offregs.find(hive_id.c_str()); it != m_hive_offregs.end())
        {
            return it->second.c_str();
        }
        else
        {
            return L"";
        }
    }

    ImageType ImageModel::Type()
    {
        auto online_drive = GetOnlineBootdrive();
        return m_bootdrive == online_drive ? ImageType::Online : ImageType::Offline;
    }

    hstring ImageModel::Edition()
    {
        std::wstring name = BasicSession().ProductPackage().ProductName().c_str();
        assert(name.ends_with(L"Edition"));
        const auto idx = name.find_last_of(L'-') + 1;
        constexpr int suffix_len = 7;
        return name.substr(idx, name.size() - idx - suffix_len).c_str();
    }

    bool ImageModel::IsWinPE()
    {
        if (this->Type() == ImageType::Online)
        {
            wil::unique_hkey hkey;
            auto lst =
                ::RegOpenKey(HKEY_LOCAL_MACHINE, L"Microsoft\\Windows NT\\CurrentVersion\\WinPE",
                             wil::out_param(hkey));
            SetLastError(0);

            if (lst == ERROR_SUCCESS)
            {
                return true;
            }
            else if (lst == ERROR_FILE_NOT_FOUND)
            {
                return false;
            }
            else
            {
                throw winrt::hresult_error{HRESULT_FROM_WIN32(lst)};
            }
        }
        else
        {
            // todo: use offline reg
            return false;
        }
    }

} // namespace winrt::UFCase::Isolation::implementation
