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

    fire_and_forget PackageManifestViewerWindow::ListView_ItemClick_Package(
        IInspectable const &sender, ItemClickEventArgs const &e)
    {
        apartment_context ui_thread;
        auto item = e.ClickedItem().as<UFCase::Identity>();

        co_await GlobalRes::MainNavServ().NavigateTo(
            L"Packages", PackagesPageNavigationContext::GetFromIdentity(item));

        co_await ui_thread;

        GlobalRes::MainWnd().Activate();
    }

    fire_and_forget PackageManifestViewerWindow::ListView_ItemClick_Component(
        IInspectable const &sender, ItemClickEventArgs const &e)
    {
        apartment_context ui_thread;
        auto item = e.ClickedItem().as<UFCase::Identity>();

        co_await GlobalRes::MainNavServ().NavigateTo(
            L"Components", ComponentsPageNavigationContext::GetFromIdentity(item));

        co_await ui_thread;

        GlobalRes::MainWnd().Activate();
    }

} // namespace winrt::UFCase::implementation
