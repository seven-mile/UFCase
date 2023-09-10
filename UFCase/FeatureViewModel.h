#pragma once

#include "CbsApi.h"
#include "FeatureViewModel.g.h"

#include "FeatureModel.h"

#include "CacheUtil.h"

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

        hstring NameRaw();
        hstring DescriptionRaw();
        hstring IdentityRaw();
        FeatureState StateRaw();
        hstring StateTextRaw();

        hstring DisplayFileRaw();
        hstring RestartRaw();
        hstring PsfNameRaw();
        hstring DownloadSizeRaw();
        hstring SetMembershipRaw();

        UFCase::PackageViewModel Package();
        UFCase::PackageViewModel ContentPackage();

        child_t Children();

        bool IsEnabled();
        IReference<bool> IsCheckedRaw();

        hstring ModificationMark();
        void ModificationMark(const hstring &value);
        IconSource Icon();

        void Enable();
        void Disable();

        PropertyCache<hstring, FeatureViewModel> Name{ *this, &FeatureViewModel::NameRaw };
        PropertyCache<hstring, FeatureViewModel> Description{ *this, &FeatureViewModel::DescriptionRaw };
        PropertyCache<hstring, FeatureViewModel> Identity{ *this, &FeatureViewModel::IdentityRaw };
        PropertyCache<FeatureState, FeatureViewModel> State{ *this, &FeatureViewModel::StateRaw };
        PropertyCache<hstring, FeatureViewModel> StateText{ *this, &FeatureViewModel::StateTextRaw };
        PropertyCache<hstring, FeatureViewModel> DisplayFile{ *this, &FeatureViewModel::DisplayFileRaw };
        PropertyCache<hstring, FeatureViewModel> Restart{ *this, &FeatureViewModel::RestartRaw };
        PropertyCache<hstring, FeatureViewModel> PsfName{ *this, &FeatureViewModel::PsfNameRaw };
        PropertyCache<hstring, FeatureViewModel> DownloadSize{ *this, &FeatureViewModel::DownloadSizeRaw };
        PropertyCache<hstring, FeatureViewModel> SetMembership{ *this, &FeatureViewModel::SetMembershipRaw };
        PropertyCache<IReference<bool>, FeatureViewModel> IsChecked{ *this, &FeatureViewModel::IsCheckedRaw };

        void Prefetch() {
            Name();
            Description();
            Identity();
            State();
            StateText();
            DisplayFile();
            Restart();
            PsfName();
            DownloadSize();
            SetMembership();
            IsChecked();
        }

    private:
        void NotifyCommonPropertyChanged() {
            m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"State"});
            m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"StateText"});
            m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"Icon"});
            m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"IsEnabled"});
            m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"IsChecked"});
        }
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeatureViewModel : FeatureViewModelT<FeatureViewModel, implementation::FeatureViewModel>
    {
    };
}
