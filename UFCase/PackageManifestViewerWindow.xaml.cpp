// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "PackageManifestViewerWindow.xaml.h"
#if __has_include("PackageManifestViewerWindow.g.cpp")
#include "PackageManifestViewerWindow.g.cpp"
#endif

#include <winrt/Microsoft.UI.Windowing.h>

#include "AsyncUtil.h"

namespace winrt::UFCase::implementation
{
    PackageManifestViewerWindow::PackageManifestViewerWindow(
        UFCase::PackageManifestViewerWindowViewModel view_model)
        : m_view_model(view_model)
    {
        no_await(m_view_model.PullData());
    }

    void PackageManifestViewerWindow::InitializeComponent()
    {
        PackageManifestViewerWindowT::InitializeComponent();

        AppWindow().Resize({1080, 768});
    }
} // namespace winrt::UFCase::implementation
