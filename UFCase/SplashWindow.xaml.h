// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "AppInitializeContext.g.h"
#include "SplashWindow.g.h"

#include "PropChgUtil.h"

namespace winrt::UFCase::implementation
{

    struct AppInitializeContext : AppInitializeContextT<AppInitializeContext>
    {
        AppInitializeContext() = default;

        UFCase::ImageSelectorViewModel ImagesViewModel()
        {
            return m_images;
        }

        void ImagesViewModel(UFCase::ImageSelectorViewModel const &value)
        {
            m_images = value;
        }

      private:
        UFCase::ImageSelectorViewModel m_images{nullptr};
    };

    struct SplashWindow : SplashWindowT<SplashWindow>, ImplPropertyChangedT<SplashWindow>
    {
        SplashWindow();

        void InitializeComponent();

        IAsyncOperation<UFCase::AppInitializeContext> InitializeAsync();

        hstring Status()
        {
            return m_status;
        }

      private:
        hstring m_status;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct AppInitializeContext
        : AppInitializeContextT<AppInitializeContext, implementation::AppInitializeContext>
    {
    };

    struct SplashWindow : SplashWindowT<SplashWindow, implementation::SplashWindow>
    {
    };
} // namespace winrt::UFCase::factory_implementation
