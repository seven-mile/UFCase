#include "pch.h"
#include "ComponentsPageViewModel.h"
#if __has_include("ComponentsPageViewModel.g.cpp")
#include "ComponentsPageViewModel.g.cpp"
#endif

namespace winrt::UFCase::implementation
{
    int32_t ComponentsPageViewModel::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ComponentsPageViewModel::MyProperty(int32_t /*value*/)
    {
        throw hresult_not_implemented();
    }
} // namespace winrt::UFCase::implementation
