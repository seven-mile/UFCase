#include "pch.h"
#include "FeaturesPage.xaml.h"
#if __has_include("FeaturesPage.g.cpp")
#include "FeaturesPage.g.cpp"
#endif

#include "GlobalUtil.h"

#include <filesystem>
#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    FeaturesPage::FeaturesPage()
    {
    }

    void FeaturesPage::OnNavigatedTo(const Navigation::NavigationEventArgs &e)
    {
        m_view_model = e.Parameter().try_as<FeaturesPageViewModel>();

        m_feature_enable_revoker = m_view_model.FeatureEnableRelay().CanExecuteChanged(
            auto_revoke, [self = get_strong()](auto &, auto &) {
                self->FeatureEnableCommand().NotifyCanExecuteChanged();
            });

        m_feature_disable_revoker = m_view_model.FeatureDisableRelay().CanExecuteChanged(
            auto_revoke, [self = get_strong()](auto &, auto &) {
                self->FeatureDisableCommand().NotifyCanExecuteChanged();
            });

        m_feature_goto_revoker = m_view_model.FeatureGotoPackageRelay().CanExecuteChanged(
            auto_revoke, [self = get_strong()](auto &, auto &) {
                self->FeatureGotoPackageCommand().NotifyCanExecuteChanged();
            });

        if (m_view_model.State() == FeaturesPageViewModelState::Uninitialized)
        {
            m_view_model.RefreshRelay().Execute(nullptr);
        }
        return;
    }

    void FeaturesPage::FeatureTreeItem_DoubleTapped(IInspectable const &sender,
                                                    Input::DoubleTappedRoutedEventArgs const &e)
    {
        auto item = sender.as<TreeViewItem>();
        item.IsExpanded(!item.IsExpanded());

        e.Handled(true);
    }

    void FeaturesPage::FeatureTreeItem_RightTapped(IInspectable const &sender,
                                                   Input::RightTappedRoutedEventArgs const &e)
    {
        auto feature = sender.as<FrameworkElement>().DataContext().as<FeatureViewModel>();
        m_view_model.SelectedFeature(feature);
    }

    void FeaturesPage::FeatureTree_SelectionChanged(
        IInspectable const &, Controls::TreeViewSelectionChangedEventArgs const &e)
    {
        if (e.AddedItems().Size() < 1)
        {
            return;
        }

        if (auto item = e.AddedItems().GetAt(0))
        {
            ViewModel().SelectedFeature(item.as<UFCase::FeatureViewModel>());
        }
    }

} // namespace winrt::UFCase::implementation
