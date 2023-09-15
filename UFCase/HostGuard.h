#pragma once

namespace winrt::UFCase
{
    struct HostGuard
    {
        HostGuard();
        ~HostGuard();

        HostGuard(HostGuard const &) = delete;
        HostGuard &operator=(HostGuard const &) = delete;
    };
} // namespace winrt::UFCase
