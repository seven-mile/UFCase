#pragma once

#include "CbsApi.h"
#include "FeatureViewModel.g.h"

#include "FeatureModel.h"

namespace winrt::UFCase::implementation
{
    struct FeatureViewModel : FeatureViewModelT<FeatureViewModel>
    {

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_propertyChanged;
        // implement INotifyPropertyChanged
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value);
        void PropertyChanged(winrt::event_token const& token);

        FeatureModel m_model;

        using child_t = IObservableVector<UFCase::FeatureViewModel>;
        child_t m_children;

        hstring m_mark = L"";
        IconSource m_icon {nullptr};
        Primitives::FlyoutBase m_menu {nullptr};

        FeatureViewModel(uint64_t hModel);


        hstring Name();
        hstring Description();
        hstring Identity();
        FeatureState State();
        hstring StateText();

        UFCase::PackageViewModel Package();

        child_t Children();

        bool IsEnabled();
        IReference<bool> IsChecked();

        hstring ModificationMark();
        void ModificationMark(const hstring &value);
        IconSource Icon();
        void Icon(IconSource const &value);
        Primitives::FlyoutBase ContextMenu();
        void ContextMenu(Primitives::FlyoutBase const &value);
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeatureViewModel : FeatureViewModelT<FeatureViewModel, implementation::FeatureViewModel>
    {
    };
}
