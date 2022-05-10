#pragma once

#include "ImageViewModel.g.h"

#include "ImageModel.h"

namespace winrt::UFCase::implementation
{
    struct ImageViewModel : ImageViewModelT<ImageViewModel>
    {
        ImageViewModel(uint64_t hModel);

        hstring Type();
        hstring Version();
        hstring Edition();
        hstring Bootdrive();
        Media::ImageSource Icon();

        void Select();

        uint64_t OpenSession();
        void CloseSession(uint64_t handle);

    private:
        ImageModel& m_model;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct ImageViewModel : ImageViewModelT<ImageViewModel, implementation::ImageViewModel>
    {
    };
}
