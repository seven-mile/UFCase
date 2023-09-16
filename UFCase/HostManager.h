#pragma once

#include "HostManager.g.h"

#include <wil/resource.h>

#include <filesystem>
#include <functional>
#include <mutex>
#include <string>

namespace winrt::UFCase::Isolation::implementation
{
    struct HostManager : HostManagerT<HostManager>
    {
        using callback_t = std::function<void(Isolation::Host)>;

        HostManager();

        void RegisterHost(Isolation::Host host);

        void UnregisterHost(Isolation::Host host);

        Isolation::Host GetOrStartHost(std::filesystem::path bootdrive);

      private:
        std::mutex m_mtx;
        std::unordered_map<std::filesystem::path, Isolation::Host> m_hosts;
        wil::unique_event m_host_event{wil::EventOptions::None};
        HANDLE m_host_job;
    };
} // namespace winrt::UFCase::Isolation::implementation
