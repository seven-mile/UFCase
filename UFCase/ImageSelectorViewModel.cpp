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
        this->m_images = GetImageSearchResult();
        this->SelectedIndex(0);
    }

    IObservableVector<UFCase::ImageViewModel> ImageSelectorViewModel::Images()
    {
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

        RunUITaskAsync([]() -> IAsyncAction {
            co_await GlobalRes::MainNavServ().Initialize();
        });

        this->m_propertyChanged(*this, winrt::Data::PropertyChangedEventArgs{L"SelectedIndex"});
    }

    winrt::event_token ImageSelectorViewModel::PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value)
    {
        return this->m_propertyChanged.add(value);
    }

    void ImageSelectorViewModel::PropertyChanged(winrt::event_token const& token)
    {
        this->m_propertyChanged.remove(token);
    }
}
