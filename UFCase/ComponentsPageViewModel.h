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

#include <wil/cppwinrt_authoring.h>

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

        wil::single_threaded_rw_property<ComponentsPageNavigationContextType> Type =
            ComponentsPageNavigationContextType::None;
        wil::single_threaded_rw_property<hstring> SelectCompId;
        wil::single_threaded_rw_property<UFCase::Identity> SelectCompIdentity;
    };

    struct ComponentsPageViewModel : ComponentsPageViewModelT<ComponentsPageViewModel>,
                                     ImplPropertyChangedT<ComponentsPageViewModel>
    {
        ComponentsPageViewModel(UFCase::ImageViewModel vm);

        ComponentsPageViewModelState State()
        {
            return m_state;
        }

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

        fire_and_forget Navigate(UFCase::ComponentsPageNavigationContext const &nav_ctx);

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

        wil::typed_event<UFCase::ComponentsPageViewModel, UFCase::ComponentsPageNavigationContext>
            Navigated;

      private:
        ComponentsPageViewModelState m_state{ComponentsPageViewModelState::Uninitialized};

        weak_ref<UFCase::ImageViewModel> m_image;

        UFCase::ComponentViewModel m_selected{nullptr};
        Collections::IObservableVector<UFCase::ComponentViewModel> m_components;
        UFCase::ComponentsPageNavigationContext m_nav_ctx;

        bool MatchingComponent(UFCase::ComponentViewModel const &vm);
        IAsyncActionWithProgress<uint32_t> PullData(apartment_context);
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
