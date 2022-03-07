#pragma once

#include <filesystem>
#include <ShlObj_core.h>

namespace winrt::UFCase {

    inline std::filesystem::path GetOnlineWindir()
    {
        static std::filesystem::path pathBd{};
        if (!pathBd.empty()) return pathBd;

        { // first call
            static wchar_t pathBuffer[MAX_PATH]{};
            if (!GetWindowsDirectory(pathBuffer, MAX_PATH))
                winrt::throw_last_error();
            pathBd = pathBuffer;
        }
        return pathBd;
    }
    
    inline std::filesystem::path GetOnlineBootdrive()
    {
        return GetOnlineWindir().parent_path();
    }

    inline std::filesystem::path GetOnlineSystem32()
    {
        return GetOnlineWindir() / L"System32";
    }

    inline std::filesystem::path GetOnlineKnownFolder(guid folder_id) {
        static std::unordered_map<guid, std::filesystem::path> mem_known_folder;
        if (auto it = mem_known_folder.find(folder_id); it != mem_known_folder.end())
            return it->second;

        PWSTR path_tmp;
        auto get_folder_path_ret = SHGetKnownFolderPath(folder_id, 0, nullptr, &path_tmp);

        if (get_folder_path_ret != S_OK) {
            CoTaskMemFree(path_tmp);
            throw_hresult(HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND));
        }
        std::wstring copied_path = path_tmp;
        CoTaskMemFree(path_tmp);
        return mem_known_folder[folder_id] = copied_path;
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

}
