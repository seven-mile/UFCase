﻿#include "pch.h"

#include <wrl/module.h>
#include <wil/resource.h>

#include <filesystem>
#include <winrt/UFCase.Isolation.h>

#include <WindowsAppSDK-VersionInfo.h>
#include <MddBootstrap.h>

namespace MddBootstrap
{
    using namespace ::Microsoft::Windows::ApplicationModel::DynamicDependency::Bootstrap;
}

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
    wprintf(L"No host object left. Test completed. Exiting...\n");
    _comServerExitEvent.SetEvent();
}

static BOOL CreateProcessInJob(HANDLE hJob, LPCTSTR lpApplicationName, LPTSTR lpCommandLine,
                               LPSECURITY_ATTRIBUTES lpProcessAttributes,
                               LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles,
                               DWORD dwCreationFlags, LPVOID lpEnvironment,
                               LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo,
                               LPPROCESS_INFORMATION ppi)
{
    BOOL fRc = CreateProcess(
        lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
        dwCreationFlags | CREATE_SUSPENDED, lpEnvironment, lpCurrentDirectory, lpStartupInfo, ppi);
    if (fRc)
    {
        fRc = AssignProcessToJobObject(hJob, ppi->hProcess);
        if (fRc && !(dwCreationFlags & CREATE_SUSPENDED))
        {
            fRc = ResumeThread(ppi->hThread) != (DWORD)-1;
        }
        if (!fRc)
        {
            TerminateProcess(ppi->hProcess, 0);
            CloseHandle(ppi->hProcess);
            CloseHandle(ppi->hThread);
            ppi->hProcess = ppi->hThread = nullptr;
        }
    }
    return fRc;
}

winrt::fire_and_forget StartHosts()
{

    WCHAR szPath[MAX_PATH];
    ::GetModuleFileName(::GetModuleHandle(NULL), szPath, MAX_PATH);

    winrt::check_win32(GetLastError());

    std::filesystem::path mainExePath{szPath};
    auto hostExeDir = mainExePath.parent_path();
    auto hostExePath = hostExeDir / L"UFCase.Host.exe";

    // co_await winrt::resume_background();

    constexpr LPCWSTR bootdrives[] = {
        L"C:\\",
        // L"F:\\",
    };

    auto host_job = CreateJobObject(nullptr, nullptr);
    JOBOBJECT_EXTENDED_LIMIT_INFORMATION info = {};
    info.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
    winrt::check_bool(
        SetInformationJobObject(host_job, JobObjectExtendedLimitInformation, &info, sizeof(info)));

    for (auto bootdrive : bootdrives)
    {
        auto client_id = winrt::to_hstring(winrt::GuidHelper::CreateNewGuid());

        STARTUPINFO st_info{
            .cb = sizeof(st_info),
        };
        PROCESS_INFORMATION proc_info{};
        if (!CreateProcessInJob(host_job, hostExePath.c_str(),
                                const_cast<LPWSTR>(winrt::format(L"{} {} {}", hostExePath.wstring(),
                                                                 client_id, bootdrive)
                                                       .c_str()),
                                NULL, NULL, FALSE, NULL, NULL, hostExeDir.c_str(), &st_info,
                                &proc_info))
        {
            if (proc_info.hProcess)
            {
                CloseHandle(proc_info.hProcess);
            }
            if (proc_info.hThread)
            {
                CloseHandle(proc_info.hThread);
            }

            winrt::check_hresult(HRESULT_FROM_WIN32(GetLastError()));
        }
    }
    co_return;
}


// Print all guid of generic interfaces. This is used in the setup of proxy stubs.
void PrintGenericInterfaces() {
    winrt::guid guids[] = {
        winrt::guid_of<winrt::Windows::Foundation::Collections::IIterable<winrt::UFCase::Isolation::ComponentFileModel>>(),
        winrt::guid_of<winrt::Windows::Foundation::Collections::IIterable<winrt::UFCase::Isolation::FeatureModel>>(),
        winrt::guid_of<winrt::Windows::Foundation::Collections::IIterable<winrt::UFCase::Isolation::PackageModel>>(),
        winrt::guid_of<winrt::Windows::Foundation::Collections::IIterator<winrt::UFCase::Isolation::ComponentFileModel>>(),
        winrt::guid_of<winrt::Windows::Foundation::Collections::IIterator<winrt::UFCase::Isolation::FeatureModel>>(),
        winrt::guid_of<winrt::Windows::Foundation::Collections::IIterator<winrt::UFCase::Isolation::PackageModel>>(),
        winrt::guid_of<winrt::Windows::Foundation::Collections::IVectorView<winrt::UFCase::Isolation::PackageModel>>(),
        winrt::guid_of<winrt::Windows::Foundation::Collections::IVector<winrt::UFCase::Isolation::PackageModel>>(),
    };

    for (auto guid : guids)
    {
        wprintf(L"%s\n", winrt::to_hstring(guid).c_str());
    }
}

int main()
{
    winrt::init_apartment();

    PrintGenericInterfaces();

    {
        winrt::com_ptr<IGlobalOptions> globalOptions;
        winrt::check_hresult(CoCreateInstance(CLSID_GlobalOptions, nullptr, CLSCTX_INPROC,
                                              IID_PPV_ARGS(&globalOptions)));
        winrt::check_hresult(globalOptions->Set(COMGLB_RO_SETTINGS, COMGLB_FAST_RUNDOWN));
    }

    // Comment it and everything works fine.
    auto winappsdkGuard{MddBootstrap::InitializeFailFast()};

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
