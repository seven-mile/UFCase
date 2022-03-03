#include "pch.h"
#include "FeatureModel.h"
#include "PackageModel.h"

#include "CbsApi.h"
#include "MallocUtil.h"
#include <wil/resource.h>

namespace winrt::UFCase {

    FeatureModel* FeatureModel::Create(com_ptr<ICbsUpdate> update, uint64_t parent)
    {
        return new FeatureModel{ update, PackageModel::GetInstance(parent)};
    }

    FeatureModel* FeatureModel::Create(com_ptr<ICbsUpdate> update, PackageModel &parent)
    {
        return new FeatureModel{ update, parent };
    }

    hstring FeatureModel::Name()
    {
        return hstring();
    }

    _CbsInstallState FeatureModel::State()
    {
        return _CbsInstallState();
    }

    hstring FeatureModel::DisplayName()
    {
        unique_malloc_wstring ws;
        update->GetProperty(CbsUpdatePropertyDisplayName, wil::out_param(ws));
        return ws.get();
    }

    hstring FeatureModel::Description()
    {
        unique_malloc_wstring ws;
        update->GetProperty(CbsUpdatePropertyDescription, wil::out_param(ws));
        return ws.get();
    }

    hstring FeatureModel::DisplayFile()
    {
        unique_malloc_wstring ws;
        update->GetProperty(CbsUpdatePropertyDisplayFile, wil::out_param(ws));
        return ws.get();
    }

    hstring FeatureModel::Restart()
    {
        unique_malloc_wstring ws;
        update->GetProperty(CbsUpdatePropertyRestart, wil::out_param(ws));
        return ws.get();
    }

    hstring FeatureModel::PsfName()
    {
        unique_malloc_wstring ws;
        update->GetProperty(CbsUpdatePropertyPsfName, wil::out_param(ws));
        return ws.get();
    }

    hstring FeatureModel::DownloadSize()
    {
        unique_malloc_wstring ws_download_size;
        update->GetProperty(CbsUpdatePropertyDownloadSize, wil::out_param(ws_download_size));
        return ws_download_size.get();
    }

    hstring FeatureModel::SetMembership()
    {
        unique_malloc_wstring ws_declared_set;
        _CbsCardinality cardinality;
        update->GetDeclaredSet(8, wil::out_param(ws_declared_set), &cardinality);
        return ws_declared_set.get();
    }

    PackageModel *FeatureModel::RawParentPackage()
    {
        return &parent;
    }

    void FeatureModel::Enable()
    {
        check_hresult(update->SetInstallState(0, CbsInstallStateInstallRequested));
    }

    void FeatureModel::Disable()
    {
        check_hresult(update->SetInstallState(0, CbsInstallStateUninstallRequested));
    }

    std::vector<FeatureModel*> FeatureModel::GetParentFeatureCollection()
    {
        constexpr HRESULT CBS_E_ARRAY_MISSING_INDEX = 0x800F0809;
        std::vector<FeatureModel*> res{};
        for (uint32_t idx = 0; ; idx++) {
            unique_malloc_wstring ws_parent_name, ws_parent_set;
            auto hr = update->GetParentUpdate(idx, wil::out_param(ws_parent_name), wil::out_param(ws_parent_set));
            if (hr == CBS_E_ARRAY_MISSING_INDEX) break;
            check_hresult(hr);

            res.push_back(parent.OpenFeature(ws_parent_name.get()));
        }
        return res;
    }
}

