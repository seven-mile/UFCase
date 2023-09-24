#include "pch.h"
#include "ManifestViewerWindowViewModel.h"
#if __has_include("ManifestViewerWindowViewModel.g.cpp")
#include "ManifestViewerWindowViewModel.g.cpp"
#endif

namespace winrt::UFCase::implementation
{
    using namespace Windows::Data::Xml::Dom;

    ManifestViewerWindowViewModel::ManifestViewerWindowViewModel(
        UFCase::Isolation::ComponentModel model)
        : m_asm(UFCase::ManifestAssemblyViewModel(model)), m_model(model)
    {
    }
} // namespace winrt::UFCase::implementation
