#include "pch.h"
#include "HostManager.h"
#if __has_include("HostManager.g.cpp")
#include "HostManager.g.cpp"
#endif

#include <wil/cppwinrt_wrl.h>

#include <chrono>

#include "PEUtil.h"

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
                DWORD const error = GetLastError();
                TerminateProcess(ppi->hProcess, 0);
                CloseHandle(ppi->hProcess);
                CloseHandle(ppi->hThread);
                ppi->hProcess = ppi->hThread = nullptr;
                SetLastError(error);
            }
        }
        return fRc;
    }

    HostManager::HostManager()
    {
        m_host_job.reset(CreateJobObject(nullptr, nullptr));
        if (!m_host_job)
        {
            THROW_LAST_ERROR();
        }

        JOBOBJECT_EXTENDED_LIMIT_INFORMATION info{};
        info.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
        check_bool(SetInformationJobObject(m_host_job.get(), JobObjectExtendedLimitInformation, &info,
                                           sizeof(info)));
    }

    void HostManager::RegisterHost(Isolation::Host host)
    {
        std::unique_lock g{m_mtx};
        OutputDebugString(winrt::format(L"host connecting: {} [{}]\n", winrt::to_hstring(host.Id()),
                                        host.Bootdrive())
                              .c_str());
        host.Ping();

        auto bootdrive = std::filesystem::path{host.Bootdrive().c_str()}.lexically_normal();
        if (m_hosts.count(bootdrive))
        {
            OutputDebugString(L"warning: duplication of host registration, double creation?\n");

            // dispose the object and the host will exit
            host = nullptr;
            return;
        }

        m_hosts.emplace(std::move(bootdrive), host);
        g.unlock();
        m_host_cv.notify_all();
    }

    void HostManager::UnregisterHost(Isolation::Host host)
    {
        std::unique_lock g{m_mtx};
        OutputDebugString(winrt::format(L"host disconnecting: {} [{}]\n",
                                        winrt::to_hstring(host.Id()), host.Bootdrive())
                              .c_str());
        host.Ping();

        auto bootdrive = std::filesystem::path{host.Bootdrive().c_str()}.lexically_normal();
        m_hosts.erase(bootdrive);
    }

    inline static std::filesystem::path GetHostExePath(DWORD arch)
    {
        WCHAR szPath[MAX_PATH];
        DWORD const pathLength = ::GetModuleFileName(::GetModuleHandle(NULL), szPath, MAX_PATH);
        if (pathLength == 0)
        {
            THROW_LAST_ERROR();
        }
        if (pathLength == MAX_PATH)
        {
            THROW_WIN32(ERROR_INSUFFICIENT_BUFFER);
        }

        std::wstring arch_str;
        switch (arch)
        {
        case PROCESSOR_ARCHITECTURE_AMD64:
            arch_str = L"amd64";
            break;
        case PROCESSOR_ARCHITECTURE_ARM64:
            arch_str = L"arm64";
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            arch_str = L"x86";
            break;
        default:
            throw_hresult(E_INVALIDARG);
        }
        auto exeName = std::format(L"UFCase.Host.{}.exe", arch_str);

        std::filesystem::path mainExePath{szPath};
        auto hostExeDir = mainExePath.parent_path();
        auto hostExePath = hostExeDir / exeName;
        if (std::filesystem::exists(hostExePath))
        {
            return hostExePath;
        }

        THROW_WIN32(ERROR_FILE_NOT_FOUND);
    }

    Isolation::Host HostManager::GetOrStartHost(std::filesystem::path bootdrive)
    {
        bootdrive = bootdrive.lexically_normal();
        {
            std::unique_lock g{m_mtx};
            for (;;)
            {
                if (auto it = m_hosts.find(bootdrive); it != m_hosts.end())
                {
                    return it->second;
                }

                if (m_starting_hosts.emplace(bootdrive).second)
                {
                    break;
                }

                m_host_cv.wait(g, [&] {
                    return m_hosts.contains(bootdrive) || !m_starting_hosts.contains(bootdrive);
                });
            }
        }
        auto clear_starting_host = wil::scope_exit([&] {
            std::unique_lock g{m_mtx};
            m_starting_hosts.erase(bootdrive);
            g.unlock();
            m_host_cv.notify_all();
        });

        auto ntoskrnlPath = bootdrive / L"Windows" / L"System32" / L"ntoskrnl.exe";
        if (!std::filesystem::exists(ntoskrnlPath))
        {
            OutputDebugString(
                winrt::format(L"ntoskrnl.exe not found in {}, aborting\n", bootdrive.c_str())
                    .c_str());
            THROW_WIN32(ERROR_FILE_NOT_FOUND);
        }
        auto hostArch = GetExecutableProcessArchitecture(ntoskrnlPath);

        auto hostExePath = GetHostExePath(hostArch);
        auto hostExeDir = hostExePath.parent_path();
        auto client_id = winrt::to_hstring(winrt::GuidHelper::CreateNewGuid());

        for (int retry_cnt = 10; retry_cnt--;)
        {
            STARTUPINFO st_info{.cb = sizeof(st_info)};
            PROCESS_INFORMATION proc_info{};
            wil::unique_handle process{nullptr};
            wil::unique_handle thread{nullptr};

            std::wstring command_line = winrt::format(L"\"{}\" \"{}\" \"{}\"",
                                                      hostExePath.wstring(), client_id,
                                                      bootdrive.c_str())
                                            .c_str();
            auto command_line_buffer = wil::make_unique_hlocal_nothrow<wchar_t[]>(command_line.size() + 1);
            if (!command_line_buffer)
            {
                THROW_WIN32(ERROR_NOT_ENOUGH_MEMORY);
            }
            wcscpy_s(command_line_buffer.get(), command_line.size() + 1, command_line.c_str());

            if (!CreateProcessInJob(m_host_job.get(), hostExePath.c_str(), command_line_buffer.get(),
                                    nullptr, nullptr, FALSE, 0, nullptr, hostExeDir.c_str(),
                                    &st_info, &proc_info))
            {
                winrt::check_hresult(HRESULT_FROM_WIN32(GetLastError()));
            }
            process.reset(proc_info.hProcess);
            thread.reset(proc_info.hThread);

            std::unique_lock g{m_mtx};
            auto const registered = m_host_cv.wait_for(g, std::chrono::milliseconds{200}, [&] {
                return m_hosts.find(bootdrive) != m_hosts.end();
            });
            if (registered)
            {
                return m_hosts.at(bootdrive);
            }
            g.unlock();

            TerminateProcess(process.get(), 0);
            WaitForSingleObject(process.get(), INFINITE);
            OutputDebugString(L"no registration received from host, retrying\n");
        }

        OutputDebugString(L"failed to start host, aborting\n");
        THROW_WIN32(ERROR_TIMEOUT);
    }
} // namespace winrt::UFCase::Isolation::implementation
