#pragma once

#include "PackagesPageNavigationContext.g.h"
#include "PackagesPageViewModel.g.h"

#include <winrt/Windows.Storage.h>
#include <winrt/Microsoft.UI.Xaml.Documents.h>
#include <winrt/UFCase.Isolation.h>

#include "XamlUtil.h"
#include "PropChgUtil.h"

#include <ShlObj.h>

#include <fstream>
#include <filesystem>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>
#include <wil/stl.h>
#include <wil/cppwinrt_authoring.h>

#include "PackageViewModel.h"

namespace winrt::UFCase::implementation
{

    struct PackagesPageNavigationContext
        : PackagesPageNavigationContextT<PackagesPageNavigationContext>
    {
        PackagesPageNavigationContext() = default;

        static UFCase::PackagesPageNavigationContext GetFromId(hstring const &val)
        {
            auto res = UFCase::PackagesPageNavigationContext();
            res.Type(PackagesPageNavigationContextType::SelectPkgStringId);
            res.SelectPkgStringId(val);
            return res;
        }

        static UFCase::PackagesPageNavigationContext GetFromIdentity(UFCase::Identity const &val)
        {
            auto res = UFCase::PackagesPageNavigationContext();
            res.Type(PackagesPageNavigationContextType::SelectPkgIdentity);
            res.SelectPkgIdentity(val);
            return res;
        }

        wil::single_threaded_rw_property<PackagesPageNavigationContextType> Type = PackagesPageNavigationContextType::None;
        wil::single_threaded_rw_property<hstring> SelectPkgStringId;
        wil::single_threaded_rw_property<UFCase::Identity> SelectPkgIdentity;
    };

    // Stateful: change the state by Self::Navigate
    struct PackagesPageViewModel : PackagesPageViewModelT<PackagesPageViewModel>,
                                   ImplPropertyChangedT<PackagesPageViewModel>
    {
        PackagesPageViewModel(UFCase::ImageViewModel image) : m_image(image)
        {
        }

        PackagesPageViewModel(UFCase::ImageViewModel image,
                              UFCase::PackagesPageNavigationContext nav_ctx)
            : m_image(image), m_nav_ctx(nav_ctx)
        {
        }

        PackagesPageViewModelState State()
        {
            return m_state;
        }

        UFCase::ImageViewModel Image()
        {
            return m_image.get();
        }

        IObservableVector<UFCase::PackageListItem> Packages()
        {
            return m_packages;
        }

        UFCase::PackageListItem SelectedPackage()
        {
            return m_selected;
        }

        void SelectedPackage(UFCase::PackageListItem value)
        {
            m_selected = value;
            m_selected_details = value ? EnsurePackageDetails(value) : nullptr;
            NotifyPropChange(L"SelectedPackage");
            NotifyPropChange(L"SelectedPackageDetails");
            NotifyPropChange(L"SelectedPackageDetailName");
            NotifyPropChange(L"SelectedPackageDetailIdentity");
            NotifyPropChange(L"SelectedPackageDescription");
            NotifyPropChange(L"SelectedPackageInstallTime");
            NotifyPropChange(L"SelectedPackageInstallClient");
        }

        UFCase::PackageDetails SelectedPackageDetails()
        {
            return m_selected_details;
        }

        hstring SelectedPackageDetailName()
        {
            return m_selected_details ? m_selected_details.DetailName() : L"";
        }

        hstring SelectedPackageDetailIdentity()
        {
            return m_selected_details ? m_selected_details.DetailIdentity() : L"";
        }

        hstring SelectedPackageDescription()
        {
            return m_selected_details ? m_selected_details.Description() : L"";
        }

        hstring SelectedPackageInstallTime()
        {
            return m_selected_details ? m_selected_details.InstallTime() : L"";
        }

        hstring SelectedPackageInstallClient()
        {
            return m_selected_details ? m_selected_details.InstallClient() : L"";
        }

        fire_and_forget Navigate(UFCase::PackagesPageNavigationContext const &nav_ctx);

        wil::typed_event<UFCase::PackagesPageViewModel, UFCase::PackagesPageNavigationContext> Navigated;

        HandleCommandAsync(PackageShowManifest)
        {
            if (!m_selected)
                co_return;

            auto m_model = SelectedPackageModel();
            if (!m_model)
            {
                co_return;
            }

            if (!GlobalRes::WindowServ().TryActivateWindow(m_model))
            {
                UFCase::PackageManifestViewerWindowViewModel vm{m_model};
                UFCase::PackageManifestViewerWindow wnd{vm};

                GlobalRes::WindowServ().RegisterWindow(m_model, wnd);

                wnd.Closed(
                    [=](auto &&, auto &&) { GlobalRes::WindowServ().UnregisterWindow(m_model); });

                wnd.Activate();
            }
        }

        HandleCommand(PackageShowInFileExplorer)
        {
            if (!m_selected)
            {
                return;
            }

#pragma warning(push)
#pragma warning(disable : 4090)
            auto details = m_selected_details;
            ITEMIDLIST *pidl = details ? ILCreateFromPath(details.ManifestFilePath().c_str()) : nullptr;
            if (pidl)
            {
                LOG_IF_FAILED(SHOpenFolderAndSelectItems(pidl, 0, 0, 0));
                ILFree(pidl);
            }
#pragma warning(pop)
        }

        HandleCommand(PackageShowInRegistry)
        {
            if (!m_selected)
            {
                return;
            }

            auto details = m_selected_details;
            if (!details)
            {
                return;
            }

            ::RegSetKeyValue(HKEY_CURRENT_USER,
                             L"Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit",
                             L"LastKey", REG_SZ, details.RegistryPath().c_str(),
                             (details.RegistryPath().size() + 1) * sizeof(wchar_t));

            ::ShellExecute(nullptr, L"open", L"regedit", L"", L"", SW_SHOW);
            LOG_IF_FAILED(HRESULT_FROM_WIN32(GetLastError()));
        }

      private:
        struct PackageRecord
        {
            uint32_t RecordId{};
            UFCase::PackageListItem Item{nullptr};
            Isolation::PackageModel Model{nullptr};
            std::optional<PackageDetailsSnapshot> Details;
        };

        PackagesPageViewModelState m_state{PackagesPageViewModelState::Uninitialized};
        uint64_t m_load_generation{};
        weak_ref<UFCase::ImageViewModel> m_image{nullptr};
        IObservableVector<UFCase::PackageListItem> m_packages{nullptr};
        std::vector<PackageRecord> m_records;
        std::unordered_map<uint32_t, size_t> m_record_index_by_id;
        std::unordered_map<std::wstring, uint32_t> m_record_id_by_identity;
        UFCase::PackageListItem m_selected{nullptr};
        UFCase::PackageDetails m_selected_details{nullptr};
        UFCase::PackagesPageNavigationContext m_nav_ctx;

        PackageRecord *FindPackageRecord(uint32_t record_id);
        PackageRecord *FindPackageRecord(UFCase::PackageListItem const &item);
        Isolation::PackageModel SelectedPackageModel();
        UFCase::PackageDetails EnsurePackageDetails(UFCase::PackageListItem const &item);
        bool MatchingPackage(PackageRecord const &record);
        IAsyncActionWithProgress<uint32_t> PullData(apartment_context ui_thread);
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPageViewModel
        : PackagesPageViewModelT<PackagesPageViewModel, implementation::PackagesPageViewModel>
    {
    };

    struct PackagesPageNavigationContext
        : PackagesPageNavigationContextT<PackagesPageNavigationContext,
                                         implementation::PackagesPageNavigationContext>
    {
    };
} // namespace winrt::UFCase::factory_implementation
