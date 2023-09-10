﻿#include "pch.h"
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
            DispatchTaskAsync(GlobalRes::WorkerQueue(), [self = get_strong()]() -> IAsyncAction {
                co_await GlobalRes::MainProgServ().InsertTask(SearchImages(), 200);
                self->m_images = GetImageSearchResult();
                RunUITask([self]() {
                    self->NotifyPropChange(L"Images");
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

        m_selectedIdx = value;

        m_images.GetAt(value).Select();

        RunUITaskAsync([self = get_strong()]() -> IAsyncAction {
            co_await GlobalRes::MainNavServ().Initialize();
            self->NotifyPropChange(L"SelectedIndex");
        });
    }

} // namespace winrt::UFCase::implementation
