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

    void FeaturesPage::FeatureEnableCommand_ExecuteRequested(Input::XamlUICommand const&, Input::ExecuteRequestedEventArgs const& args)
    {
        auto ele = args.Parameter().as<FeatureViewModel>();
        //ele.State(FeatureState::Enabled);
    }
    void FeaturesPage::FeatureDisableCommand_ExecuteRequested(Input::XamlUICommand const&, Input::ExecuteRequestedEventArgs const& args)
    {
        auto ele = args.Parameter().as<FeatureViewModel>();
        //ele.State(FeatureState::Disabled);
    }

    void FeaturesPage::OpenFileButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto vm = this->FeatureTree().SelectedItem().as<FeatureViewModel>();
        auto target = vm.Package().InstallLocation();
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
        //auto vm = this->FeatureTree().SelectedItem().as<FeatureViewModel>();
        //auto target = vm.Package().Identity(); // todo: concat

        //OutputDebugString(std::format(L"{}\n", target.c_str()).c_str());

        //try {
        //    wil::unique_hkey hkeyTmp;
        //    check_win32(RegOpenKey(HKEY_LOCAL_MACHINE, target.c_str(), wil::out_param(hkeyTmp)));
        //} catch (winrt::hresult_error const&) {
        //    ContentDialog cd;
        //    cd.XamlRoot(this->XamlRoot());
        //    cd.Title(box_value(L"Cannot open file"));
        //    cd.Content(box_value(L"This package have no valid file path."));
        //    cd.PrimaryButtonText(L"OK");
        //    cd.DefaultButton(ContentDialogButton::Primary);
        //    cd.ShowAsync();

        //    return;
        //}

        //target = L"HKLM\\" + target;

        //// write to HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit
        ////wil::unique_hkey hkeyLastKey;
        ////check_nt(RegOpenKey(HKEY_CURRENT_USER,
        ////    L"Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit",
        ////    wil::out_param(hkeyLastKey)));
        ////check_nt(RegSetValue(hkeyLastKey.get(), L"LastKey", REG_SZ,
        ////    target.c_str(), sizeof(target.front()) * (1ull + target.size())));
        //
        //Windows::ApplicationModel::DataTransfer::DataPackage regText;
        //regText.SetText(target);
        //Windows::ApplicationModel::DataTransfer::Clipboard::SetContent(regText);

        //{
        //    ContentDialog cd;
        //    cd.XamlRoot(this->XamlRoot());
        //    cd.Title(box_value(L"Registry path copied!"));
        //    cd.Content(box_value(L"You can paste it in the address bar and jump to it.\nUFCase cannot locate it automatically for you."));
        //    cd.PrimaryButtonText(L"OK");
        //    cd.DefaultButton(ContentDialogButton::Primary);
        //    cd.ShowAsync().Completed([](auto&, auto&) {
        //        ShellExecute(nullptr, L"open", L"regedit", nullptr, nullptr, SW_SHOW);
        //    });
        //}


    }

    void FeaturesPage::OpenKBButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto vm = this->FeatureTree().SelectedItem().as<FeatureViewModel>();
        auto url = vm.Package().SupportInformation();
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



