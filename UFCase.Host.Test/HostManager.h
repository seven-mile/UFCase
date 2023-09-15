#pragma once

#include "HostManager.g.h"

#include <filesystem>
#include <mutex>

namespace winrt::UFCase::Isolation::implementation
{
    struct HostManager : HostManagerT<HostManager>
    {
        void RegisterHost(Isolation::Host host);

        void UnregisterHost(Isolation::Host host);

      private:
        std::mutex m_mtx;
        std::unordered_map<std::filesystem::path, Isolation::Host> m_hosts;
    };
} // namespace winrt::UFCase::Isolation::implementation
