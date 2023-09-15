#include "pch.h"

#include <wrl/module.h>
#include <wil/resource.h>

#include <filesystem>
#include <winrt/UFCase.Isolation.h>

namespace winrt
{
    using namespace Windows::Foundation;
}

CoCreatableClassWrlCreatorMapInclude(HostManagerSingleton);

// Holds the wwinmain open until COM tells us there are no more server connections
wil::unique_event _comServerExitEvent;

// Routine Description:
// - Called back when COM says there is nothing left for our server to do and we can tear down.
static void _releaseNotifier() noexcept
{
    _comServerExitEvent.SetEvent();
}

winrt::fire_and_forget StartHosts()
{

    WCHAR szPath[MAX_PATH];
    ::GetModuleFileName(::GetModuleHandle(NULL), szPath, MAX_PATH);

    winrt::check_win32(GetLastError());

    std::filesystem::path mainExePath{szPath};
    auto hostExeDir = mainExePath.parent_path().parent_path() / L"UFCase.Host";
    auto hostExePath = hostExeDir / L"UFCase.Host.exe";

    // co_await winrt::resume_background();

    for (int i = 0; i < 4; i++)
    {
        auto client_id = winrt::to_hstring(winrt::GuidHelper::CreateNewGuid());
        auto bootdrive = L"C:";

        STARTUPINFO st_info{
            .cb = sizeof(st_info),
        };
        PROCESS_INFORMATION proc_info{};
        if (!CreateProcess(
                hostExePath.c_str(),
                const_cast<LPWSTR>(winrt::format(L"{} {}", client_id, bootdrive).c_str()), NULL,
                NULL, FALSE, NULL, NULL, hostExeDir.c_str(), &st_info, &proc_info))
        {
            winrt::check_hresult(HRESULT_FROM_WIN32(GetLastError()));
        }
    }
    co_return;
}

int main()
{
    winrt::init_apartment();

    {
        winrt::com_ptr<IGlobalOptions> globalOptions;
        winrt::check_hresult(CoCreateInstance(CLSID_GlobalOptions, nullptr, CLSCTX_INPROC,
                                              IID_PPV_ARGS(&globalOptions)));
        winrt::check_hresult(globalOptions->Set(COMGLB_RO_SETTINGS, COMGLB_FAST_RUNDOWN));
    }

    _comServerExitEvent.create();
#pragma warning(disable : 4324)
    auto &module = ::Microsoft::WRL::Module<::Microsoft::WRL::ModuleType::OutOfProc>::Create(
        &_releaseNotifier);
    try
    {
        RETURN_IF_FAILED(module.RegisterObjects());
        StartHosts();
        _comServerExitEvent.wait();
        RETURN_IF_FAILED(module.UnregisterObjects());
    }
    CATCH_RETURN()

    return 0;
}
