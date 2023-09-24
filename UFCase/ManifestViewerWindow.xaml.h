// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "ManifestViewerWindow.g.h"

namespace winrt::UFCase::implementation
{
    struct ManifestViewerWindow : ManifestViewerWindowT<ManifestViewerWindow>
    {
        ManifestViewerWindow(UFCase::ManifestViewerWindowViewModel view_model);

        UFCase::ManifestViewerWindowViewModel ViewModel()
        {
            return m_view_model;
        }

        UFCase::ManifestViewerWindowViewModel m_view_model;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct ManifestViewerWindow : ManifestViewerWindowT<ManifestViewerWindow, implementation::ManifestViewerWindow>
    {
    };
}
