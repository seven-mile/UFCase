#pragma once

#include "ComponentsPageViewModel.g.h"

namespace winrt::UFCase::implementation
{
    struct ComponentsPageViewModel : ComponentsPageViewModelT<ComponentsPageViewModel>
    {
        ComponentsPageViewModel() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ComponentsPageViewModel
        : ComponentsPageViewModelT<ComponentsPageViewModel, implementation::ComponentsPageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
