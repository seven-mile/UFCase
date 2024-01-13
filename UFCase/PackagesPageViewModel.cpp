#include "pch.h"
#include "PackagesPageViewModel.h"
#if __has_include("PackagesPageNavigationContext.g.cpp")
#include "PackagesPageNavigationContext.g.cpp"
#endif
#if __has_include("PackagesPageViewModel.g.cpp")
#include "PackagesPageViewModel.g.cpp"
#endif

#include "PackageViewModel.g.h"

#include "IdentityUtil.h"

namespace winrt::UFCase::implementation
{

    bool PackagesPageViewModel::MatchingPackage(UFCase::PackageViewModel pkg)
    {
        if (!m_nav_ctx)
            return false;

        if (m_nav_ctx.Type() == UFCase::PackagesPageNavigationContextType::SelectPkgStringId)
        {
            return pkg.DetailIdentity() == m_nav_ctx.SelectPkgStringId();
        }
        else if (m_nav_ctx.Type() == UFCase::PackagesPageNavigationContextType::SelectPkgIdentity)
        {
            auto pkg_ident = IdentityUtil::GetIdentityFromPkgKeyForm(pkg.Model().Identity());
            return IdentityUtil::RoughMatch(pkg_ident, m_nav_ctx.SelectPkgIdentity());
        }
        return false;
    }

    IAsyncActionWithProgress<uint32_t> PackagesPageViewModel::PullData(apartment_context ui_thread)
    {
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

        auto &&pkgs = session.GetPackageCollection(0x70);
        report_prog(50);
        uint32_t cnt = 0;

        // todo: batching task submissions for better performance
        for (auto pkg : pkgs)
        {
            UFCase::PackageViewModel pkg_vm(pkg);
            RunUITask([=] { m_packages.Append(pkg_vm); });
            report_prog(static_cast<uint32_t>(50 + 50 * ++cnt / pkgs.Size()));
        }

        co_await ui_thread;

        NotifyPropChange(L"Packages");
        NotifyPropChange(L"SelectedPackage");

        m_state = PackagesPageViewModelState::Idle;

        co_return;
    }

    fire_and_forget PackagesPageViewModel::Navigate(
        UFCase::PackagesPageNavigationContext const &nav_ctx)
    {
        apartment_context ui_thread{};

        m_nav_ctx = nav_ctx;

        co_await resume_background();

        if (m_state == PackagesPageViewModelState::Uninitialized)
        {
            co_await GlobalRes::MainProgServ().InsertTask(PullData(ui_thread), 100);
        }

        // find the package and select it
        if (m_nav_ctx && m_nav_ctx.Type() != UFCase::PackagesPageNavigationContextType::None)
        {
            m_selected = nullptr;
            for (auto pkg : m_packages)
            {
                if (MatchingPackage(pkg))
                {
                    m_selected = pkg;
                    break;
                }
            }
            co_await ui_thread;
            NotifyPropChange(L"SelectedPackage");
        }

        Navigated.invoke(*this, m_nav_ctx);

        co_return;
    }

} // namespace winrt::UFCase::implementation
