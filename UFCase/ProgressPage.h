#pragma once

#include "ProgressPage.g.h"

#include <functional>

namespace winrt {
    using namespace Microsoft::UI::Xaml::Navigation;
}

namespace winrt::UFCase::implementation
{
    struct ProgressPage : ProgressPageT<ProgressPage>
    {

        ProgressPage();

        void OnNavigatedTo(const winrt::NavigationEventArgs &e);

    private:
        uint32_t m_prog = 0;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct ProgressPage : ProgressPageT<ProgressPage, implementation::ProgressPage>
    {
    };
}
