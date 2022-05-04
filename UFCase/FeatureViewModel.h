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
        child_t m_children = multi_threaded_observable_vector<UFCase::FeatureViewModel>();

        hstring m_mark = L"";

        FeatureViewModel(uint64_t hModel);

        hstring Name();
        hstring Description();
        hstring Identity();
        FeatureState State();
        hstring StateText();

        hstring DisplayFile();
        hstring Restart();
        hstring PsfName();
        hstring DownloadSize();
        hstring SetMembership();

        UFCase::PackageViewModel Package();

        child_t Children();

        bool IsEnabled();
        IReference<bool> IsChecked();

        hstring ModificationMark();
        void ModificationMark(const hstring &value);
        IconSource Icon();

        void Enable();
        void Disable();
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeatureViewModel : FeatureViewModelT<FeatureViewModel, implementation::FeatureViewModel>
    {
    };
}
