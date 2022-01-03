#include "pch.h"
#include "PackageViewModel.h"
#if __has_include("PackageViewModel.g.cpp")
#include "PackageViewModel.g.cpp"
#endif

#include "CbsProviderManager.h"
#include "MallocUtil.h"
#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    UFCase::PackageViewModel PackageViewModel::LoadFromIdentity(hstring const& sessionClient, hstring const& id)
    {
        UFCase::PackageViewModel res{ sessionClient };

        res.Identity(id);

        auto pSess = CbsProviderManager::Current().ApplyFromBootdrive(sessionClient,
            CbsProviderManager::GetOnlineBootdrive())->ApplySession();

        com_ptr<ICbsIdentity> pId;
        check_hresult(pSess->CreateCbsIdentity(pId.put()));

        check_hresult(pId->LoadFromStringId(id.c_str()));
        com_ptr<ICbsPackage> pPkg;
        check_hresult(pSess->OpenPackage(0, pId.get(), nullptr, pPkg.put()));

        pPkg = pPkg.as<ICbsPackage>();

        unique_malloc_wstring dsnameOutParam, descOutParam, reltypeOutParam;
        check_hresult(pPkg->GetProperty(CbsPackagePropertyDisplayName, wil::out_param(dsnameOutParam)));
        check_hresult(pPkg->GetProperty(CbsPackagePropertyDescription, wil::out_param(descOutParam)));
        check_hresult(pPkg->GetProperty(CbsPackagePropertyReleaseType, wil::out_param(reltypeOutParam)));
        res.DisplayName(dsnameOutParam.get());
        res.Description(descOutParam.get());
        res.ReleaseType(reltypeOutParam.get());

        // state
        {
            _CbsInstallState stApp, stCur;
            check_hresult(pPkg->EvaluateApplicability(0, &stApp, &stCur));
            // map it
            if (stCur == CbsInstallStatePartiallyInstalled)
                res.State(PackageState::PartiallyInstalled);
            else if (stCur == CbsInstallStateCancel)
                res.State(PackageState::Cancel);
            else if (stCur == CbsInstallStateSuperseded)
                res.State(PackageState::Superseded);
            else if (stCur == CbsInstallStateDefault)
                res.State(PackageState::Default);
            else if (stCur == CbsInstallStateAbsent)
                res.State(PackageState::Absent);
            else if (stCur == CbsInstallStateResolving)
                res.State(PackageState::Resolving);
            else if (stCur == CbsInstallStateResolved)
                res.State(PackageState::Resolved);
            else if (stCur == CbsInstallStateStaging)
                res.State(PackageState::Staging);
            else if (stCur == CbsInstallStateStaged)
                res.State(PackageState::Staged);
            else if (stCur == CbsInstallStateUninstallRequested)
                res.State(PackageState::UninstallRequested);
            else if (stCur == CbsInstallStateInstallRequested)
                res.State(PackageState::InstallRequested);
            else if (stCur == CbsInstallStateInstalled)
                res.State(PackageState::Installed);
            else if (stCur == CbsInstallStatePermanent)
                res.State(PackageState::Permanent);
            else res.State(PackageState::Unknown);
        }

        return res;
    }
    com_ptr<ICbsSession> PackageViewModel::GetSession()
    {
        return CbsProviderManager::Current().ApplyFromBootdrive(m_sessionClient,
            CbsProviderManager::GetOnlineBootdrive())->ApplySession();
    }
    com_ptr<ICbsPackage> PackageViewModel::GetPackage()
    {
        if (!m_pPkg) {
            com_ptr<ICbsIdentity> pId;
            auto pSess = this->GetSession();
            check_hresult(pSess->CreateCbsIdentity(pId.put()));
            check_hresult(pId->LoadFromStringId(id.c_str()));

            check_hresult(pSess->OpenPackage(0, pId.get(), nullptr, m_pPkg.put()));
            m_pPkg = m_pPkg.as<ICbsPackage>();
        }
        return m_pPkg;
    }
    PackageViewModel::PackageViewModel(hstring sessionClient) : m_sessionClient(sessionClient)
    {
    }
    hstring PackageViewModel::Identity()
    {
        return id;
    }
    void PackageViewModel::Identity(hstring const& val)
    {
        id = val;
    }
    hstring PackageViewModel::DisplayName()
    {
        return displayName;
    }
    void PackageViewModel::DisplayName(hstring const& val)
    {
        displayName = val;
    }
    hstring PackageViewModel::Description()
    {
        return description;
    }
    void PackageViewModel::Description(hstring const& val)
    {
        description = val;
    }
    PackageState PackageViewModel::State()
    {
        return state;
    }
    void PackageViewModel::State(PackageState const& val)
    {
        state = val;
    }
    hstring PackageViewModel::ReleaseType()
    {
        return reltype;
    }
    void PackageViewModel::ReleaseType(hstring const& val)
    {
        reltype = val;
    }

    template <class T, class IEnumT>
    inline std::vector<T> GetIEnumStructVector(com_ptr<IEnumT> pEnum)
    {
        std::vector<T> v;
        ULONG* pk = new ULONG;

        while (true) {
            T ptr;
            pEnum->Next(1, &ptr, pk);
            if (*pk) v.push_back(ptr);
            else break;
        }

        return v;
    }

    hstring PackageViewModel::GetFSPath()
    {
        //auto pSess = CbsProviderManager::Current().ApplyFromBootdrive(L"PackageViewModel",
        //	CbsProviderManager::GetOnlineBootdrive())->ApplySession();
        //check_hresult(pSess->Initialize(CbsSessionOptionNone, L"UFCase::PackageViewModel", nullptr, nullptr));

        //com_ptr<ICbsIdentity> pId;
        //check_hresult(pSess->CreateCbsIdentity(pId.put()));

        //check_hresult(pId->LoadFromStringId(id.c_str()));
        //com_ptr<ICbsPackage> pPkg;
        //check_hresult(pSess->OpenPackage(0, pId.get(), nullptr, pPkg.put()));

        //pPkg = pPkg.as<ICbsPackage>();

        //unique_malloc_wstring insPath;
        //check_hresult(pPkg->GetProperty(CbsPackagePropertyReleaseQuality, wil::out_param(insPath)));

        //com_ptr<IEnumString> strList;
        //check_hresult(pPkg->EnumerateSources(strList.put()));
        //
        //for (wchar_t *strSrc : GetIEnumStructVector<LPWSTR>(strList)) {
        //	auto uSrc = make_malloc(strSrc);
        //	OutputDebugString(std::format(L"{}\n", uSrc.get()).c_str());
        //}

        ////ICbsUpdate::GetProperty(CbsUpdatePropertyDisplayFile, wil::out_param(insPath));

        //_CbsRequiredAction ra{};
        //check_hresult(pSess->Finalize(&ra));

        //return insPath.get();

        // get software reg path
        // todo: support offline => extend image provider bootdrive

        hstring pathWinSxS = L"C:\\Windows\\WinSxS";
        if (pathWinSxS.back() == L'\\') {
            pathWinSxS = pathWinSxS + id;
        } else {
            pathWinSxS = pathWinSxS + L"\\" + id;
        }

        // wrong path!
        return pathWinSxS;
    }
    hstring PackageViewModel::GetRegPath()
    {
        // get software reg path
        // todo: support offline => use reg provider
        hstring pathSoftware = L"SOFTWARE";

        if (pathSoftware.back() == L'\\') {
            pathSoftware = pathSoftware + L"Microsoft\\Windows\\CurrentVersion\\Component Based Servicing\\Packages\\" + id;
        } else {
            pathSoftware = pathSoftware + L"\\Microsoft\\Windows\\CurrentVersion\\Component Based Servicing\\Packages\\" + id;
        }

        return pathSoftware;
    }
    hstring PackageViewModel::GetSupportUrl()
    {
        auto pSess = CbsProviderManager::Current().ApplyFromBootdrive(L"PackageViewModel",
            CbsProviderManager::GetOnlineBootdrive())->ApplySession();
        check_hresult(pSess->Initialize(CbsSessionOptionNone, L"UFCase::PackageViewModel", nullptr, nullptr));

        com_ptr<ICbsIdentity> pId;
        check_hresult(pSess->CreateCbsIdentity(pId.put()));

        check_hresult(pId->LoadFromStringId(id.c_str()));
        com_ptr<ICbsPackage> pPkg;
        check_hresult(pSess->OpenPackage(0, pId.get(), nullptr, pPkg.put()));

        pPkg = pPkg.as<ICbsPackage>();

        _CbsInstallState st1, st2;
        check_hresult(pPkg->EvaluateApplicability(0, &st1, &st2));

        unique_malloc_wstring resUrl;
        check_hresult(pPkg->GetProperty(CbsPackagePropertySupportInformation, wil::out_param(resUrl)));

        _CbsRequiredAction ra{};
        check_hresult(pSess->Finalize(&ra));

        return resUrl.get();
    }
}
