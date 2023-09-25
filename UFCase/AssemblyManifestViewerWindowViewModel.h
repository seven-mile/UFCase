#pragma once

#include "AssemblyManifestViewerWindowViewModel.g.h"

#include <winrt/Windows.Data.Xml.Dom.h>

namespace winrt::UFCase::implementation
{
    struct AssemblyManifestViewerWindowViewModel
        : AssemblyManifestViewerWindowViewModelT<AssemblyManifestViewerWindowViewModel>
    {
        AssemblyManifestViewerWindowViewModel(UFCase::Isolation::ComponentModel model);

        UFCase::ManifestAssemblyViewModel Assembly()
        {
            return m_asm;
        }

        hstring ManifestText()
        {
            return m_model.Manifest();
        }

      private:
        UFCase::Isolation::ComponentModel m_model;
        UFCase::ManifestAssemblyViewModel m_asm{nullptr};
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct AssemblyManifestViewerWindowViewModel
        : AssemblyManifestViewerWindowViewModelT<AssemblyManifestViewerWindowViewModel,
                                         implementation::AssemblyManifestViewerWindowViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
