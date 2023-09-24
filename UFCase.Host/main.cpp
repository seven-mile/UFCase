#include "pch.h"

#include "Host.h"

#include <shellapi.h>

#include <chrono>
#include <filesystem>

#ifdef _DEBUG
#include <winrt/UFCase.Host.Manifest.h>
#include "Utils/StreamUtil.h"
#endif

#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")

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

#ifdef _DEBUG
void TestManifestWinRT()
{
    winrt::com_ptr<::IStream> stream;
    winrt::check_hresult(SHCreateStreamOnFileEx(
        LR"(C:\Users\7mile\source\repos\UFCase\docs\manifests\comp_dependency.xml)", STGM_READ,
        FILE_ATTRIBUTE_NORMAL, FALSE, nullptr, stream.put()));

    // auto assembly = winrt::UFCase::Host::Manifest::ManifestParser::ParseFromPath(
    //     LR"(C:\Users\7mile\source\repos\UFCase\docs\manifests\comp_dependency.xml)");

    auto straem_wrapper =
        winrt::make<winrt::UFCase::Host::Manifest::implementation::ComStreamWrapper>(stream);

    auto assembly = winrt::UFCase::Host::Manifest::ManifestParser::ParseFromStream(straem_wrapper);

    OutputDebugString(winrt::format(L"{} v{}\n", assembly.Identity().Name(), assembly.Version().Value()).c_str());

    for (auto &file : assembly.Files())
    {
        OutputDebugString(winrt::format(L"file: [{}] {} {}\n", file.DestinationName(), file.Hash(),
                                        file.SizeInByte())
                              .c_str());
    }

    for (auto &key : assembly.Keys())
    {
        OutputDebugString(
            winrt::format(L"key: [{}] {} values\n", key.Name(), key.Values().size()).c_str());

        for (auto &value : key.Values())
        {
            OutputDebugString(
                winrt::format(L"key value: [{}] {} {}\n", value.Name(), (int)value.Type(),
                              winrt::unbox_value_or<winrt::hstring>(value.Data(), L"unsupported"))
                    .c_str());
        }
    }

    for (auto &dep : assembly.Dependencies())
    {
        OutputDebugString(
            winrt::format(L"dep: [{}] {}\n", dep.Identity().KeyForm(), dep.Type()).c_str());
    }
}
#endif

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
