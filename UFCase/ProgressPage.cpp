#include "pch.h"
#include "ProgressPage.h"
#if __has_include("ProgressPage.g.cpp")
#include "ProgressPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UFCase::implementation
{

    ProgressPage::ProgressPage()
    {
        InitializeComponent();
    }

    void ProgressPage::OnNavigatedTo(const winrt::NavigationEventArgs& e)
    {
        winrt::apartment_context ui_thread;

        auto handler =
        [ui_thread, prog_bar = this->ProgBar()]
        (auto &op, uint32_t pr) -> winrt::IAsyncAction {
            co_await ui_thread;
            prog_bar.Value(pr);
        };

        if (auto val = e.Parameter().try_as<IAsyncActionWithProgress<uint32_t>>()) {
            val.Progress(handler);
        } else if (auto val = e.Parameter().try_as<IAsyncOperationWithProgress<IObservableVector<FeatureTreeElement>, uint32_t>>()) {
            val.Progress(handler);
        } else {
            throw winrt::hresult_invalid_argument();
        }
    }

}
