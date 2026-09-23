#pragma once

#include "HostManager.g.h"

#include <wil/resource.h>

#include <filesystem>
#include <functional>
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <string>
#include <unordered_set>

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
        std::condition_variable m_host_cv;
        std::unordered_map<std::filesystem::path, Isolation::Host> m_hosts;
        std::unordered_set<std::filesystem::path> m_starting_hosts;
        wil::unique_handle m_host_job;
    };
} // namespace winrt::UFCase::Isolation::implementation
