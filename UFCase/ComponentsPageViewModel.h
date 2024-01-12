#pragma once

#include "ComponentsPageNavigationContext.g.h"
#include "ComponentsPageViewModel.g.h"

#include <winrt/Microsoft.UI.Xaml.Documents.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.System.h>

#include <winrt/UFCase.Isolation.h>

#include <winrt/UFCase.h>

#include <filesystem>

#include "PropChgUtil.h"
#include "XamlUtil.h"

namespace winrt::UFCase::implementation
{

    struct ComponentsPageNavigationContext
        : ComponentsPageNavigationContextT<ComponentsPageNavigationContext>
    {
        ComponentsPageNavigationContext() = default;
        static UFCase::ComponentsPageNavigationContext GetFromId(hstring const &val)
        {
            auto res = UFCase::ComponentsPageNavigationContext();
            res.Type(ComponentsPageNavigationContextType::SelectCompId);
            res.SelectCompId(val);
            return res;
        }
        static UFCase::ComponentsPageNavigationContext GetFromIdentity(UFCase::Identity const &val)
        {
            auto res = UFCase::ComponentsPageNavigationContext();
            res.Type(ComponentsPageNavigationContextType::SelectCompIdentity);
            res.SelectCompIdentity(val);
            return res;
        }

        ComponentsPageNavigationContextType Type()
        {
            return m_type;
        }
        void Type(ComponentsPageNavigationContextType const &value)
        {
            m_type = value;
        }

        hstring SelectCompId()
        {
            return m_select_comp_id;
        }
        void SelectCompId(hstring const &value)
        {
            m_select_comp_id = value;
        }

        UFCase::Identity SelectCompIdentity()
        {
            return m_select_comp_identity;
        }
        void SelectCompIdentity(UFCase::Identity const &value)
        {
            m_select_comp_identity = value;
        }

      private:
        ComponentsPageNavigationContextType m_type = ComponentsPageNavigationContextType::None;
        hstring m_select_comp_id;
        UFCase::Identity m_select_comp_identity;
    };

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

        UFCase::ComponentsPageNavigationContext NavContext()
        {
            return m_nav_context;
        }

        void NavContext(UFCase::ComponentsPageNavigationContext const &value)
        {
            m_nav_context = value;
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
        UFCase::ComponentsPageNavigationContext m_nav_context;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ComponentsPageNavigationContext
        : ComponentsPageNavigationContextT<ComponentsPageNavigationContext,
                                           implementation::ComponentsPageNavigationContext>
    {
    };

    struct ComponentsPageViewModel
        : ComponentsPageViewModelT<ComponentsPageViewModel, implementation::ComponentsPageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
