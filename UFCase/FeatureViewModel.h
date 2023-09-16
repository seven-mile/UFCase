#pragma once

#include "CbsApi.h"
#include "FeatureViewModel.g.h"

#include <winrt/UFCase.Isolation.h>

#include "CacheUtil.h"
#include "PropChgUtil.h"

namespace winrt::UFCase::implementation
{
    struct FeatureViewModel : FeatureViewModelT<FeatureViewModel>,
                              ImplPropertyChangedT<FeatureViewModel>
    {
        Isolation::FeatureModel m_model;

        using child_t = IObservableVector<UFCase::FeatureViewModel>;
        child_t m_children = multi_threaded_observable_vector<UFCase::FeatureViewModel>();

        hstring m_mark = L"";

        FeatureViewModel(Isolation::FeatureModel model);

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

        UFCase::PackageViewModel ContentPackage();

        child_t Children();

        bool IsEnabled();
        IReference<bool> IsCheckedRaw();

        hstring ModificationMark();
        void ModificationMark(const hstring &value);
        IconSource Icon();

        void Enable();
        void Disable();

        // clang-format off
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
        // clang-format on

        void Prefetch()
        {
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
        void NotifyCommonPropertyChanged()
        {
            NotifyPropChange(L"State");
            NotifyPropChange(L"StateText");
            NotifyPropChange(L"Icon");
            NotifyPropChange(L"IsEnabled");
            NotifyPropChange(L"IsChecked");
        }
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct FeatureViewModel : FeatureViewModelT<FeatureViewModel, implementation::FeatureViewModel>
    {
    };
} // namespace winrt::UFCase::factory_implementation
