#pragma once

#include "FeaturesPageViewModel.g.h"
#include "ImageViewModel.g.h"

#include "SessionModel.h"
#include "PackageModel.h"

#include "XamlUtil.h"

#include <winrt/Windows.ApplicationModel.DataTransfer.h>
#include <winrt/Windows.System.h>

#include <wil/resource.h>
#include <filesystem>

namespace winrt::UFCase::implementation
{
    struct FeaturesPageViewModel : FeaturesPageViewModelT<FeaturesPageViewModel>
    {
        FeaturesPageViewModel(ImageViewModel image): m_image(image) { }

        ImageViewModel Image() { return m_image; }
        IObservableVector<FeatureViewModel> RootFeatures() { return m_features; }

        IAsyncActionWithProgress<uint32_t> PullData();

        // implement INotifyPropertyChanged
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value) {
            return m_property_changed.add(value);
        }

        void PropertyChanged(winrt::event_token const& token) {
            m_property_changed.remove(token);
        }

        FeatureViewModel SelectedFeature() {
            return m_selected;
        }

        void SelectedFeature(FeatureViewModel feature) {
            m_selected = feature;
            m_property_changed(*this, Data::PropertyChangedEventArgs{ L"SelectedFeature" });

            NotifyCommandsCanExecuteChanged();
        }

        HandleCommandEx(FeatureEnable, L"Enable", L"\xE78C", [this](IInspectable) {
            if (!m_selected) return false;
            auto&& state = m_selected.State();
            return state != FeatureState::PartiallyEnabled
                && state != FeatureState::Enabled;
        }) {
            if (!m_selected) return;
            m_selected.Enable();

            NotifyCommandsCanExecuteChanged();
        }

        HandleCommandEx(FeatureDisable, L"Disable", L"\xE74D", [this](IInspectable) {
            if (!m_selected) return false;
            auto&& state = m_selected.State();
            return state == FeatureState::PartiallyEnabled
                || state == FeatureState::Enabled;
        }) {
            if (!m_selected) return;
            m_selected.Disable();

            NotifyCommandsCanExecuteChanged();
        }

        HandleCommandAsync(FeatureOpenExplorer, L"Open in explorer", L"\xE8DA") {
            auto target = m_selected.Package().InstallLocation();
            if (target == L"" || !std::filesystem::exists(target.c_str())) {
                ContentDialog cd;
                cd.XamlRoot(GlobalRes::MainWnd().Content().XamlRoot());
                cd.Title(box_value(L"Cannot open file"));
                cd.Content(box_value(L"This package have no valid file path."));
                cd.PrimaryButtonText(L"OK");
                cd.DefaultButton(ContentDialogButton::Primary);
                co_await cd.ShowAsync();

                co_return;
            }
            ShellExecute(nullptr, L"open", L"explorer", std::format(L"/select, {}", target.c_str()).c_str(), nullptr, SW_SHOW);
        }

        HandleCommandAsync(FeatureOpenRegistry, L"Open in registry", L"") {
            ContentDialog cd;
            cd.XamlRoot(GlobalRes::MainWnd().Content().XamlRoot());
            cd.Title(box_value(L"Not supported"));
            cd.Content(box_value(L"Cannot find registry entry for this package."));
            cd.PrimaryButtonText(L"OK");
            cd.DefaultButton(ContentDialogButton::Primary);
            co_await cd.ShowAsync();
        }

        HandleCommand(FeatureGetPackage, L"Goto package", L"\xE950") {
            UFCase::PackagesPageNavigationContext ctx;
            ctx.SelectPkgId(m_selected.ContentPackage().DetailIdentity());
            GlobalRes::MainNavServ().NavigateTo(L"Packages", ctx);
        }

        HandleCommand(FeatureSystemUI, L"OptionalFeatures.exe", L"\xE72B") {
            ShellExecute(nullptr, L"open", L"OptionalFeatures.exe", L"", L"", SW_SHOW);
        }

        HandleCommand(FeatureAddSourceUI, L"Add source", Symbol::Add) {
            static AddSourceContentDialog addSrcDlg{};

            addSrcDlg.XamlRoot(GlobalRes::MainWnd().Content().XamlRoot());
            addSrcDlg.ShowAsync().Completed([](auto const& op, auto const&) {
                if (op.GetResults() == ContentDialogResult::Primary) {
                    if (auto path = std::filesystem::path(addSrcDlg.SourcePath().c_str());
                        std::filesystem::exists(path) && std::filesystem::is_directory(path)) {

                        OutputDebugString(std::format(L"added install source path: \"{}\"", path.c_str()).c_str());
                    } else {
                        OutputDebugString(L"error: invalid path provided!");
                    }
                } else {
                    return;
                }
            });
        }

        HandleCommandAsync(Commit, L"Save changes", Symbol::Save) {
            apartment_context ui_thread;
            // set change flag to save updates
            Session().FoundationPackage()->Install();
            co_await GlobalRes::MainProgServ().InsertTask(Session().SaveChanges(), 200);

            // dispose the finalized session
            m_image.CloseSession(m_session);
            m_session = 0;

            co_await ui_thread;

            // clear all packages and updates, which is not usable anymore
            Refresh_cmd.Execute(nullptr);

            co_return;
        }

        HandleCommandAsync(Refresh, L"Refresh", Symbol::Refresh) {
            // clear selection
            m_selected = nullptr;
            m_property_changed(*this, Data::PropertyChangedEventArgs{ L"SelectedFeature" });

            co_await GlobalRes::MainProgServ().InsertTask(PullData(), 100);
            co_return;
        }

    private:

        ImageViewModel m_image{nullptr};
        IObservableVector<FeatureViewModel> m_features{nullptr};
        FeatureViewModel m_selected{nullptr};
        uint64_t m_session = 0;

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_property_changed{};

        uint64_t SessionHandle() {
            if (m_session) return m_session;
            return m_session = m_image.OpenSession();
        }

        SessionModel &Session() {
            return SessionModel::GetInstance(SessionHandle());
        }

        void NotifyCommandsCanExecuteChanged() {
            FeatureEnableCommand().NotifyCanExecuteChanged();
            FeatureDisableCommand().NotifyCanExecuteChanged();
        }
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeaturesPageViewModel : FeaturesPageViewModelT<FeaturesPageViewModel, implementation::FeaturesPageViewModel>
    {
    };
}
