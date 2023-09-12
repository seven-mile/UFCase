#include "pch.h"
#include "ImageSelectorViewModel.h"
#if __has_include("ImageSelectorViewModel.g.cpp")
#include "ImageSelectorViewModel.g.cpp"
#endif

#include "AppConfig.h"
#include "ImageSelectorHelper.h"
#include "GlobalUtil.h"
#include "AsyncUtil.h"

#include <filesystem>

namespace winrt::UFCase::implementation
{
    ImageSelectorViewModel::ImageSelectorViewModel()
    {
        this->m_images = multi_threaded_observable_vector<UFCase::ImageViewModel>();
    }

    IObservableVector<UFCase::ImageViewModel> ImageSelectorViewModel::Images()
    {
        return m_images;
    }

    int32_t ImageSelectorViewModel::SelectedIndex()
    {
        return m_selected_idx;
    }

    void ImageSelectorViewModel::SelectedIndex(int32_t value)
    {
        if (m_selected_idx == value)
            return;

        auto image = m_images.GetAt(value);

        if (!image.Selectable())
            return;

        m_selected_idx = value;
        image.Select();

        RunUITaskAsync([self_lambda = get_strong()]() -> IAsyncAction {
            auto self = self_lambda;
            co_await GlobalRes::MainNavServ().Initialize();
            self->NotifyPropChange(L"SelectedIndex");
        });
    }

    IAsyncActionWithProgress<hstring> ImageSelectorViewModel::PullData()
    {
        apartment_context ui_thread;

        auto report_prog = co_await get_progress_token();

        auto forward_progress = [&](auto const &op) {
            op.Progress([&](auto &, auto prog) { report_prog(prog); });
            return op;
        };

        this->m_images = co_await forward_progress(SearchImages());
        // select online image
        this->m_selected_idx = 0;

        RunUITask([self = get_strong()]() {
            self->NotifyPropChange(L"Images");
            self->NotifyPropChange(L"SelectedIndex");
        });

        co_return;
    }

} // namespace winrt::UFCase::implementation
