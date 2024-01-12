#include "pch.h"
#include "ComponentsPageViewModel.h"
#if __has_include("ComponentsPageNavigationContext.g.cpp")
#include "ComponentsPageNavigationContext.g.cpp"
#endif
#if __has_include("ComponentsPageViewModel.g.cpp")
#include "ComponentsPageViewModel.g.cpp"
#endif

#include <winrt/UFCase.Isolation.h>

#include "AsyncUtil.h"

#include <ranges>

namespace winrt::UFCase::implementation
{
    ComponentsPageViewModel::ComponentsPageViewModel(UFCase::ImageViewModel image) : m_image(image)
    {
        m_components = multi_threaded_observable_vector<UFCase::ComponentViewModel>();
    }

    bool ComponentsPageViewModel::MatchingComponent(UFCase::ComponentViewModel const &comp)
    {
        if (m_nav_ctx.Type() == ComponentsPageNavigationContextType::SelectCompId)
        {
            return comp.Name() == m_nav_ctx.SelectCompId();
        }
        else if (m_nav_ctx.Type() == ComponentsPageNavigationContextType::SelectCompIdentity)
        {
            UFCase::Identity comp_ident;
            comp_ident.Name(comp.Name());
            comp_ident.Version(comp.Version());
            comp_ident.PublicKeyToken(comp.PublicKeyToken());
            comp_ident.ProcessorArchitecture(comp.ProcessorArchitecture());
            comp_ident.Culture(comp.Culture());
            return UFCase::Identity::RoughMatch(comp_ident, m_nav_ctx.SelectCompIdentity());
        }
        return false;
    }

    IAsyncActionWithProgress<uint32_t> ComponentsPageViewModel::PullData(
        apartment_context ui_thread)
    {
        auto lifetime{get_strong()};

        co_await resume_background();

        switch (m_state)
        {
        case ComponentsPageViewModelState::Loading:
            co_return;
        default:
            m_state = ComponentsPageViewModelState::Loading;
            break;
        }

        auto report_progress = co_await get_progress_token();

        m_components.Clear();

        auto store = m_image.get().Store();

        auto comps = store.GetComponentCollection();

        // if no reference restriction, estimate 15000 components
        // if there is reference restriction, this should be fast enough
        // and do not need a progress bar
        SIZE_T comps_count = 15000;

        bool matched_flag = false;
        for (SIZE_T idx = 0; auto comp_ : comps)
        {
            auto comp = comp_.as<Isolation::ComponentModel>();
            UFCase::ComponentViewModel comp_vm{comp};
            // todo: batching for better performance
            if (MatchingComponent(comp_vm))
            {
                RunUITask([=, lifetime = lifetime] {
                    m_selected = comp_vm;
                    NotifyPropChange(L"SelectedComponent");
                    Navigated.invoke(*this, m_nav_ctx);
                    m_components.Append(comp_vm);
                });
                matched_flag = true;
            }
            else
            {
                RunUITask([=, lifetime = lifetime] { m_components.Append(comp_vm); });
            }

            ++idx;
            if (idx <= comps_count)
            {
                report_progress(static_cast<uint32_t>(idx * 100 / comps_count));
            }
        }

        co_await ui_thread;

        NotifyPropChange(L"Components");

        report_progress(100);

        if (!matched_flag)
        {
            m_selected = nullptr;
            NotifyPropChange(L"SelectedComponent");
            Navigated.invoke(*this, m_nav_ctx);
        }

        m_state = ComponentsPageViewModelState::Idle;

        co_return;
    }

    fire_and_forget ComponentsPageViewModel::Navigate(
        UFCase::ComponentsPageNavigationContext const &nav_ctx)
    {
        apartment_context ui_thread{};

        m_nav_ctx = nav_ctx;

        co_await resume_background();

        if (m_state == ComponentsPageViewModelState::Uninitialized)
        {
            co_await GlobalRes::MainProgServ().InsertTask(PullData(ui_thread), 100);
        }
        else
        {
            // find the component and select it
            if (m_nav_ctx && m_nav_ctx.Type() != UFCase::ComponentsPageNavigationContextType::None)
            {
                m_selected = nullptr;
                for (auto comp : m_components)
                {
                    if (MatchingComponent(comp))
                    {
                        m_selected = comp;
                        co_await ui_thread;
                        NotifyPropChange(L"SelectedComponent");
                        Navigated.invoke(*this, m_nav_ctx);
                        break;
                    }
                }
            }
        }

        co_return;
    }

} // namespace winrt::UFCase::implementation
