#pragma once

#include "ComponentsPageViewModel.g.h"

#include "PropChgUtil.h"

namespace winrt::UFCase::implementation
{
    struct ComponentsPageViewModel : ComponentsPageViewModelT<ComponentsPageViewModel>,
                                     ImplPropertyChangedT<ComponentsPageViewModel>
    {
        ComponentsPageViewModel(UFCase::ImageViewModel vm);

        IAsyncActionWithProgress<uint32_t> PullData();

        Collections::IObservableVector<UFCase::ComponentViewModel> Components()
        {
            return m_components;
        }

        UFCase::ComponentViewModel SelectedComponent()
        {
            return m_selected;
        }

        void SelectedComponent(UFCase::ComponentViewModel value)
        {
            m_selected = value;
            // NotifyPropChange(L"SelectedComponent");
        }

      private:
        UFCase::ImageViewModel m_image;

        UFCase::ComponentViewModel m_selected{nullptr};
        Collections::IObservableVector<UFCase::ComponentViewModel> m_components;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ComponentsPageViewModel
        : ComponentsPageViewModelT<ComponentsPageViewModel, implementation::ComponentsPageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
