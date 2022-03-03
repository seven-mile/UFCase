#include "pch.h"
#include "CbsApi.h"
#include "FeatureTreeElement.h"
#if __has_include("FeatureTreeElement.g.cpp")
#include "FeatureTreeElement.g.cpp"
#endif

#include <winrt/Windows.Storage.Streams.h>

#include "CbsProviderManager.h"
#include "MallocUtil.h"
#include "CbsUtil.h"
#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    com_ptr<ICbsSession> FeatureTreeElement::GetSession()
    {
        return CbsProviderManager::Current().ApplyFromBootdrive(m_sessionClient, m_img.Bootdrive().c_str())->ApplySession();
    }
    com_ptr<ICbsUpdate> FeatureTreeElement::GetUpdate()
    {
        if (!m_pUpd) {
            check_hresult(FindFoundationPkg(GetSession())->GetUpdate(m_identity.c_str(), m_pUpd.put()));
        }
        return m_pUpd;
    }
    com_ptr<ICbsPackage> FeatureTreeElement::GetPackage()
    {
        if (!m_pPkg)
            this->GetUpdate()->GetPackage(m_pPkg.put());
        return m_pPkg;
    }

    FeatureTreeElement::FeatureTreeElement(hstring const& sessionClient, hstring const& name, hstring const& desc, hstring const& identity,
        FeatureState state, child_t children, UFCase::ImageItem img)
    {
        m_sessionClient = sessionClient;
        m_name = name;
        m_desc = desc;
        m_identity = identity;
        m_state = state;
        m_children = children;
        m_img = img;
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
    UFCase::PackageViewModel FeatureTreeElement::Package()
    {
        if (!m_PkgVM) {
            unique_malloc_wstring idstr;
            winrt::check_hresult(this->GetPackage()->GetProperty(CbsPackagePropertyIdentityString, wil::out_param(idstr)));

            m_PkgVM = UFCase::PackageViewModel::LoadFromIdentity(m_sessionClient, idstr.get());
        }
        return m_PkgVM;
    }
    void FeatureTreeElement::State(FeatureState const &value)
    {
        if (m_state == FeatureState::Invalid || value == FeatureState::PartiallyEnabled) {
            m_state = value;
            return;
        }

        auto pUpd = this->GetUpdate();
        OutputDebugString(std::format(L"pUpd = {}\n", reinterpret_cast<void*>(pUpd.get())).c_str());
        //if (value == )
        //pUpd->SetInstallState(0, );

        m_state = value;

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
