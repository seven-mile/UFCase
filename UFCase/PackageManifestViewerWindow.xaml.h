// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "PackageManifestViewerWindow.g.h"

namespace winrt::UFCase::implementation
{
    struct PackageManifestViewerWindow : PackageManifestViewerWindowT<PackageManifestViewerWindow>
    {
        PackageManifestViewerWindow(UFCase::PackageManifestViewerWindowViewModel view_model);

        void InitializeComponent();

        UFCase::PackageManifestViewerWindowViewModel ViewModel()
        {
            return m_view_model;
        }

        fire_and_forget ListView_ItemClick(IInspectable const &sender,
                                ItemClickEventArgs const &e);

      private:
        UFCase::PackageManifestViewerWindowViewModel m_view_model;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct PackageManifestViewerWindow
        : PackageManifestViewerWindowT<PackageManifestViewerWindow,
                                       implementation::PackageManifestViewerWindow>
    {
    };
} // namespace winrt::UFCase::factory_implementation
