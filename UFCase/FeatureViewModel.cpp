#include "pch.h"
#include "CbsApi.h"
#include "FeatureViewModel.h"
#if __has_include("FeatureViewModel.g.cpp")
#include "FeatureViewModel.g.cpp"
#endif

#include "PackageModel.h"

#include <winrt/Windows.Storage.Streams.h>

#include "MallocUtil.h"
#include "CbsUtil.h"
#include "GlobalUtil.h"

#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    FeatureViewModel::FeatureViewModel(uint64_t hModel) : m_model(FeatureModel::GetInstance(hModel)) {
        m_children.VectorChanged([this](auto const&, IVectorChangedEventArgs args) {
            switch (args.CollectionChange()) {
            case CollectionChange::ItemInserted:
                m_children.GetAt(args.Index()).PropertyChanged([this](auto const&, auto const&) {
                    GlobalRes::MainWnd().DispatcherQueue().TryEnqueue([this]() {
                        NotifyCommonPropertyChanged();
                    });
                });
                break;
            default:
                break;
            }
        });
    }

    winrt::event_token FeatureViewModel::PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value)
    {
        return this->m_propertyChanged.add(value);
    }

    void FeatureViewModel::PropertyChanged(winrt::event_token const& token)
    {
        this->m_propertyChanged.remove(token);
    }

    hstring FeatureViewModel::Name()
    {
        auto &&res = m_model.DisplayName();
        if (res.empty()) return m_model.Name();
        return res;
    }
    hstring FeatureViewModel::Description()
    {
        auto &&res = m_model.Description();
        if (res.empty()) return L"No description.";
        return res;
    }
    hstring FeatureViewModel::Identity()
    {
        return m_model.Name();
    }
    FeatureState FeatureViewModel::State()
    {
        auto state = m_model.RequestedState();
        switch (state) {
        case CbsInstallStateInstallRequested:
        case CbsInstallStateInstalled:
        //case CbsInstallStatePermanent:
            if (std::optional<bool> opt = this->IsChecked(); opt.has_value()) {
                assert(*opt);
                return FeatureState::Enabled;
            }
            else return FeatureState::PartiallyEnabled;
        case CbsInstallStateUninstallRequested:
        case CbsInstallStateStaged:
        //case CbsInstallStateResolved:
            return FeatureState::Disabled;
        case CbsInstallStateAbsent:
            return FeatureState::Unavailable;
        default:
            return FeatureState::Invalid;
        }
    }
    hstring FeatureViewModel::StateText()
    {
        switch (this->State()) {
            case FeatureState::Unavailable: return L"Unavailable";
            case FeatureState::Disabled: return L"Disabled";
            case FeatureState::PartiallyEnabled: return L"PartiallyEnabled";
            case FeatureState::Enabled: return L"Enabled";
            default: return L"Invalid";
        }
    }

    hstring FeatureViewModel::DisplayFile()
    {
        return m_model.DisplayFile();
    }

    hstring FeatureViewModel::Restart()
    {
        return m_model.Restart();
    }

    hstring FeatureViewModel::PsfName()
    {
        return m_model.PsfName();
    }

    hstring FeatureViewModel::DownloadSize()
    {
        return m_model.DownloadSize();
    }

    hstring FeatureViewModel::SetMembership()
    {
        return m_model.SetMembership();
    }

    UFCase::PackageViewModel FeatureViewModel::Package()
    {
        return UFCase::PackageViewModel(m_model.RawParentPackage()->GetHandle());
    }

    FeatureViewModel::child_t FeatureViewModel::Children()
    {
        return m_children;
    }

    bool FeatureViewModel::IsEnabled()
    {
        return this->State() != FeatureState::Unavailable
            && this->State() != FeatureState::Invalid;
    }

    IReference<bool> FeatureViewModel::IsChecked()
    {
        uint32_t cnt = 0;
        for (auto child : m_children) {
            std::optional<bool> t = child.IsChecked();
            cnt += t.has_value() && *t;
        }
        if (cnt < m_children.Size()) return std::optional<bool>(std::nullopt);
        if (m_model.RequestedState() >= CbsInstallStateInstallRequested) return true;
        return false;
    }

    hstring FeatureViewModel::ModificationMark()
    {
        return m_mark;
    }
    void FeatureViewModel::ModificationMark(hstring const &val)
    {
        m_mark = val;
        m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"ModificationMark"});
    }

    IconSource FeatureViewModel::Icon()
    {
        FontIconSource src{};
        src.FontFamily(GlobalRes::SymbolThemeFontFamily());

        switch (this->State()) {
        case FeatureState::Enabled:
            src.Glyph(L"\uf16c"); break;
        case FeatureState::Disabled:
            src.Glyph(L"\uf16b"); break;
        case FeatureState::PartiallyEnabled:
            src.Glyph(L"\uf16d"); break;
        case FeatureState::Unavailable:
            src.Glyph(L"\uea39"); break;

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
}
