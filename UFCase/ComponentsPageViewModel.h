#pragma once

#include "ComponentsPageNavigationContext.g.h"
#include "ComponentsPageViewModel.g.h"

#include <winrt/Microsoft.UI.Xaml.Documents.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.System.h>

#include <winrt/UFCase.Isolation.h>

#include <winrt/UFCase.h>

#include <filesystem>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "PropChgUtil.h"
#include "XamlUtil.h"

#include <wil/cppwinrt_authoring.h>

#include "ComponentViewModel.h"

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

        Collections::IObservableVector<UFCase::ComponentListItem> Components()
        {
            return m_components;
        }

        UFCase::ComponentListItem SelectedComponent()
        {
            return m_selected;
        }

        void SelectedComponent(UFCase::ComponentListItem value)
        {
            m_selected = value;
            m_selected_details = value ? EnsureComponentDetails(value) : nullptr;
            NotifyPropChange(L"SelectedComponent");
            NotifyPropChange(L"SelectedComponentDetails");
            NotifyPropChange(L"SelectedComponentName");
            NotifyPropChange(L"SelectedComponentKeyForm");
            NotifyPropChange(L"SelectedComponentPayloadPath");
        }

        UFCase::ComponentDetails SelectedComponentDetails()
        {
            return m_selected_details;
        }

        hstring SelectedComponentName()
        {
            return m_selected_details ? m_selected_details.Name() : L"";
        }

        hstring SelectedComponentKeyForm()
        {
            return m_selected_details ? m_selected_details.KeyForm() : L"";
        }

        hstring SelectedComponentPayloadPath()
        {
            return m_selected_details ? m_selected_details.PayloadPath() : L"";
        }

        fire_and_forget Navigate(UFCase::ComponentsPageNavigationContext const &nav_ctx);

        HandleCommandAsync(ComponentShowManifest)
        {
            if (!m_selected)
                co_return;
            auto model = SelectedComponentModel();
            if (!model)
            {
                co_return;
            }

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

            auto details = m_selected_details;
            if (!details)
                co_return;

            std::filesystem::path path = details.PayloadPath().c_str();
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
        struct ComponentRecord
        {
            uint32_t RecordId{};
            UFCase::ComponentListItem Item{nullptr};
            Isolation::ComponentModel Model{nullptr};
            std::optional<ComponentDetailsSnapshot> Details;
        };

        ComponentsPageViewModelState m_state{ComponentsPageViewModelState::Uninitialized};
        uint64_t m_load_generation{};

        weak_ref<UFCase::ImageViewModel> m_image;

        UFCase::ComponentListItem m_selected{nullptr};
        UFCase::ComponentDetails m_selected_details{nullptr};
        Collections::IObservableVector<UFCase::ComponentListItem> m_components;
        std::vector<ComponentRecord> m_records;
        std::unordered_map<uint32_t, size_t> m_record_index_by_id;
        std::unordered_map<std::wstring, uint32_t> m_record_id_by_name;
        UFCase::ComponentsPageNavigationContext m_nav_ctx;

        ComponentRecord *FindComponentRecord(uint32_t record_id);
        ComponentRecord *FindComponentRecord(UFCase::ComponentListItem const &item);
        Isolation::ComponentModel SelectedComponentModel();
        UFCase::ComponentDetails EnsureComponentDetails(UFCase::ComponentListItem const &item);
        bool MatchingComponent(ComponentRecord const &record);
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
