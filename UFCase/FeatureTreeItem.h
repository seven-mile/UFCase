#pragma once

#include "CbsApi.h"
#include "FeatureDetails.g.h"
#include "FeatureTreeItem.g.h"

#include <winrt/UFCase.Isolation.h>

#include "PropChgUtil.h"

namespace winrt::UFCase::implementation
{
    struct FeatureTreeItemSnapshot
    {
        hstring Name;
        hstring Description;
        hstring Identity;
        Isolation::CbsInstallState RequestedState{Isolation::CbsInstallState::CbsInstallStateInvalid};
    };

    struct FeatureDetailsSnapshot
    {
        hstring Name;
        hstring Description;
        hstring Identity;
        hstring DisplayFile;
        hstring Restart;
        hstring PsfName;
        hstring DownloadSize;
        hstring SetMembership;
        hstring ContentPackageIdentity;
    };

    FeatureTreeItemSnapshot ReadFeatureTreeItemSnapshot(Isolation::FeatureModel const &model);
    FeatureDetailsSnapshot ReadFeatureDetailsSnapshot(Isolation::FeatureModel const &model);

    struct FeatureTreeItem : FeatureTreeItemT<FeatureTreeItem>,
                             ImplPropertyChangedT<FeatureTreeItem>
    {
        using child_t = IObservableVector<UFCase::FeatureTreeItem>;

        FeatureTreeItem(uint32_t record_id, FeatureTreeItemSnapshot data);

        uint32_t RecordId() const
        {
            return m_record_id;
        }

        void UpdateSnapshot(FeatureTreeItemSnapshot data);

        hstring Name();
        hstring Description();
        hstring Identity();
        FeatureState State();
        hstring StateText();

        child_t Children();

        bool IsEnabled();
        IReference<bool> IsChecked();

        hstring ModificationMark();
        void ModificationMark(hstring const &value);
        IconSource Icon();

      private:
        uint32_t m_record_id{};
        FeatureTreeItemSnapshot m_data;
        child_t m_children = multi_threaded_observable_vector<UFCase::FeatureTreeItem>();
        hstring m_mark;

        void NotifyCommonPropertyChanged();
    };

    struct FeatureDetails : FeatureDetailsT<FeatureDetails>
    {
        FeatureDetails(FeatureDetailsSnapshot data);

        hstring Name();
        hstring Description();
        hstring Identity();
        hstring DisplayFile();
        hstring Restart();
        hstring PsfName();
        hstring DownloadSize();
        hstring SetMembership();
        hstring ContentPackageIdentity();

      private:
        FeatureDetailsSnapshot m_data;
    };
} // namespace winrt::UFCase::implementation
