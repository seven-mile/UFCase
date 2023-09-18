#pragma once

#include "ComponentsPageViewModel.g.h"

#include <winrt/Microsoft.UI.Xaml.Documents.h>

#include "PropChgUtil.h"
#include "XamlUtil.h"

namespace winrt::UFCase::implementation
{
    struct ComponentsPageViewModel : ComponentsPageViewModelT<ComponentsPageViewModel>,
                                     ImplPropertyChangedT<ComponentsPageViewModel>
    {
        ComponentsPageViewModel(UFCase::ImageViewModel vm);

        ComponentsPageViewModelState State()
        {
            return m_state;
        }

        IAsyncActionWithProgress<uint32_t> PullData();

        Collections::IObservableVector<UFCase::ComponentViewModel> Components()
        {
            return m_components;
        }

        UFCase::ComponentViewModel SelectedComponent()
        {
            return m_selected;
        }

        void SelectedComponent(UFCase::ComponentViewModel value)
        {
            m_selected = value;
            // NotifyPropChange(L"SelectedComponent");
        }

        HandleCommandAsync(ComponentShowManifest)
        {
            if (!m_selected)
                co_return;
            auto manifest = m_selected.Manifest();
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

        HandleCommandAsync(ComponentShowInFileExplorer)
        {
            co_return;
        }

      private:
        ComponentsPageViewModelState m_state{ComponentsPageViewModelState::Uninitialized};

        weak_ref<UFCase::ImageViewModel> m_image;

        UFCase::ComponentViewModel m_selected{nullptr};
        Collections::IObservableVector<UFCase::ComponentViewModel> m_components;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct ComponentsPageViewModel
        : ComponentsPageViewModelT<ComponentsPageViewModel, implementation::ComponentsPageViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
