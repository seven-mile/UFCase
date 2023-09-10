#pragma once

#include <ShlObj_core.h>

#include <wil/resource.h>
#include <wil/win32_helpers.h>

#include <filesystem>

namespace winrt::UFCase
{

    inline std::filesystem::path GetOnlineKnownFolder(guid folder_id)
    {
        static std::unordered_map<guid, std::filesystem::path> mem_known_folder;
        if (auto it = mem_known_folder.find(folder_id); it != mem_known_folder.end())
            return it->second;

        wil::unique_cotaskmem_string path_tmp;

        auto get_folder_path_ret = SHGetKnownFolderPath(folder_id, 0, nullptr, path_tmp.put());

        if (get_folder_path_ret != S_OK)
        {
            throw_hresult(HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND));
        }
        std::wstring copied_path = path_tmp.get();
        return mem_known_folder[folder_id] = copied_path;
    }

    inline std::filesystem::path GetOnlineWindir()
    {
        return GetOnlineKnownFolder(FOLDERID_Windows);
    }

    inline std::filesystem::path GetOnlineBootdrive()
    {
        return GetOnlineWindir().parent_path();
    }

    inline std::filesystem::path GetOnlineSystem32()
    {
        return GetOnlineWindir() / L"System32";
    }

    inline std::filesystem::path GetOnlineHomeDir()
    {
        return GetOnlineKnownFolder(FOLDERID_Profile);
    }

    inline std::filesystem::path GetOnlineTempDir()
    {
        return GetOnlineKnownFolder(FOLDERID_LocalAppData) / L"Temp";
    }

    inline std::filesystem::path GetOnlineRoamingAppDataDir()
    {
        return GetOnlineKnownFolder(FOLDERID_RoamingAppData);
    }

} // namespace winrt::UFCase
