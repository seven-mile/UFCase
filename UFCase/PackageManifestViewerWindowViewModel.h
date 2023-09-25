#pragma once

#include "PackageManifestViewerWindowViewModel.g.h"

#include <PropChgUtil.h>

namespace winrt::UFCase::implementation
{
    struct PackageManifestViewerWindowViewModel
        : PackageManifestViewerWindowViewModelT<PackageManifestViewerWindowViewModel>,
          ImplPropertyChangedT<PackageManifestViewerWindowViewModel>
    {
        PackageManifestViewerWindowViewModel(UFCase::Isolation::PackageModel model);

        hstring ManifestText()
        {
            return m_manifest_text;
        }

        hstring Title()
        {
            return m_title;
        }

        IObservableVector<UFCase::Identity> Components()
        {
            return m_components;
        }

        IObservableVector<UFCase::Identity> Packages()
        {
            return m_packages;
        }

        IObservableVector<UFCase::Identity> Drivers()
        {
            return m_drivers;
        }

        IObservableVector<UFCase::Identity> Parents()
        {
            return m_parents;
        }

        IAsyncActionWithProgress<uint32_t> PullData();

      private:
        UFCase::Isolation::PackageModel m_model;
        hstring m_manifest_text;
        hstring m_title;

        IObservableVector<UFCase::Identity> m_components{nullptr};
        IObservableVector<UFCase::Identity> m_packages{nullptr};
        IObservableVector<UFCase::Identity> m_drivers{nullptr};
        IObservableVector<UFCase::Identity> m_parents{nullptr};

        IAsyncActionWithProgress<uint32_t> ParseManifest(Windows::Storage::StorageFile);
        UFCase::Identity ParseIdentity(Windows::Data::Xml::Dom::IXmlNode node, IdentityType type);
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct PackageManifestViewerWindowViewModel
        : PackageManifestViewerWindowViewModelT<
              PackageManifestViewerWindowViewModel,
              implementation::PackageManifestViewerWindowViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
