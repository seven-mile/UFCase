// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "AssemblyManifestViewerWindow.g.h"

namespace winrt::UFCase::implementation
{
    struct AssemblyManifestViewerWindow : AssemblyManifestViewerWindowT<AssemblyManifestViewerWindow>
    {
        AssemblyManifestViewerWindow(UFCase::AssemblyManifestViewerWindowViewModel view_model);

        void InitializeComponent();

        UFCase::AssemblyManifestViewerWindowViewModel ViewModel()
        {
            return m_view_model;
        }

        UFCase::AssemblyManifestViewerWindowViewModel m_view_model;

        fire_and_forget ListView_ItemClick_Component(IInspectable const &sender,
                                                     ItemClickEventArgs const &e);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct AssemblyManifestViewerWindow : AssemblyManifestViewerWindowT<AssemblyManifestViewerWindow, implementation::AssemblyManifestViewerWindow>
    {
    };
}
