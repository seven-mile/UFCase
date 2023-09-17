#include "pch.h"
#include "PackagesPageViewModel.h"
#if __has_include("PackagesPageNavigationContext.g.cpp")
#include "PackagesPageNavigationContext.g.cpp"
#endif
#if __has_include("PackagesPageViewModel.g.cpp")
#include "PackagesPageViewModel.g.cpp"
#endif

#include "PackageViewModel.g.h"

namespace winrt::UFCase::implementation
{
    IAsyncActionWithProgress<uint32_t> PackagesPageViewModel::PullData(bool is_nav)
    {
        apartment_context ui_thread{};

        m_packages = multi_threaded_observable_vector<UFCase::PackageViewModel>();
        m_selected = {nullptr};

        co_await resume_background();

        switch (m_state)
        {
        case PackagesPageViewModelState::Loading:
            co_return;
        default:
            m_state = PackagesPageViewModelState::Loading;
            break;
        }

        auto report_prog = co_await get_progress_token();
        auto session = m_image.get().OpenSession();
        report_prog(25);

        auto &&pkgs = session.GetPackageCollection(0x50);
        report_prog(50);
        uint32_t cnt = 0;

        for (auto pkg : pkgs)
        {
            UFCase::PackageViewModel pkg_vm(pkg);
            if (is_nav && m_nav_ctx && pkg.Identity() == m_nav_ctx.SelectPkgId())
            {
                if (!m_selected)
                    m_selected = pkg_vm;
            }
            RunUITask([=] { m_packages.Append(pkg_vm); });
            report_prog(static_cast<uint32_t>(50 + 50 * ++cnt / pkgs.Size()));
        }

        co_await ui_thread;

        NotifyPropChange(L"Packages");
        NotifyPropChange(L"SelectedPackage");

        m_state = PackagesPageViewModelState::Idle;

        co_return;
    }
} // namespace winrt::UFCase::implementation
