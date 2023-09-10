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

        hstring ManifestRaw();

        hstring StatusRaw();
        hstring PayloadPathRaw();

        Collections::IObservableVector<ComponentFileViewModel> FilesRaw();

        // clang-format off
        PropertyCache<hstring, ComponentViewModel> TextForm{*this, &ComponentViewModel::TextFormRaw};
        PropertyCache<hstring, ComponentViewModel> KeyForm{*this, &ComponentViewModel::KeyFormRaw};
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
