// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "AssemblyManifestViewerWindow.xaml.h"
#if __has_include("AssemblyManifestViewerWindow.g.cpp")
#include "AssemblyManifestViewerWindow.g.cpp"
#endif

#include "AsyncUtil.h"

#include <winrt/Microsoft.UI.Windowing.h>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    AssemblyManifestViewerWindow::AssemblyManifestViewerWindow(UFCase::AssemblyManifestViewerWindowViewModel view_model)
        : m_view_model(view_model)
    {
        no_await(m_view_model.Assembly().PullData());
    }
    void AssemblyManifestViewerWindow::InitializeComponent()
    {
        AssemblyManifestViewerWindowT::InitializeComponent();

        AppWindow().Resize({1080, 768});
    }
} // namespace winrt::UFCase::implementation
