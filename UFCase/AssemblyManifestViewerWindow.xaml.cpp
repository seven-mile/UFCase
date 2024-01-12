// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "AssemblyManifestViewerWindow.xaml.h"
#if __has_include("AssemblyManifestViewerWindow.g.cpp")
#include "AssemblyManifestViewerWindow.g.cpp"
#endif

#include "AsyncUtil.h"
#include "GlobalUtil.h"

#include <winrt/Microsoft.UI.Windowing.h>


namespace winrt::UFCase::implementation
{

    AssemblyManifestViewerWindow::AssemblyManifestViewerWindow(
        UFCase::AssemblyManifestViewerWindowViewModel view_model)
        : m_view_model(view_model)
    {
        no_await(m_view_model.Assembly().PullData());
    }
    void AssemblyManifestViewerWindow::InitializeComponent()
    {
        AssemblyManifestViewerWindowT::InitializeComponent();

        AppWindow().Resize({1080, 768});
    }

    fire_and_forget AssemblyManifestViewerWindow::ListView_ItemClick_Component(
        IInspectable const &sender, ItemClickEventArgs const &e)
    {
        auto lv = sender.as<ListView>();
        auto idx = lv.IndexFromContainer(lv.ContainerFromItem(e.ClickedItem()));
        m_view_model.Assembly().LocateDependentAssembly(idx);
        co_return;
    }

} // namespace winrt::UFCase::implementation
