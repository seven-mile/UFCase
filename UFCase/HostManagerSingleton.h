#pragma once

#include "HostManagerSingleton.g.h"

#include "HostManager.h"

namespace winrt::UFCase::Isolation::implementation
{
    struct __declspec(uuid("EF5B65F8-2568-46BF-9436-65D304ADF719")) HostManagerSingleton
        : HostManagerSingletonT<HostManagerSingleton>
    {
        static Isolation::HostManager Current()
        {
            static auto instance = make<implementation::HostManager>();
            return instance;
        }
    };
} // namespace winrt::UFCase::Isolation::implementation

namespace winrt::UFCase::Isolation::factory_implementation
{
    struct HostManagerSingleton
        : HostManagerSingletonT<HostManagerSingleton, implementation::HostManagerSingleton>
    {
    };
} // namespace winrt::UFCase::Isolation::factory_implementation
