#pragma once

#include "ComponentsPageViewModel.g.h"

#include <winrt/Microsoft.UI.Xaml.Documents.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.System.h>

#include <winrt/UFCase.Isolation.h>

#include <filesystem>

#include "PropChgUtil.h"
#include "XamlUtil.h"

namespace winrt::UFCase::implementation
{
    struct ComponentsPageViewModel : ComponentsPageViewModelT<ComponentsPageViewModel>,
                                     ImplPropertyChangedT<ComponentsPageViewModel>
    {
        ComponentsPageViewModel(UFCase::ImageViewModel vm);

        ComponentsPageViewModelState State()
        {
            return m_state;
        }

        IAsyncActionWithProgress<uint32_t> PullData();

        Collections::IObservableVector<UFCase::ComponentViewModel> Components()
        {
            return m_components;
        }

        UFCase::ComponentViewModel SelectedComponent()
        {
            return m_selected;
        }

        void SelectedComponent(UFCase::ComponentViewModel value)
        {
            m_selected = value;
            NotifyPropChange(L"SelectedComponent");
        }

        HandleCommandAsync(ComponentShowManifest)
        {
            if (!m_selected)
                co_return;
            auto model = m_selected.Model();

            if (!GlobalRes::WindowServ().TryActivateWindow(model))
            {
                UFCase::AssemblyManifestViewerWindowViewModel wnd_vm{model};
                UFCase::AssemblyManifestViewerWindow viewer_wnd{wnd_vm};
                GlobalRes::WindowServ().RegisterWindow(model, viewer_wnd);

                viewer_wnd.Closed(
                    [model](auto &&, auto &&) { GlobalRes::WindowServ().UnregisterWindow(model); });

                viewer_wnd.Activate();
            }
        }

        HandleCommandAsync(ComponentShowInFileExplorer)
        {
            if (!m_selected)
                co_return;

            auto model = m_selected.Model();

            std::filesystem::path path = model.PayloadPath().c_str();
            if (!std::filesystem::exists(path))
            {
                co_return;
            }

            auto folder = co_await winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(
                path.c_str());

            co_await winrt::Windows::System::Launcher::LaunchFolderAsync(folder);

            co_return;
        }

      private:
        ComponentsPageViewModelState m_state{ComponentsPageViewModelState::Uninitialized};

        weak_ref<UFCase::ImageViewModel> m_image;

        UFCase::ComponentViewModel m_selected{nullptr};
        Collections::IObservableVector<UFCase::ComponentViewModel> m_components;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ComponentsPageViewModel
        : ComponentsPageViewModelT<ComponentsPageViewModel, implementation::ComponentsPageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
