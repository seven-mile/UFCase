#include "pch.h"
#include "FeaturesPage.xaml.h"
#if __has_include("FeaturesPage.g.cpp")
#include "FeaturesPage.g.cpp"
#endif

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::UFCase::implementation
{
    FeaturesPage::FeaturesPage()
    {
        InitializeComponent();
    }

    FeaturesPage::source_t FeaturesPage::FeatureDataSource()
    {
        return m_source;
    }

    void FeaturesPage::OnNavigatedTo(const Navigation::NavigationEventArgs& e)
    {
        if (auto val = e.Parameter().try_as<source_t>()) {
            // configure icon & menu flyout from xaml
            for (auto ele : val) {
                this->ConfigFeatureTreeElementUIElements(ele);
            }

            m_source = val;
        } else {
            throw winrt::hresult_invalid_argument();
        }
    }

    void FeaturesPage::FeatureInstallCommand_ExecuteRequested(Input::XamlUICommand const&, Input::ExecuteRequestedEventArgs const& args)
    {
        auto ele = args.Parameter().as<FeatureTreeElement>();
        ele.State(FeatureState::Enabled);
    }
    void FeaturesPage::FeatureStageCommand_ExecuteRequested(Input::XamlUICommand const&, Input::ExecuteRequestedEventArgs const& args)
    {
        auto ele = args.Parameter().as<FeatureTreeElement>();
        ele.State(FeatureState::Disabled);
    }

    void FeaturesPage::ConfigFeatureTreeElementUIElements(FeatureTreeElement ele)
    {
        const static std::unordered_map<FeatureState, IconSource> map_icon_src {
            {FeatureState::Enabled, this->Resources().Lookup(box_value(L"TreeElementEnabledIconSource")).as<IconSource>()},
            {FeatureState::Disabled, this->Resources().Lookup(box_value(L"TreeElementDisabledIconSource")).as<IconSource>()},
            {FeatureState::PartiallyEnabled, this->Resources().Lookup(box_value(L"TreeElementPartiallyIconSource")).as<IconSource>()},
            {FeatureState::Unavailable, this->Resources().Lookup(box_value(L"TreeElementUnavailableIconSource")).as<IconSource>()},
        };
        ele.Icon(map_icon_src.find(ele.State())->second);

        // for context menu
        MenuFlyout res;
        MenuFlyoutSeparator sp1, sp2;
        ele.ContextMenu(res);

        // todo: deal with other enum state
        if (ele.State() == FeatureState::Enabled) {
            MenuFlyoutItem stageItem, removeItem;
            stageItem.Command(this->FeatureStageCommand());
            removeItem.Command(this->FeatureRemoveCommand());
            res.Items().Append(stageItem);
            res.Items().Append(removeItem);
        } else {
            MenuFlyoutItem installItem;
            installItem.Command(this->FeatureInstallCommand());
            res.Items().Append(installItem);
        }
        res.Items().Append(sp1);

        MenuFlyoutItem openExplorerItem, openRegistryItem, addSrcItem;
        MenuFlyoutSubItem goBackItem;

        openExplorerItem.Command(this->FeatureOpenExplorerCommand());
        openRegistryItem.Command(this->FeatureOpenRegistryCommand());

        res.Items().Append(openExplorerItem);
        res.Items().Append(openRegistryItem);

        { // for go back sub item
            RadioMenuFlyoutItem ver1Item, ver2Item, ver3Item;
            auto groupId = to_hstring(GuidHelper::CreateNewGuid());
            ver1Item.GroupName(groupId);
            ver1Item.Text(L"10.0.22000.282");
            ver1Item.IsChecked(true);
            ver2Item.GroupName(groupId);
            ver2Item.Text(L"10.0.22000.190");
            ver2Item.SetAreCheckStatesEnabled(goBackItem, true);
            ver3Item.GroupName(groupId);
            ver3Item.Text(L"10.0.22000.1");
            ver3Item.SetAreCheckStatesEnabled(goBackItem, true);
            goBackItem.Text(L"Go back");
            goBackItem.Items().Append(ver1Item);
            goBackItem.Items().Append(ver2Item);
            goBackItem.Items().Append(ver3Item);
        }
        res.Items().Append(goBackItem);

        res.Items().Append(sp2);

        addSrcItem.Command(this->FeatureAddSourceCommand());
        res.Items().Append(addSrcItem);

        // set param to data context
        for (auto anyItem : res.Items())
            if (auto cmdItem = anyItem.try_as<MenuFlyoutItem>())
                cmdItem.CommandParameter(ele);
        
        for (auto child : ele.Children())
            this->ConfigFeatureTreeElementUIElements(child);
    }
}
