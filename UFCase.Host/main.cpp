#include "pch.h"

#include "Host.h"

#include <shellapi.h>

#include <chrono>
#include <filesystem>

namespace winrt
{
    using namespace Windows::Foundation;
} // namespace winrt

// {EF5B65F8-2568-46BF-9436-65D304ADF719}
static const GUID CLSID_HostManagerSingleton = {
    0xef5b65f8, 0x2568, 0x46bf, {0x94, 0x36, 0x65, 0xd3, 0x4, 0xad, 0xf7, 0x19}};

inline void EnsureBackupRestorePrivilege()
{
    wil::unique_handle hToken;
    winrt::check_bool(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
                                       wil::out_param(hToken)));

    TOKEN_PRIVILEGES tp{};
    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    winrt::check_bool(LookupPrivilegeValue(nullptr, SE_BACKUP_NAME, &tp.Privileges[0].Luid));

    winrt::check_bool(
        AdjustTokenPrivileges(hToken.get(), FALSE, &tp, sizeof(tp), nullptr, nullptr));

    winrt::check_bool(LookupPrivilegeValue(nullptr, SE_RESTORE_NAME, &tp.Privileges[0].Luid));

    winrt::check_bool(
        AdjustTokenPrivileges(hToken.get(), FALSE, &tp, sizeof(tp), nullptr, nullptr));
}

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
// int main()
{
    winrt::init_apartment();

    auto cmd_line = GetCommandLine();
    int argc{-1};
    auto argv = CommandLineToArgvW(cmd_line, &argc);

    if (argc != 2)
    {
        return E_INVALIDARG;
    }

    winrt::guid client_id{};
    try
    {
        client_id = winrt::guid{argv[0]};
    }
    catch (std::exception const &)
    {
        return E_INVALIDARG;
    }

    std::filesystem::path bootdrive{argv[1]};
    if (!std::filesystem::exists(bootdrive))
    {
        return E_INVALIDARG;
    }

    auto host_mgr_singleton =
        winrt::create_instance<winrt::UFCase::Isolation::HostManagerSingleton>(
            CLSID_HostManagerSingleton, CLSCTX_LOCAL_SERVER);
    auto host_mgr = host_mgr_singleton.Current();

    EnsureBackupRestorePrivilege();

    auto host = winrt::make<winrt::UFCase::Isolation::implementation::Host>(client_id, bootdrive);

    host_mgr.RegisterHost(host);

    // process messages, for long run
    MSG msg{};
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
