#include "pch.h"

#include "CbsApi.h"

#include "FeatureViewModel.h"
#if __has_include("FeatureViewModel.g.cpp")
#include "FeatureViewModel.g.cpp"
#endif

#include <winrt/Windows.Storage.Streams.h>

#include "AsyncUtil.h"
#include "GlobalUtil.h"

#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    FeatureViewModel::FeatureViewModel(Isolation::FeatureModel model) : m_model(model)
    {
        m_children.VectorChanged([self = get_strong()](auto const &, IVectorChangedEventArgs args) {
            switch (args.CollectionChange())
            {
            case CollectionChange::ItemInserted:
                self->m_children.GetAt(args.Index())
                    .PropertyChanged([self](auto const &, auto const &) {
                        RunUITask([self]() { self->NotifyCommonPropertyChanged(); });
                    });
                break;
            default:
                break;
            }
        });

        Prefetch();
    }

    hstring FeatureViewModel::NameRaw()
    {
        auto &&res = m_model.DisplayName();
        if (res.empty())
            return m_model.Name();
        return res;
    }
    hstring FeatureViewModel::DescriptionRaw()
    {
        auto &&res = m_model.Description();
        if (res.empty())
            return L"No description.";
        return res;
    }
    hstring FeatureViewModel::IdentityRaw()
    {
        return m_model.Name();
    }
    FeatureState FeatureViewModel::StateRaw()
    {
        auto state = m_model.RequestedState();
        switch (state)
        {
        case Isolation::CbsInstallState::CbsInstallStateInstallRequested:
        case Isolation::CbsInstallState::CbsInstallStateInstalled:
            // case Isolation::CbsInstallState::CbsInstallStatePermanent:
            if (std::optional<bool> opt = this->IsChecked(); opt.has_value())
            {
                assert(*opt);
                return FeatureState::Enabled;
            }
            else
                return FeatureState::PartiallyEnabled;
        case Isolation::CbsInstallState::CbsInstallStateUninstallRequested:
        case Isolation::CbsInstallState::CbsInstallStateStaged:
            // case Isolation::CbsInstallState::CbsInstallStateResolved:
            return FeatureState::Disabled;
        case Isolation::CbsInstallState::CbsInstallStateAbsent:
            return FeatureState::Unavailable;
        default:
            return FeatureState::Invalid;
        }
    }
    hstring FeatureViewModel::StateTextRaw()
    {
        switch (this->State())
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

    hstring FeatureViewModel::DisplayFileRaw()
    {
        return m_model.DisplayFile();
    }

    hstring FeatureViewModel::RestartRaw()
    {
        return m_model.Restart();
    }

    hstring FeatureViewModel::PsfNameRaw()
    {
        return m_model.PsfName();
    }

    hstring FeatureViewModel::DownloadSizeRaw()
    {
        return m_model.DownloadSize();
    }

    hstring FeatureViewModel::SetMembershipRaw()
    {
        return m_model.SetMembership();
    }

    UFCase::PackageViewModel FeatureViewModel::ContentPackage()
    {
        return UFCase::PackageViewModel(m_model.ContentPackage());
    }

    FeatureViewModel::child_t FeatureViewModel::Children()
    {
        return m_children;
    }

    bool FeatureViewModel::IsEnabled()
    {
        return this->State() != FeatureState::Unavailable && this->State() != FeatureState::Invalid;
    }

    IReference<bool> FeatureViewModel::IsCheckedRaw()
    {
        uint32_t cnt = 0;
        for (auto child : m_children)
        {
            std::optional<bool> t = child.IsChecked();
            cnt += t.has_value() && *t;
        }
        if (cnt < m_children.Size())
            return std::optional<bool>(std::nullopt);
        if (static_cast<DWORD>(m_model.RequestedState()) >= CbsInstallStateInstallRequested)
            return true;
        return false;
    }

    hstring FeatureViewModel::ModificationMark()
    {
        return m_mark;
    }
    void FeatureViewModel::ModificationMark(hstring const &val)
    {
        m_mark = val;
        NotifyPropChange(L"ModificationMark");
    }

    IconSource FeatureViewModel::Icon()
    {
        FontIconSource src{};
        src.FontFamily(GlobalRes::SymbolThemeFontFamily());

        switch (this->State())
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
            throw_hresult(HRESULT_FROM_WIN32(ERROR_INVALID_STATE));
        }
        return src;
    }

    void FeatureViewModel::Enable()
    {
        m_model.Enable();

        NotifyCommonPropertyChanged();
    }
    void FeatureViewModel::Disable()
    {
        m_model.Disable();

        NotifyCommonPropertyChanged();
    }
} // namespace winrt::UFCase::implementation
