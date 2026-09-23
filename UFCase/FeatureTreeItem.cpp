#include "pch.h"

#include "FeatureTreeItem.h"
#if __has_include("FeatureDetails.g.cpp")
#include "FeatureDetails.g.cpp"
#endif
#if __has_include("FeatureTreeItem.g.cpp")
#include "FeatureTreeItem.g.cpp"
#endif

#include "AsyncUtil.h"
#include "GlobalUtil.h"

namespace winrt::UFCase::implementation
{
    static FeatureState GetFeatureState(Isolation::CbsInstallState requested_state,
                                        IReference<bool> const &checked)
    {
        switch (requested_state)
        {
        case Isolation::CbsInstallState::CbsInstallStateInstallRequested:
        case Isolation::CbsInstallState::CbsInstallStateInstalled:
            return checked ? FeatureState::Enabled : FeatureState::PartiallyEnabled;
        case Isolation::CbsInstallState::CbsInstallStateUninstallRequested:
        case Isolation::CbsInstallState::CbsInstallStateStaged:
            return FeatureState::Disabled;
        case Isolation::CbsInstallState::CbsInstallStateAbsent:
            return FeatureState::Unavailable;
        default:
            return FeatureState::Invalid;
        }
    }

    FeatureTreeItemSnapshot ReadFeatureTreeItemSnapshot(Isolation::FeatureModel const &model)
    {
        auto display_name = model.DisplayName();
        auto identity = model.Name();
        return FeatureTreeItemSnapshot{
            .Name = display_name.empty() ? identity : display_name,
            .Description = model.Description().empty() ? L"No description." : model.Description(),
            .Identity = identity,
            .RequestedState = model.RequestedState(),
        };
    }

    FeatureDetailsSnapshot ReadFeatureDetailsSnapshot(Isolation::FeatureModel const &model)
    {
        auto tree_data = ReadFeatureTreeItemSnapshot(model);
        auto content_package = model.ContentPackage();
        return FeatureDetailsSnapshot{
            .Name = tree_data.Name,
            .Description = tree_data.Description,
            .Identity = tree_data.Identity,
            .DisplayFile = model.DisplayFile(),
            .Restart = model.Restart(),
            .PsfName = model.PsfName(),
            .DownloadSize = model.DownloadSize(),
            .SetMembership = model.SetMembership(),
            .ContentPackageIdentity = content_package ? content_package.Identity() : hstring{},
        };
    }

    FeatureTreeItem::FeatureTreeItem(uint32_t record_id, FeatureTreeItemSnapshot data)
        : m_record_id(record_id), m_data(std::move(data))
    {
        m_children.VectorChanged([self = get_strong()](auto const &, IVectorChangedEventArgs args) {
            if (args.CollectionChange() == CollectionChange::ItemInserted)
            {
                self->m_children.GetAt(args.Index())
                    .PropertyChanged([self](auto const &, auto const &) {
                        RunUITask([self]() { self->NotifyCommonPropertyChanged(); });
                    });
            }
        });
    }

    void FeatureTreeItem::UpdateSnapshot(FeatureTreeItemSnapshot data)
    {
        m_data = std::move(data);
        NotifyPropChange(L"Name");
        NotifyPropChange(L"Description");
        NotifyPropChange(L"Identity");
        NotifyCommonPropertyChanged();
    }

    hstring FeatureTreeItem::Name()
    {
        return m_data.Name;
    }

    hstring FeatureTreeItem::Description()
    {
        return m_data.Description;
    }

    hstring FeatureTreeItem::Identity()
    {
        return m_data.Identity;
    }

    FeatureState FeatureTreeItem::State()
    {
        return GetFeatureState(m_data.RequestedState, IsChecked());
    }

    hstring FeatureTreeItem::StateText()
    {
        switch (State())
        {
        case FeatureState::Unavailable:
            return L"Unavailable";
        case FeatureState::Disabled:
            return L"Disabled";
        case FeatureState::PartiallyEnabled:
            return L"PartiallyEnabled";
        case FeatureState::Enabled:
            return L"Enabled";
        default:
            return L"Invalid";
        }
    }

    FeatureTreeItem::child_t FeatureTreeItem::Children()
    {
        return m_children;
    }

    bool FeatureTreeItem::IsEnabled()
    {
        auto state = State();
        return state != FeatureState::Unavailable && state != FeatureState::Invalid;
    }

    IReference<bool> FeatureTreeItem::IsChecked()
    {
        uint32_t enabled_children = 0;
        for (auto const &child : m_children)
        {
            std::optional<bool> child_checked = child.IsChecked();
            enabled_children += child_checked.has_value() && *child_checked;
        }

        if (enabled_children < m_children.Size())
        {
            return std::optional<bool>(std::nullopt);
        }

        if (static_cast<DWORD>(m_data.RequestedState) >= CbsInstallStateInstallRequested)
        {
            return true;
        }
        return false;
    }

    hstring FeatureTreeItem::ModificationMark()
    {
        return m_mark;
    }

    void FeatureTreeItem::ModificationMark(hstring const &value)
    {
        m_mark = value;
        NotifyPropChange(L"ModificationMark");
    }

    IconSource FeatureTreeItem::Icon()
    {
        FontIconSource src{};
        src.FontFamily(GlobalRes::SymbolThemeFontFamily());

        switch (State())
        {
        case FeatureState::Enabled:
            src.Glyph(L"\uf16c");
            break;
        case FeatureState::Disabled:
            src.Glyph(L"\uf16b");
            break;
        case FeatureState::PartiallyEnabled:
            src.Glyph(L"\uf16d");
            break;
        case FeatureState::Unavailable:
            src.Glyph(L"\uea39");
            break;
        default:
            src.Glyph(L"\ue783");
            break;
        }
        return src;
    }

    void FeatureTreeItem::NotifyCommonPropertyChanged()
    {
        NotifyPropChange(L"State");
        NotifyPropChange(L"StateText");
        NotifyPropChange(L"Icon");
        NotifyPropChange(L"IsEnabled");
        NotifyPropChange(L"IsChecked");
    }

    FeatureDetails::FeatureDetails(FeatureDetailsSnapshot data) : m_data(std::move(data)) {}

    hstring FeatureDetails::Name() { return m_data.Name; }
    hstring FeatureDetails::Description() { return m_data.Description; }
    hstring FeatureDetails::Identity() { return m_data.Identity; }
    hstring FeatureDetails::DisplayFile() { return m_data.DisplayFile; }
    hstring FeatureDetails::Restart() { return m_data.Restart; }
    hstring FeatureDetails::PsfName() { return m_data.PsfName; }
    hstring FeatureDetails::DownloadSize() { return m_data.DownloadSize; }
    hstring FeatureDetails::SetMembership() { return m_data.SetMembership; }
    hstring FeatureDetails::ContentPackageIdentity() { return m_data.ContentPackageIdentity; }
} // namespace winrt::UFCase::implementation
