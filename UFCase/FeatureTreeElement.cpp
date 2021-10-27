#include "pch.h"
#include "FeatureTreeElement.h"
#if __has_include("FeatureTreeElement.g.cpp")
#include "FeatureTreeElement.g.cpp"
#endif

#include <winrt/Windows.Storage.Streams.h>

#include "CbsSessionManager.h"

namespace winrt::UFCase::implementation
{
    FeatureTreeElement::FeatureTreeElement(hstring name, hstring desc, hstring identity, FeatureState state, child_t children)
    {
        m_name = name;
        m_desc = desc;
        m_identity = identity;
        m_state = state;
        m_children = children;
    }

    winrt::event_token FeatureTreeElement::PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value)
    {
        return this->m_propertyChanged.add(value);
    }

    void FeatureTreeElement::PropertyChanged(winrt::event_token const& token)
    {
        this->m_propertyChanged.remove(token);
    }

    hstring FeatureTreeElement::Name()
    {
        return m_name;
    }
    void FeatureTreeElement::Name(const hstring &value)
    {
        m_name = value;
    }
    hstring FeatureTreeElement::Description()
    {
        return m_desc;
    }
    void FeatureTreeElement::Description(const hstring& value)
    {
        m_desc = value;
    }
    hstring FeatureTreeElement::Identity()
    {
        return m_identity;
    }
    void FeatureTreeElement::Identity(const hstring& value)
    {
        m_identity = value;
    }
    FeatureState FeatureTreeElement::State()
    {
        return m_state;
    }
    void FeatureTreeElement::State(FeatureState const &value)
    {
        if (m_state == FeatureState::Invalid) {
            m_state = value;
            return;
        }

        auto pSess = CbsSessionManager::instance().ApplyNew();

        // todo: use config
        winrt::check_hresult(pSess->Initialize(CbsSessionOptionNone, L"UFCase", nullptr, nullptr));

        // find foundation package
        winrt::com_ptr<ICbsPackage> pFound;
        {
            winrt::com_ptr<ICbsIdentity> pId;
        
            winrt::check_hresult(pSess->CreateCbsIdentity(pId.put()));

            winrt::check_hresult(pId->LoadFromStringId(L"@Foundation"));

            winrt::com_ptr<ICbsPackage> pPkgTmp;
            winrt::check_hresult(pSess->OpenPackage(0, pId.get(), nullptr, pPkgTmp.put()));
    
            // unmarshalling
            pFound = pPkgTmp.as<ICbsPackage>();
        }

        // open this update and initiate modification
        com_ptr<ICbsUpdate> pUpd;
        winrt::check_hresult(pFound->GetUpdate(m_identity.c_str(), pUpd.put()));
        OutputDebugString(std::format(L"pUpd = {}\n", reinterpret_cast<void*>(pUpd.get())).c_str());
        //if (value == )
        //pUpd->SetInstallState(0, );

        m_state = value;

        // finalize the session
        _CbsRequiredAction ra;
        winrt::check_hresult(pSess->Finalize(&ra));

        this->ModificationMark(L"*");
        m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"State"});
    }
    FeatureTreeElement::child_t FeatureTreeElement::Children()
    {
        return m_children;
    }

    hstring FeatureTreeElement::ModificationMark()
    {
        return m_mark;
    }
    void FeatureTreeElement::ModificationMark(hstring const &val)
    {
        m_mark = val;
        m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"ModificationMark"});
    }

    IconSource FeatureTreeElement::Icon()
    {
        return m_icon;
    }
    void FeatureTreeElement::Icon(IconSource const &value)
    {
        m_icon = value;
        m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"Icon"});
    }
    Primitives::FlyoutBase FeatureTreeElement::ContextMenu()
    {
        return m_menu;
    }
    void FeatureTreeElement::ContextMenu(Primitives::FlyoutBase const &value)
    {
        m_menu = value;
        m_propertyChanged(*this, Data::PropertyChangedEventArgs{L"ContextMenu"});
    }
}
