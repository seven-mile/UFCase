// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "PackageManifestViewerWindow.xaml.h"
#if __has_include("PackageManifestViewerWindow.g.cpp")
#include "PackageManifestViewerWindow.g.cpp"
#endif

#include <winrt/Microsoft.UI.Windowing.h>

#include "AsyncUtil.h"
#include "GlobalUtil.h"

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

    fire_and_forget PackageManifestViewerWindow::ListView_ItemClick(IInspectable const &sender,
                                                         ItemClickEventArgs const &e)
    {
        auto item = e.ClickedItem().as<UFCase::Identity>();
        
        co_await GlobalRes::MainNavServ().NavigateTo(L"Packages", PackagesPageNavigationContext::GetFromIdentity(item));
    }
} // namespace winrt::UFCase::implementation
