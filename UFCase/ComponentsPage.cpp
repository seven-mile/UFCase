#include "pch.h"
#include "ComponentsPage.h"
#if __has_include("ComponentsPage.g.cpp")
#include "ComponentsPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UFCase::implementation
{
    int32_t ComponentsPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ComponentsPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void ComponentsPage::ClickHandler(IInspectable const &, RoutedEventArgs const &)
    {
        Button().Content(box_value(L"Clicked"));
    }
} // namespace winrt::UFCase::implementation
