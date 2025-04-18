#include "pch.h"
#include "HostManager.h"
#if __has_include("HostManager.g.cpp")
#include "HostManager.g.cpp"
#endif

#include <wil/cppwinrt_wrl.h>

namespace winrt::UFCase::Isolation::implementation
{

    static BOOL CreateProcessInJob(HANDLE hJob, LPCTSTR lpApplicationName, LPTSTR lpCommandLine,
                                   LPSECURITY_ATTRIBUTES lpProcessAttributes,
                                   LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles,
                                   DWORD dwCreationFlags, LPVOID lpEnvironment,
                                   LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo,
                                   LPPROCESS_INFORMATION ppi)
    {
        BOOL fRc =
            CreateProcess(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes,
                          bInheritHandles, dwCreationFlags | CREATE_SUSPENDED, lpEnvironment,
                          lpCurrentDirectory, lpStartupInfo, ppi);
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

    HostManager::HostManager()
    {
        m_host_job = CreateJobObject(nullptr, nullptr);
        JOBOBJECT_EXTENDED_LIMIT_INFORMATION info = {};
        info.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
        check_bool(SetInformationJobObject(m_host_job, JobObjectExtendedLimitInformation, &info,
                                           sizeof(info)));
    }

    void HostManager::RegisterHost(Isolation::Host host)
    {
        std::unique_lock g{m_mtx};
        OutputDebugString(winrt::format(L"host connecting: {} [{}]\n", winrt::to_hstring(host.Id()),
                                        host.Bootdrive())
                              .c_str());
        host.Ping();

        if (m_hosts.count(host.Bootdrive().c_str()))
        {
            OutputDebugString(L"warning: duplication of host registration, double creation?\n");

            // dispose the object and the host will exit
            host = nullptr;

            return;
        }

        m_hosts.emplace(host.Bootdrive().c_str(), host);

        m_host_event.SetEvent();
    }

    void HostManager::UnregisterHost(Isolation::Host host)
    {
        std::unique_lock g{m_mtx};
        OutputDebugString(winrt::format(L"host disconnecting: {} [{}]\n",
                                        winrt::to_hstring(host.Id()), host.Bootdrive())
                              .c_str());
        host.Ping();

        m_hosts.erase(host.Bootdrive().c_str());
    }

    inline static std::filesystem::path GetHostExePath(std::wstring const &arch)
    {
        WCHAR szPath[MAX_PATH];
        ::GetModuleFileName(::GetModuleHandle(NULL), szPath, MAX_PATH);

        winrt::check_win32(GetLastError());

        auto exeName = std::format(L"UFCase.Host.{}.exe", arch);

        std::filesystem::path mainExePath{szPath};
        {
            auto hostExeDir = mainExePath.parent_path();
            auto hostExePath = hostExeDir / exeName;
            if (std::filesystem::exists(hostExePath))
            {
                return hostExePath;
            }
        }

        THROW_WIN32(ERROR_FILE_NOT_FOUND);
    }

    Isolation::Host HostManager::GetOrStartHost(std::filesystem::path bootdrive)
    {
        bootdrive = bootdrive.lexically_normal();
        {
            std::unique_lock g{m_mtx};
            if (auto it = m_hosts.find(bootdrive); it != m_hosts.end())
            {
                return it->second;
            }
        }

        // todo: detect host architecture
#if defined(_M_ARM64)
        auto hostArch = L"arm64";
#elif defined(_M_ARM)
        auto hostArch = L"arm32";
#elif defined(_M_X64)
        auto hostArch = L"amd64";
#elif defined(_M_X86)
        auto hostArch = L"x86";
#else
#error "Unknown architecture"
#endif

        auto hostExePath = GetHostExePath(hostArch);
        auto hostExeDir = hostExePath.parent_path();

        auto client_id = winrt::to_hstring(winrt::GuidHelper::CreateNewGuid());

        for (int retry_cnt = 10; retry_cnt--;)
        {
            STARTUPINFO st_info{
                .cb = sizeof(st_info),
            };
            PROCESS_INFORMATION proc_info{};
            if (!CreateProcessInJob(
                    m_host_job, hostExePath.c_str(),
                    const_cast<LPWSTR>(winrt::format(L"{} {} {}", hostExePath.wstring(), client_id,
                                                     bootdrive.c_str())
                                           .c_str()),
                    NULL, NULL, FALSE, NULL, NULL, hostExeDir.c_str(), &st_info, &proc_info))
            {
                winrt::check_hresult(HRESULT_FROM_WIN32(GetLastError()));
            }

            if (m_host_event.wait(200))
            {
                std::unique_lock g{m_mtx};
                if (auto it = m_hosts.find(bootdrive); it != m_hosts.end())
                {
                    return it->second;
                }
            }

            if (proc_info.hProcess)
            {
                TerminateProcess(proc_info.hProcess, 0);
            }
            OutputDebugString(L"no registration received from host, retrying\n");
        }

        OutputDebugString(L"failed to start host, aborting\n");
        THROW_WIN32(ERROR_TIMEOUT);
    }
} // namespace winrt::UFCase::Isolation::implementation
