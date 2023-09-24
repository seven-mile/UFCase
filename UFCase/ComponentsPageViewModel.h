#pragma once

#include "ComponentsPageViewModel.g.h"

#include <winrt/Microsoft.UI.Xaml.Documents.h>

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
                UFCase::ManifestViewerWindowViewModel wnd_vm{model};
                UFCase::ManifestViewerWindow viewer_wnd{wnd_vm};
                GlobalRes::WindowServ().RegisterWindow(model, viewer_wnd);

                viewer_wnd.Closed(
                    [model](auto &&, auto &&) { GlobalRes::WindowServ().UnregisterWindow(model); });

                viewer_wnd.Activate();
            }
        }

        HandleCommandAsync(ComponentShowInFileExplorer)
        {
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
