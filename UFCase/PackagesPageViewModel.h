#pragma once

#include "PackagesPageNavigationContext.g.h"
#include "PackagesPageViewModel.g.h"

#include <winrt/Windows.Storage.h>
#include <winrt/Microsoft.UI.Xaml.Documents.h>

#include "XamlUtil.h"

#include "ImageModel.h"

#include <fstream>

namespace winrt::UFCase::implementation
{

    struct PackagesPageNavigationContext : PackagesPageNavigationContextT<PackagesPageNavigationContext> {
        PackagesPageNavigationContext() = default;

        hstring SelectPkgId() { return m_sel_pkg; }
        void SelectPkgId(hstring value) { m_sel_pkg = value; }

        hstring m_sel_pkg;
    };

    struct PackagesPageViewModel : PackagesPageViewModelT<PackagesPageViewModel>
    {
        PackagesPageViewModel(UFCase::ImageViewModel image): m_image(image) { }
        PackagesPageViewModel(UFCase::ImageViewModel image, UFCase::PackagesPageNavigationContext nav_ctx)
            : m_image(image), m_nav_ctx(nav_ctx) { }

        UFCase::ImageViewModel Image() { return m_image; }
        IObservableVector<UFCase::PackageViewModel> Packages() { return m_packages; }
        UFCase::PackageViewModel SelectedPackage() { return m_selected; }
        void SelectedPackage(UFCase::PackageViewModel value) {
            m_selected = value;
            //m_property_changed(*this, Data::PropertyChangedEventArgs{ L"SelectedPackage" });
        }

        UFCase::PackagesPageNavigationContext NavContext() { return m_nav_ctx; }

        IAsyncActionWithProgress<uint32_t> PullData(bool is_nav = true);

        // implement INotifyPropertyChanged
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value) {
            return m_property_changed.add(value);
        }
        void PropertyChanged(winrt::event_token const& token) {
            m_property_changed.remove(token);
        }

        HandleCommandAsync(PackageShowManifest, L"Show manifest", L"\xe8a1") {
            auto manifest_root = ImageModel::Current()->Bootdrive() / L"Windows" / L"servicing" / L"Packages";
            auto manifest_name = m_selected.DetailIdentity() + L".mum";
            auto file = co_await Windows::Storage::StorageFile::GetFileFromPathAsync((manifest_root / manifest_name.c_str()).c_str());
            auto manifest = co_await Windows::Storage::FileIO::ReadTextAsync(file);
            ContentDialog cd;
            cd.XamlRoot(GlobalRes::MainWnd().Content().XamlRoot());
            cd.Title(box_value(L"Manifest content"));
            RichTextBlock txt;
            Documents::Run run;
            run.Text(manifest);
            Documents::Paragraph para;
            para.Inlines().Append(run);
            txt.Blocks().Append(para);
            ScrollViewer sv;
            sv.Content(txt);
            cd.Content(sv);
            cd.PrimaryButtonText(L"OK");
            cd.DefaultButton(ContentDialogButton::Primary);
            cd.MaxHeight(600);
            co_await cd.ShowAsync();
        }

        HandleCommandAsync(PackageShowInFileExplorer, L"Open in explorer", L"\xE8DA") {
            co_return;
        }

        HandleCommandAsync(PackageShowInRegistry, L"Open in registry", L"") {
            co_return;
        }

    private:
        UFCase::ImageViewModel m_image{nullptr};
        IObservableVector<UFCase::PackageViewModel> m_packages{nullptr};
        UFCase::PackageViewModel m_selected{nullptr};
        UFCase::PackagesPageNavigationContext m_nav_ctx;

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_property_changed{};
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPageViewModel : PackagesPageViewModelT<PackagesPageViewModel, implementation::PackagesPageViewModel>
    {
    };

    struct PackagesPageNavigationContext : PackagesPageNavigationContextT<PackagesPageNavigationContext, implementation::PackagesPageNavigationContext>
    {
    };
}
