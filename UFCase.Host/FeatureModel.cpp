#include "pch.h"
#include "FeatureModel.h"
#if __has_include("FeatureModel.g.cpp")
#include "FeatureModel.g.cpp"
#endif

#include "PackageModel.h"
#include "Utils/MallocUtil.h"

namespace winrt::UFCase::Isolation::implementation
{
    hstring FeatureModel::Name()
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsUpdatePropertyName, wil::out_param(ws)));
        return ws.get();
    }

    CbsInstallState FeatureModel::CurrentState()
    {
        ::_CbsInstallState state_current{}, state_intended{}, state_request{};
        check_hresult(
            GetInterface()->GetInstallState(&state_current, &state_intended, &state_request));
        return static_cast<CbsInstallState>(state_current);
    }

    CbsInstallState FeatureModel::RequestedState()
    {
        ::_CbsInstallState state_current{}, state_intended{}, state_request{};
        check_hresult(
            GetInterface()->GetInstallState(&state_current, &state_intended, &state_request));
        return static_cast<CbsInstallState>(state_request);
    }

    hstring FeatureModel::DisplayName()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsUpdatePropertyDisplayName, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::Description()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsUpdatePropertyDescription, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::DisplayFile()
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsUpdatePropertyDisplayFile, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::Restart()
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsUpdatePropertyRestart, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::PsfName()
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsUpdatePropertyPsfName, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::DownloadSize()
    {
        unique_malloc_wstring ws_download_size;
        check_hresult(GetInterface()->GetProperty(CbsUpdatePropertyDownloadSize,
                                                  wil::out_param(ws_download_size)));
        return ws_download_size.get();
    }

    hstring FeatureModel::SetMembership()
    {
        // todo: find out what's this
        // unique_malloc_wstring ws_declared_set;
        //_CbsCardinality cardinality;
        // check_hresult(GetInterface()->GetDeclaredSet(8, wil::out_param(ws_declared_set),
        // &cardinality)); return ws_declared_set.get();
        return L"Not impl";
    }

    Isolation::PackageModel FeatureModel::ContentPackage()
    {
        com_ptr<ICbsPackage> pPkg;
        check_hresult(GetInterface()->GetPackage(pPkg.put()));
        if (auto self_pkg = m_package)
        {
            auto pkg = make<implementation::PackageModel>(self_pkg.Session(), pPkg);
            return pkg;
        }
        return {nullptr};
    }

    void FeatureModel::Enable()
    {
        check_hresult(GetInterface()->SetInstallState(0, CbsInstallStateInstallRequested));
    }

    void FeatureModel::Disable()
    {
        check_hresult(GetInterface()->SetInstallState(0, CbsInstallStateUninstallRequested));
    }

    Windows::Foundation::Collections::IVector<Isolation::FeatureModel> FeatureModel::
        GetParentFeatureCollection()
    {
        constexpr HRESULT CBS_E_ARRAY_MISSING_INDEX = 0x800F0809, CBS_E_UNKNOWN_UPDATE = 0x800F080C,
                          CBS_E_DUPLICATE_UPDATENAME = 0x800F0819;
        auto res = single_threaded_vector<Isolation::FeatureModel>();
        for (uint32_t idx = 0;; idx++)
        {
            unique_malloc_wstring ws_parent_name, ws_parent_set;
            auto hr = GetInterface()->GetParentUpdate(idx, wil::out_param(ws_parent_name),
                                                      wil::out_param(ws_parent_set));

            // no more parents
            if (hr == CBS_E_ARRAY_MISSING_INDEX)
                break;

            if (FAILED(hr))
                throw_hresult(hr);

            try
            {
                res.Append(m_package.OpenFeature(ws_parent_name.get()));
            }
            catch (hresult_error const &hr)
            {
                if (hr.code() == CBS_E_UNKNOWN_UPDATE)
                {
                    // unknown update, ignore it
                    continue;
                }
                else if (hr.code() == CBS_E_DUPLICATE_UPDATENAME)
                {
                    // duplicate update name, fallback to enumeration
                    for (auto upd : m_package.GetFeatureCollection(CbsApplicabilityApplicable,
                                                         CbsSelectabilityAllClass)) {
                        if (upd.Name() == ws_parent_name.get()) {
                            res.Append(upd);
                            break;
                        }
                    }
                }
                else
                {
                    // rethrow
                    throw hr;
                }
            }
        }

        return res;
    }
} // namespace winrt::UFCase::Isolation::implementation
