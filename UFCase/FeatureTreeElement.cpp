#include "pch.h"
#include "FeatureTreeElement.h"
#if __has_include("FeatureTreeElement.g.cpp")
#include "FeatureTreeElement.g.cpp"
#endif

#include <winrt/Windows.Storage.Streams.h>

#include "CbsProviderManager.h"
#include "MallocUtil.h"
#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    FeatureTreeElement::FeatureTreeElement(hstring name, hstring desc, hstring identity,
        FeatureState state, child_t children, UFCase::ImageItem img)
    {
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
        auto pSess = CbsProviderManager::Current().ApplyFromBootdrive(L"FeatureTree", m_img.Bootdrive().c_str())->ApplySession();

        // todo: use config
        winrt::check_hresult(pSess->Initialize(CbsSessionOptionNone, L"UFCase::FeatureTree", nullptr, nullptr));

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

        com_ptr<ICbsUpdate> pUpd;
        winrt::check_hresult(pFound->GetUpdate(m_identity.c_str(), pUpd.put()));
        com_ptr<ICbsPackage> pPkg;
        winrt::check_hresult(pUpd->GetPackage(pPkg.put()));
        unique_malloc_wstring idstr;
        winrt::check_hresult(pPkg->GetProperty(CbsPackagePropertyIdentityString, wil::out_param(idstr)));

        _CbsRequiredAction ra;
        winrt::check_hresult(pSess->Finalize(&ra));

        return UFCase::PackageViewModel::LoadFromIdentity(idstr.get());
    }
    void FeatureTreeElement::State(FeatureState const &value)
    {
        if (m_state == FeatureState::Invalid || value == FeatureState::PartiallyEnabled) {
            m_state = value;
            return;
        }

        auto pSess = CbsProviderManager::Current().ApplyFromBootdrive(L"FeatureTree", m_img.Bootdrive().c_str())->ApplySession();

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
