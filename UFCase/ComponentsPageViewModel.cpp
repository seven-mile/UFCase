#include "pch.h"
#include "ComponentsPageViewModel.h"
#if __has_include("ComponentsPageViewModel.g.cpp")
#include "ComponentsPageViewModel.g.cpp"
#endif

#include "StoreModel.h"
#include "ComponentModel.h"

#include "AsyncUtil.h"
#include "CbsUtil.h"

#include <ranges>

namespace winrt::UFCase::implementation
{
    ComponentsPageViewModel::ComponentsPageViewModel(UFCase::ImageViewModel image) : m_image(image)
    {
        m_components = multi_threaded_observable_vector<UFCase::ComponentViewModel>();
    }

    IAsyncActionWithProgress<uint32_t> ComponentsPageViewModel::PullData()
    {
        auto lifetime{get_strong()};
        apartment_context ui_thread{};

        co_await resume_background();
        auto report_progress = co_await get_progress_token();

        m_components.Clear();

        auto &store = StoreModel::GetInstance(m_image.Store());

        auto comps = store.Components();

        // if no reference restriction, estimate 10000 components
        // if there is reference restriction, this should be fast enough
        // and do not need a progress bar
        SIZE_T comps_count = 10000;

        for (SIZE_T idx = 0; auto *comp : comps)
        {
            UFCase::ComponentViewModel comp_vm{comp->GetHandle()};
            RunUITask([=] { m_components.Append(comp_vm); });

            ++idx;
            if (idx <= comps_count)
            {
                report_progress(static_cast<uint32_t>(idx * 100 / comps_count));
            }
        }

        co_await ui_thread;

        NotifyPropChange(L"Components");

        report_progress(100);

        co_return;
    }
} // namespace winrt::UFCase::implementation
