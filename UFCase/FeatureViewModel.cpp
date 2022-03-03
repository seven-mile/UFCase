#include "pch.h"
#include "CbsApi.h"
#include "FeatureViewModel.h"
#if __has_include("FeatureViewModel.g.cpp")
#include "FeatureViewModel.g.cpp"
#endif

#include "PackageModel.h"

#include <winrt/Windows.Storage.Streams.h>

#include "CbsProviderManager.h"
#include "MallocUtil.h"
#include "CbsUtil.h"
#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    FeatureViewModel::FeatureViewModel(uint64_t hModel) : m_model(FeatureModel::GetInstance(hModel)) { }

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
        return m_model.DisplayName();
    }
    hstring FeatureViewModel::Description()
    {
        return m_model.Description();
    }
    hstring FeatureViewModel::Identity()
    {
        return m_model.RawParentPackage()->Identity();
    }
    FeatureState FeatureViewModel::State()
    {
        switch (m_model.State()) {
        case CbsInstallStateInstallRequested:
            if (this->IsChecked().Value())
                return FeatureState::Enabled;
            else return FeatureState::PartiallyEnabled;
        case CbsInstallStateUninstallRequested:
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
        return m_model.State() >= CbsInstallStateUninstallRequested;
    }

    IReference<bool> FeatureViewModel::IsChecked()
    {
        if (m_model.State() >= CbsInstallStateInstallRequested) return true;
        uint32_t cnt = 0;
        for (auto child : m_children) {
            std::optional<bool> t = child.IsChecked();
            cnt += t.has_value() && *t;
        }
        if (cnt < m_children.Size()) return nullptr;
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
        return m_icon;
    }
    void FeatureViewModel::Icon(IconSource const &value)
    {
        m_icon = value;
        m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"Icon"});
    }
    Primitives::FlyoutBase FeatureViewModel::ContextMenu()
    {
        return m_menu;
    }
    void FeatureViewModel::ContextMenu(Primitives::FlyoutBase const &value)
    {
        m_menu = value;
        m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"ContextMenu"});
    }
}
