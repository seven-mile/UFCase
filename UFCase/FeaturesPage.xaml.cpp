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

        if (m_view_model.State() == FeaturesPageViewModelState::Uninitialized)
        {
            m_view_model.RefreshCommand().Execute(nullptr);
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

        // continue to pop up context menu
        e.Handled(false);
    }

} // namespace winrt::UFCase::implementation
