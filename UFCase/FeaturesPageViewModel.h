#pragma once

#include "FeaturesPageViewModel.g.h"
#include "ImageViewModel.g.h"

#include "FeatureTreeItem.h"
#include "PropChgUtil.h"
#include "XamlUtil.h"

#include <winrt/Windows.ApplicationModel.DataTransfer.h>
#include <winrt/Windows.System.h>

#include <filesystem>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    struct FeaturesPageViewModel : FeaturesPageViewModelT<FeaturesPageViewModel>,
                                   ImplPropertyChangedT<FeaturesPageViewModel>
    {
        FeaturesPageViewModel(ImageViewModel image) : m_image(image)
        {
            m_features = multi_threaded_observable_vector<UFCase::FeatureTreeItem>();
        }

        FeaturesPageViewModelState State()
        {
            return m_state;
        }

        ImageViewModel Image()
        {
            return m_image.get();
        }

        IObservableVector<UFCase::FeatureTreeItem> RootFeatures()
        {
            return m_features;
        }

        IAsyncActionWithProgress<uint32_t> PullData();

        UFCase::FeatureTreeItem SelectedFeature()
        {
            return m_selected;
        }

        void SelectedFeature(UFCase::FeatureTreeItem feature)
        {
            m_selected = feature;
            m_selected_details = feature ? EnsureFeatureDetails(feature) : nullptr;
            NotifyPropChange(L"SelectedFeature");
            NotifyPropChange(L"SelectedFeatureDetails");
            NotifyCommandsCanExecuteChanged();
        }

        UFCase::FeatureDetails SelectedFeatureDetails()
        {
            return m_selected_details;
        }

        HandleCommandEx(FeatureEnable, [this](IInspectable) {
            if (!m_selected)
                return false;
            auto state = m_selected.State();
            return state != FeatureState::PartiallyEnabled && state != FeatureState::Enabled;
        })
        {
            if (auto record = SelectedFeatureRecord())
            {
                record->Model.Enable();
                RefreshFeatureRecord(*record);
            }
            NotifyCommandsCanExecuteChanged();
        }

        HandleCommandEx(FeatureDisable, [this](IInspectable) {
            if (!m_selected)
                return false;
            auto state = m_selected.State();
            return state == FeatureState::PartiallyEnabled || state == FeatureState::Enabled;
        })
        {
            if (auto record = SelectedFeatureRecord())
            {
                record->Model.Disable();
                RefreshFeatureRecord(*record);
            }
            NotifyCommandsCanExecuteChanged();
        }

        HandleCommandEx(FeatureGotoPackage, [this](IInspectable) { return !!m_selected; })
        {
            if (!m_selected)
            {
                return;
            }

            auto details = m_selected_details ? m_selected_details : EnsureFeatureDetails(m_selected);
            if (!details)
            {
                return;
            }

            auto nav_ctx = PackagesPageNavigationContext::GetFromId(
                details.ContentPackageIdentity());
            GlobalRes::MainNavServ().NavigateTo(L"Packages", nav_ctx);
        }

        HandleCommand(FeatureSystem)
        {
            ShellExecute(nullptr, L"open", L"OptionalFeatures.exe", L"", L"", SW_SHOW);
        }

        HandleCommand(FeatureAddSource)
        {
            static AddSourceContentDialog addSrcDlg{};

            addSrcDlg.XamlRoot(GlobalRes::MainWnd().Content().XamlRoot());
            addSrcDlg.ShowAsync().Completed([](auto const &op, auto const &) {
                if (op.GetResults() == ContentDialogResult::Primary)
                {
                    if (auto path = std::filesystem::path(addSrcDlg.SourcePath().c_str());
                        std::filesystem::exists(path) && std::filesystem::is_directory(path))
                    {
                        OutputDebugString(
                            std::format(L"added install source path: \"{}\"", path.c_str())
                                .c_str());
                    }
                    else
                    {
                        OutputDebugString(L"error: invalid path provided!");
                    }
                }
            });
        }

        HandleCommandAsync(Commit)
        {
            apartment_context ui_thread;
            Session().FoundationPackage().Install();
            co_await GlobalRes::MainProgServ().InsertTask(Session().SaveChanges(), 200);

            m_session = nullptr;

            co_await ui_thread;
            RefreshRelay().Execute(nullptr);

            co_return;
        }

        HandleCommandAsync(Refresh)
        {
            m_selected = nullptr;
            m_selected_details = nullptr;
            NotifyPropChange(L"SelectedFeature");
            NotifyPropChange(L"SelectedFeatureDetails");

            co_await GlobalRes::MainProgServ().InsertTask(PullData(), 100);
            co_return;
        }

      private:
        struct FeatureRecord
        {
            uint32_t RecordId{};
            UFCase::FeatureTreeItem Item{nullptr};
            Isolation::FeatureModel Model{nullptr};
            uint32_t ParentRecordId{};
            std::vector<uint32_t> ChildRecordIds;
            std::optional<FeatureDetailsSnapshot> Details;
        };

        FeaturesPageViewModelState m_state{FeaturesPageViewModelState::Uninitialized};
        uint64_t m_load_generation{};

        weak_ref<ImageViewModel> m_image{nullptr};
        IObservableVector<UFCase::FeatureTreeItem> m_features{nullptr};
        std::vector<FeatureRecord> m_records;
        std::unordered_map<uint32_t, size_t> m_record_index_by_id;
        std::unordered_map<std::wstring, uint32_t> m_record_id_by_name;
        UFCase::FeatureTreeItem m_selected{nullptr};
        UFCase::FeatureDetails m_selected_details{nullptr};
        Isolation::SessionModel m_session{nullptr};

        Isolation::SessionModel Session()
        {
            if (m_session)
            {
                return m_session;
            }
            return m_session = m_image.get().OpenSession();
        }

        FeatureRecord *FindFeatureRecord(uint32_t record_id);
        FeatureRecord *FindFeatureRecord(UFCase::FeatureTreeItem const &item);
        FeatureRecord *SelectedFeatureRecord();
        UFCase::FeatureDetails EnsureFeatureDetails(UFCase::FeatureTreeItem const &item);
        void RefreshFeatureRecord(FeatureRecord &record);

        void NotifyCommandsCanExecuteChanged()
        {
            FeatureEnableRelay().NotifyCanExecuteChanged();
            FeatureDisableRelay().NotifyCanExecuteChanged();
            FeatureGotoPackageRelay().NotifyCanExecuteChanged();
        }
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPageViewModel
        : FeaturesPageViewModelT<FeaturesPageViewModel, implementation::FeaturesPageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
