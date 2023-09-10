#pragma once

#include "ComponentsPage.g.h"

namespace winrt::UFCase::implementation
{
    struct ComponentsPage : ComponentsPageT<ComponentsPage>
    {
        ComponentsPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(IInspectable const &sender, RoutedEventArgs const &args);
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ComponentsPage : ComponentsPageT<ComponentsPage, implementation::ComponentsPage>
    {
    };
} // namespace winrt::UFCase::factory_implementation
