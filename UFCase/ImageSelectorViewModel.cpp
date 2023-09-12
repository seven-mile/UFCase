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
    }

    IObservableVector<UFCase::ImageViewModel> ImageSelectorViewModel::Images()
    {
        if (!m_images)
        {
            DispatchTaskAsync(GlobalRes::WorkerQueue(), [self_lambda = get_strong()]() -> IAsyncAction {
                auto self = self_lambda;
                co_await GlobalRes::MainProgServ().InsertTask(SearchImages(), 200);
                self->m_images = GetImageSearchResult();
                RunUITask([self]() {
                    self->NotifyPropChange(L"Images");
                    // select online image by default
                    self->SelectedIndex(0);
                });
            });
        }

        return m_images;
    }

    int32_t ImageSelectorViewModel::SelectedIndex()
    {
        return m_selectedIdx;
    }

    void ImageSelectorViewModel::SelectedIndex(int32_t value)
    {
        if (m_selectedIdx == value)
            return;

        auto image = m_images.GetAt(value);

        if (!image.Selectable())
            return;

        m_selectedIdx = value;
        image.Select();

        RunUITaskAsync([self_lambda = get_strong()]() -> IAsyncAction {
            auto self = self_lambda;
            co_await GlobalRes::MainNavServ().Initialize();
            self->NotifyPropChange(L"SelectedIndex");
        });
    }

} // namespace winrt::UFCase::implementation
