#pragma once

#include "HrError.g.h"
#include "ErrorPage.g.h"

namespace winrt {
    using namespace Microsoft::UI::Xaml::Navigation;
}

namespace winrt::UFCase::implementation
{

    struct HrError : HrErrorT<HrError>
    {
        HrError();
        HrError(int hr);

        int Code();
        void Code(int val);
        hstring Message();
        void Message(const hstring &val);

    private:
        int m_code;
        hstring m_msg;
    };

    struct ErrorPage : ErrorPageT<ErrorPage>
    {
        ErrorPage();

        void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const &e);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct HrError : HrErrorT<HrError, implementation::HrError>
    {
    };

    struct ErrorPage : ErrorPageT<ErrorPage, implementation::ErrorPage>
    {
    };
}
