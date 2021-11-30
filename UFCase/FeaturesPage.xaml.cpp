#include "pch.h"
#include "FeaturesPage.xaml.h"
#if __has_include("FeaturesPage.g.cpp")
#include "FeaturesPage.g.cpp"
#endif

#include <winrt/Windows.ApplicationModel.DataTransfer.h>
#include <winrt/Windows.System.h>

#include <filesystem>
#include <wil/resource.h>

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

    void FeaturesPage::FeatureOpenOFDialogCommand_ExecuteRequested(Input::XamlUICommand const&, Input::ExecuteRequestedEventArgs const&)
    {
        ShellExecute(nullptr, L"open", L"OptionalFeatures.exe", L"", L"", SW_SHOW);
    }

    void FeaturesPage::FeatureAddSourceUICommand_ExecuteRequested(Input::XamlUICommand const&, Input::ExecuteRequestedEventArgs const&)
    {
        AddSourceContentDialog addSrcDlg(Application::Current().Resources().Lookup(box_value(L"MainWindowInstance")).as<Window>());

        addSrcDlg.XamlRoot(this->XamlRoot());
        addSrcDlg.ShowAsync().Completed([this, addSrcDlg](auto const&op, auto const&) {
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

    bool FeaturesPage::IsFeatureStateCheckBoxEnabled(FeatureState const& st)
    {
        return st != FeatureState::Unavailable && st != FeatureState::Invalid;
    }

    Windows::Foundation::IReference<bool> FeaturesPage::IsFeatureStateCheckBoxCheckd(FeatureState const& st)
    {
        switch (st) {
        case FeatureState::Enabled: return true;
        case FeatureState::PartiallyEnabled: return nullptr;
        default: return false;
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

        // set indetermined state
        if (ele.State() == FeatureState::Enabled) {
            uint32_t cntEnabled = 0;
            for (auto child : ele.Children()) {
                cntEnabled += child.State() == FeatureState::Enabled;
            }
            if (cntEnabled < ele.Children().Size())
                ele.State(FeatureState::PartiallyEnabled);
        }

        ele.Icon(map_icon_src.find(ele.State())->second);

        // for context menu
        MenuFlyout res;
        MenuFlyoutSeparator sp1, sp2;
        ele.ContextMenu(res);


        // todo: deal with other enum state
        if (ele.State() == FeatureState::Enabled || ele.State() == FeatureState::PartiallyEnabled) {
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

        addSrcItem.Command(this->FeatureAddSourceUICommand());
        res.Items().Append(addSrcItem);

        // set param to data context
        for (auto anyItem : res.Items())
            if (auto cmdItem = anyItem.try_as<MenuFlyoutItem>())
                cmdItem.CommandParameter(ele);
        
        for (auto child : ele.Children())
            this->ConfigFeatureTreeElementUIElements(child);
    }

    void FeaturesPage::OpenFileButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto vm = this->FeatureTree().SelectedItem().as<FeatureTreeElement>();
        auto target = vm.Package().GetFSPath();
        if (target == L"" || !std::filesystem::exists(target.c_str())) {
            ContentDialog cd;
            cd.XamlRoot(this->XamlRoot());
            cd.Title(box_value(L"Cannot open file"));
            cd.Content(box_value(L"This package have no valid file path."));
            cd.PrimaryButtonText(L"OK");
            cd.DefaultButton(ContentDialogButton::Primary);
            cd.ShowAsync();

            return;
        }
        ShellExecute(nullptr, L"open", L"explorer", std::format(L"/select, {}", target.c_str()).c_str(), nullptr, SW_SHOW);
    }

    void FeaturesPage::OpenRegButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto vm = this->FeatureTree().SelectedItem().as<FeatureTreeElement>();
        auto target = vm.Package().GetRegPath();

        OutputDebugString(std::format(L"{}\n", target.c_str()).c_str());

        try {
            wil::unique_hkey hkeyTmp;
            check_win32(RegOpenKey(HKEY_LOCAL_MACHINE, target.c_str(), wil::out_param(hkeyTmp)));
        } catch (winrt::hresult_error const&) {
            ContentDialog cd;
            cd.XamlRoot(this->XamlRoot());
            cd.Title(box_value(L"Cannot open file"));
            cd.Content(box_value(L"This package have no valid file path."));
            cd.PrimaryButtonText(L"OK");
            cd.DefaultButton(ContentDialogButton::Primary);
            cd.ShowAsync();

            return;
        }

        target = L"HKLM\\" + target;

        // write to HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit
        //wil::unique_hkey hkeyLastKey;
        //check_nt(RegOpenKey(HKEY_CURRENT_USER,
        //    L"Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit",
        //    wil::out_param(hkeyLastKey)));
        //check_nt(RegSetValue(hkeyLastKey.get(), L"LastKey", REG_SZ,
        //    target.c_str(), sizeof(target.front()) * (1ull + target.size())));
        
        Windows::ApplicationModel::DataTransfer::DataPackage regText;
        regText.SetText(target);
        Windows::ApplicationModel::DataTransfer::Clipboard::SetContent(regText);

        {
            ContentDialog cd;
            cd.XamlRoot(this->XamlRoot());
            cd.Title(box_value(L"Registry path copied!"));
            cd.Content(box_value(L"You can paste it in the address bar and jump to it.\nUFCase cannot locate it automatically for you."));
            cd.PrimaryButtonText(L"OK");
            cd.DefaultButton(ContentDialogButton::Primary);
            cd.ShowAsync().Completed([](auto&, auto&) {
                ShellExecute(nullptr, L"open", L"regedit", nullptr, nullptr, SW_SHOW);
            });
        }


    }

    void FeaturesPage::OpenKBButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto vm = this->FeatureTree().SelectedItem().as<FeatureTreeElement>();
        auto url = vm.Package().GetSupportUrl();
        try {
            Windows::System::Launcher::LaunchUriAsync(Uri(url));
        } catch (hresult_error const&) {
            ContentDialog cd;
            cd.XamlRoot(this->XamlRoot());
            cd.Title(box_value(L"Cannot open support info"));
            cd.Content(box_value(L"This package have no valid support url."));
            cd.PrimaryButtonText(L"OK");
            cd.DefaultButton(ContentDialogButton::Primary);
            cd.ShowAsync();
        }
    }

    void FeaturesPage::FeatureTree_Loaded(IInspectable const&, RoutedEventArgs const&)
    {
        if (auto src = this->FeatureTree().ItemsSource().as<source_t>(); src.Size()) {
            auto z = src.GetAt(0);
            this->FeatureTree().SelectedItem(z);
            auto ele = this->FeatureTree().ContainerFromItem(z);
            ele.as<TreeViewItem>().IsSelected(true);
        } else {
            this->FeatureInfoPanel().Visibility(Visibility::Collapsed);
        }
    }
    void FeaturesPage::FeatureTreeItem_DoubleTapped(IInspectable const& sender, Input::DoubleTappedRoutedEventArgs const&)
    {
        auto item = sender.as<TreeViewItem>();
        item.IsExpanded(!item.IsExpanded());
    }
}



