#pragma once

#include "ManifestAssemblyViewModel.g.h"

#include "PropChgUtil.h"

namespace winrt::UFCase::implementation
{
    enum class ManifestAssemblyViewModelState
    {
        Uninitialized,
        Loading,
        Idle,
    };

    struct ManifestAssemblyViewModel : ManifestAssemblyViewModelT<ManifestAssemblyViewModel>,
                                       ImplPropertyChangedT<ManifestAssemblyViewModel>
    {
        ManifestAssemblyViewModel(UFCase::Isolation::ComponentModel model) : m_model(model)
        {
        }

        hstring Name()
        {
            return m_name;
        };

        hstring ManifestText()
        {
            return m_manifest_text;
        }

        IObservableVector<FileItem> FileItems()
        {
            return m_files;
        }

        IObservableVector<RegItem> RegItems()
        {
            return m_regs;
        }

        IObservableVector<hstring> DependentAssemblies()
        {
            return m_deps;
        }

        IAsyncActionWithProgress<uint32_t> PullData();

        fire_and_forget LocateDependentAssembly(int32_t index);

      private:
        UFCase::Isolation::ComponentModel m_model;
        UFCase::Host::Manifest::Assembly m_asm{nullptr};

        ManifestAssemblyViewModelState m_state = ManifestAssemblyViewModelState::Uninitialized;

        hstring m_name;
        hstring m_manifest_text;
        IObservableVector<FileItem> m_files{nullptr};
        IObservableVector<RegItem> m_regs{nullptr};
        IObservableVector<hstring> m_deps{nullptr};
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ManifestAssemblyViewModel
        : ManifestAssemblyViewModelT<ManifestAssemblyViewModel,
                                     implementation::ManifestAssemblyViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
