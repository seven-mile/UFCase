#pragma once

#include "ComponentViewModel.g.h"

#include "ComponentModel.h"

#include "CacheUtil.h"
#include "PropChgUtil.h"

namespace winrt::UFCase::implementation
{
    struct ComponentViewModel : ComponentViewModelT<ComponentViewModel>,
                                ImplPropertyChangedT<ComponentViewModel>
    {
        ComponentViewModel(uint64_t handle);

        hstring TextFormRaw();
        hstring KeyFormRaw();

        hstring NameRaw();
        hstring CultureRaw();
        hstring VersionRaw();
        hstring PublicKeyTokenRaw();
        hstring ProcessorArchitectureRaw();
        hstring VersionScopeRaw();

        hstring ManifestRaw();

        hstring StatusRaw();
        hstring PayloadPathRaw();

        Collections::IObservableVector<ComponentFileViewModel> FilesRaw();

        // clang-format off
        PropertyCache<hstring, ComponentViewModel> TextForm{*this, &ComponentViewModel::TextFormRaw};
        PropertyCache<hstring, ComponentViewModel> KeyForm{*this, &ComponentViewModel::KeyFormRaw};
        PropertyCache<hstring, ComponentViewModel> Name{*this, &ComponentViewModel::NameRaw};
        PropertyCache<hstring, ComponentViewModel> Culture{*this, &ComponentViewModel::CultureRaw};
        PropertyCache<hstring, ComponentViewModel> Version{*this, &ComponentViewModel::VersionRaw};
        PropertyCache<hstring, ComponentViewModel> PublicKeyToken{*this, &ComponentViewModel::PublicKeyTokenRaw};
        PropertyCache<hstring, ComponentViewModel> ProcessorArchitecture{*this, &ComponentViewModel::ProcessorArchitectureRaw};
        PropertyCache<hstring, ComponentViewModel> VersionScope{*this, &ComponentViewModel::VersionScopeRaw};
        PropertyCache<hstring, ComponentViewModel> Manifest{*this, &ComponentViewModel::ManifestRaw};
        PropertyCache<hstring, ComponentViewModel> Status{*this, &ComponentViewModel::StatusRaw};
        PropertyCache<hstring, ComponentViewModel> PayloadPath{*this, &ComponentViewModel::PayloadPathRaw};
        PropertyCache<Collections::IObservableVector<ComponentFileViewModel>, ComponentViewModel> Files{*this, &ComponentViewModel::FilesRaw};
        // clang-format on

      private:
        ComponentModel m_model;

        void Prefetch()
        {
            TextForm();
            KeyForm();
            Manifest();
            Status();
            PayloadPath();
            Files();
        }
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ComponentViewModel
        : ComponentViewModelT<ComponentViewModel, implementation::ComponentViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
