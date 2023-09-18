#pragma once

#include "FeaturesPageViewModel.g.h"
#include "ImageViewModel.g.h"

#include "XamlUtil.h"
#include "PropChgUtil.h"

#include <winrt/Windows.ApplicationModel.DataTransfer.h>
#include <winrt/Windows.System.h>

#include <wil/resource.h>
#include <filesystem>

namespace winrt::UFCase::implementation
{
    struct FeaturesPageViewModel : FeaturesPageViewModelT<FeaturesPageViewModel>,
                                   ImplPropertyChangedT<FeaturesPageViewModel>
    {
        FeaturesPageViewModel(ImageViewModel image) : m_image(image)
        {
        }

        FeaturesPageViewModelState State()
        {
            return m_state;
        }

        ImageViewModel Image()
        {
            return m_image.get();
        }
        IObservableVector<FeatureViewModel> RootFeatures()
        {
            return m_features;
        }

        IAsyncActionWithProgress<uint32_t> PullData();

        FeatureViewModel SelectedFeature()
        {
            return m_selected;
        }

        void SelectedFeature(FeatureViewModel feature)
        {
            m_selected = feature;
            NotifyPropChange(L"SelectedFeature");

            NotifyCommandsCanExecuteChanged();
        }

        HandleCommandEx(FeatureEnable, [this](IInspectable) {
            if (!m_selected)
                return false;
            auto &&state = m_selected.State();
            return state != FeatureState::PartiallyEnabled && state != FeatureState::Enabled;
        })
        {
            if (!m_selected)
                return;
            m_selected.Enable();

            NotifyCommandsCanExecuteChanged();
        }

        HandleCommandEx(FeatureDisable, [this](IInspectable) {
            if (!m_selected)
                return false;
            auto &&state = m_selected.State();
            return state == FeatureState::PartiallyEnabled || state == FeatureState::Enabled;
        })
        {
            if (!m_selected)
                return;
            m_selected.Disable();

            NotifyCommandsCanExecuteChanged();
        }

        HandleCommandEx(FeatureGotoPackage, [this](IInspectable) { return !!m_selected; })
        {
            if (!m_selected)
            {
                return;
            }

            UFCase::PackagesPageNavigationContext ctx;
            ctx.SelectPkgId(m_selected.ContentPackage().DetailIdentity());

            GlobalRes::MainNavServ().NavigateTo(L"Packages", ctx);
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
                else
                {
                    return;
                }
            });
        }

        HandleCommandAsync(Commit)
        {
            apartment_context ui_thread;
            // set change flag to save updates
            Session().FoundationPackage().Install();
            co_await GlobalRes::MainProgServ().InsertTask(Session().SaveChanges(), 200);

            // dispose the finalized session
            m_session = nullptr;

            co_await ui_thread;

            // clear all packages and updates, which is not usable anymore
            Refresh_cmd.Execute(nullptr);

            co_return;
        }

        HandleCommandAsync(Refresh)
        {
            // clear selection
            m_selected = nullptr;
            NotifyPropChange(L"SelectedFeature");

            co_await GlobalRes::MainProgServ().InsertTask(PullData(), 100);
            co_return;
        }

      private:
        FeaturesPageViewModelState m_state{FeaturesPageViewModelState::Uninitialized};

        weak_ref<ImageViewModel> m_image{nullptr};
        IObservableVector<FeatureViewModel> m_features{nullptr};
        FeatureViewModel m_selected{nullptr};
        Isolation::SessionModel m_session{nullptr};

        Isolation::SessionModel Session()
        {
            if (m_session)
            {
                return m_session;
            }
            return m_session = m_image.get().OpenSession();
        }

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
