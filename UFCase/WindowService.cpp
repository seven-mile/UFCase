#include "pch.h"
#include "WindowService.h"
#if __has_include("WindowService.g.cpp")
#include "WindowService.g.cpp"
#endif

#include "GlobalUtil.h"

namespace winrt::UFCase::implementation
{
    WindowService::WindowService()
    {
        GlobalRes::WindowServ(*this);
    }

    bool WindowService::TryActivateWindow(IInspectable view_model)
    {
        std::unique_lock g{m_mutex};
        if (m_windows.find(view_model) == m_windows.end())
        {
            return false;
        }

        m_windows.at(view_model).Activate();
        return true;
    }

    void WindowService::RegisterWindow(IInspectable view_model, Window window)
    {
        std::unique_lock g{m_mutex};
        m_windows.emplace(view_model, window);
    }

    void WindowService::UnregisterWindow(IInspectable view_model)
    {
        std::unique_lock g{m_mutex};
        m_windows.erase(view_model);
    }

} // namespace winrt::UFCase::implementation
