#include "pch.h"
#include "AssemblyManifestViewerWindowViewModel.h"
#if __has_include("AssemblyManifestViewerWindowViewModel.g.cpp")
#include "AssemblyManifestViewerWindowViewModel.g.cpp"
#endif

namespace winrt::UFCase::implementation
{
    using namespace Windows::Data::Xml::Dom;

    AssemblyManifestViewerWindowViewModel::AssemblyManifestViewerWindowViewModel(
        UFCase::Isolation::ComponentModel model)
        : m_asm(UFCase::ManifestAssemblyViewModel(model)), m_model(model)
    {
    }
} // namespace winrt::UFCase::implementation
