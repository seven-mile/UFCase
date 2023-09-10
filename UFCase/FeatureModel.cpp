#include "pch.h"
#include "FeatureModel.h"
#include "PackageModel.h"
#include "SessionModel.h"

#include "CbsApi.h"
#include "MallocUtil.h"
#include <wil/resource.h>

namespace winrt::UFCase
{

    FeatureModel *FeatureModel::Create(com_ptr<ICbsUpdate> update, PackageModel *package)
    {
        return new FeatureModel{update, package};
    }

    hstring FeatureModel::Name() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsUpdatePropertyName, wil::out_param(ws)));
        return ws.get();
    }

    _CbsInstallState FeatureModel::CurrentState() const
    {
        _CbsInstallState state_current{}, state_intended{}, state_request{};
        check_hresult(
            GetInterface()->GetInstallState(&state_current, &state_intended, &state_request));
        return state_current;
    }

    _CbsInstallState FeatureModel::RequestedState() const
    {
        _CbsInstallState state_current{}, state_intended{}, state_request{};
        check_hresult(
            GetInterface()->GetInstallState(&state_current, &state_intended, &state_request));
        return state_request;
    }

    hstring FeatureModel::DisplayName() const
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsUpdatePropertyDisplayName, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::Description() const
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsUpdatePropertyDescription, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::DisplayFile() const
    {
        unique_malloc_wstring ws;
        check_hresult(
            GetInterface()->GetProperty(CbsUpdatePropertyDisplayFile, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::Restart() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsUpdatePropertyRestart, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::PsfName() const
    {
        unique_malloc_wstring ws;
        check_hresult(GetInterface()->GetProperty(CbsUpdatePropertyPsfName, wil::out_param(ws)));
        return ws.get();
    }

    hstring FeatureModel::DownloadSize() const
    {
        unique_malloc_wstring ws_download_size;
        check_hresult(GetInterface()->GetProperty(CbsUpdatePropertyDownloadSize,
                                                  wil::out_param(ws_download_size)));
        return ws_download_size.get();
    }

    hstring FeatureModel::SetMembership() const
    {
        // todo: find out what's this
        // unique_malloc_wstring ws_declared_set;
        //_CbsCardinality cardinality;
        // check_hresult(GetInterface()->GetDeclaredSet(8, wil::out_param(ws_declared_set),
        // &cardinality)); return ws_declared_set.get();
        return L"Not impl";
    }

    PackageModel *FeatureModel::RawParentPackage() const
    {
        return &package;
    }

    PackageModel *FeatureModel::RawFeaturePackage() const
    {
        com_ptr<ICbsPackage> pPkg;
        check_hresult(GetInterface()->GetPackage(pPkg.put()));

        auto pkg = PackageModel::Create(package.Session(), pPkg);
        OutputDebugString(pkg->Identity().c_str());
        OutputDebugString(L"\n");
        return pkg;
    }

    void FeatureModel::Enable()
    {
        check_hresult(GetInterface()->SetInstallState(0, CbsInstallStateInstallRequested));
    }

    void FeatureModel::Disable()
    {
        check_hresult(GetInterface()->SetInstallState(0, CbsInstallStateUninstallRequested));
    }

    std::vector<FeatureModel *> FeatureModel::GetParentFeatureCollection() const
    {
        constexpr HRESULT CBS_E_ARRAY_MISSING_INDEX = 0x800F0809, CBS_E_UNKNOWN_UPDATE = 0x800F080C;
        std::vector<FeatureModel *> res{};
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
                res.push_back(package.OpenFeature(ws_parent_name.get()));
            }
            catch (hresult_error const &hr)
            {
                if (hr.code() == CBS_E_UNKNOWN_UPDATE)
                {
                    // unknown update, ignore it
                    continue;
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
} // namespace winrt::UFCase
