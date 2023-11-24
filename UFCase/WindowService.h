#pragma once

#include "WindowService.g.h"

#include <unordered_map>
#include <mutex>

namespace winrt::UFCase::implementation
{
    struct WindowService : WindowServiceT<WindowService>
    {
        WindowService();

        bool TryActivateWindow(IInspectable view_model);
        void RegisterWindow(IInspectable view_model, Window window);
        void UnregisterWindow(IInspectable view_model);

      private:
        std::unordered_map<IInspectable, Window> m_windows;
        std::mutex m_mutex;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct WindowService : WindowServiceT<WindowService, implementation::WindowService>
    {
    };
} // namespace winrt::UFCase::factory_implementation
