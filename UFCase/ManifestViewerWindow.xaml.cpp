// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "ManifestViewerWindow.xaml.h"
#if __has_include("ManifestViewerWindow.g.cpp")
#include "ManifestViewerWindow.g.cpp"
#endif

#include "AsyncUtil.h"

#include <winrt/Microsoft.UI.Windowing.h>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    ManifestViewerWindow::ManifestViewerWindow(UFCase::ManifestViewerWindowViewModel view_model)
        : m_view_model(view_model)
    {
        no_await(m_view_model.Assembly().PullData());
    }
    void ManifestViewerWindow::InitializeComponent()
    {
        ManifestViewerWindowT::InitializeComponent();

        AppWindow().Resize({1080, 768});
    }
} // namespace winrt::UFCase::implementation
