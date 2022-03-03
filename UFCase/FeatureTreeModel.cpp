#include "pch.h"
#include "FeatureTreeModel.h"

#include "MallocUtil.h"
#include "CbsProviderManager.h"
#include "CbsUtil.h"


#include <functional>

#include <wil/resource.h>

namespace winrt::UFCase
{

inline const CLSID CLSID_CbsSession = { 0x752073A1,0x23F2,0x4396,{0x85,0xF0,0x8F,0xDB,0x87,0x9E,0xD0,0xED} };

FeatureTreeModel::FeatureTreeModel(UFCase::ImageItem img)
{
    ClearTree();

    m_img = img;
    
    pSess = CbsProviderManager::Current().ApplyFromBootdrive(m_sessionClient, m_img.Bootdrive().c_str())->ApplySession();

    LOG_IF_FAILED(pSess->Initialize(CbsSessionOptionNone, L"UFCase", nullptr, nullptr));
}

FeatureTreeModel::~FeatureTreeModel()
{
    m_mapEle.Clear();
    m_mapFa.Clear();

    _CbsRequiredAction ra;
    pSess->Finalize(&ra); // I don't care

    CbsProviderManager::Current().Return(m_sessionClient, m_img.Bootdrive().c_str());
}

winrt::IAsyncOperationWithProgress<winrt::IObservableVector<FeatureTreeModel::ele_t>, uint32_t>
FeatureTreeModel::ConstructUpdateTree()
{
    auto report_prog = co_await winrt::get_progress_token();
    winrt::apartment_context exception_context;

    
    co_await winrt::resume_background();
    auto res = single_threaded_observable_vector<ele_t>();

    auto pFound = FindFoundationPkg(pSess);
    if (!pFound) winrt::check_win32(ERROR_NOT_FOUND);

    report_prog(10);

    auto joinUpdates = [=](winrt::com_ptr<IEnumCbsUpdate> pUpds) -> winrt::IAsyncActionWithProgress<uint32_t> {

        auto report_prog = co_await winrt::get_progress_token();

        auto&& vecUpds = GetIEnumComPtrVector<ICbsUpdate>(pUpds);

        const uint32_t ENUM_UPDATE_PROG = 30; // 30%
        report_prog(ENUM_UPDATE_PROG);

        co_await winrt::resume_background();

        uint32_t idx = 0, all = static_cast<uint32_t>(vecUpds.size());

        for (const auto& pUpd : vecUpds) {
            // ======== TEST WAIT =========
            // let loading progress slow down
#ifdef _DEBUG
            // using namespace std::chrono_literals;
            // co_await 3ms;
#endif
            // ======== TEST WAIT =========

            // calc current progress
            report_prog(ENUM_UPDATE_PROG + uint32_t(std::floor(1.0 * idx / all * (100 - ENUM_UPDATE_PROG))));

            unique_malloc_wstring szRawName, szName, szDesc, szParentName, szSet;
            winrt::check_hresult(pUpd->GetProperty(CbsUpdatePropertyName, wil::out_param(szRawName)));
            winrt::check_hresult(pUpd->GetProperty(CbsUpdatePropertyDisplayName, wil::out_param(szName)));
            winrt::check_hresult(pUpd->GetProperty(CbsUpdatePropertyDescription, wil::out_param(szDesc)));

            if (lstrlenW(szName.get()) <= 0) continue;

            const int CBS_E_ARRAY_ELEMENT_MISSING = -2146498551;
            auto hr = pUpd->GetParentUpdate(0, wil::out_param(szParentName), wil::out_param(szSet));

            _CbsInstallState stCur, stInt, stReq;
            winrt::check_hresult(pUpd->GetInstallState(&stCur, &stInt, &stReq));

            const FeatureState eState = stCur >= CbsInstallStateInstalled ? //stReq == CbsInstallStateInstallRequested ?
                                        FeatureState::Enabled : FeatureState::Disabled;

            const bool hasParent = hr != CBS_E_ARRAY_ELEMENT_MISSING;
            if (hasParent) {
                if (SUCCEEDED(hr))
                    AddDependency(szParentName.get(), szName.get(), szDesc.get(), eState, szRawName.get());
                else {
                    winrt::check_hresult(hr);
                }
            }
            else {
                AddDependency(GetRoot(), szName.get(), szDesc.get(), eState, szRawName.get());
            }
            idx++;
        }
        co_return;
    };

    winrt::IAsyncActionWithProgress<uint32_t> join_op1, join_op2;
    uint32_t prog1 = 0, prog2 = 0;
    {
        winrt::com_ptr<IEnumCbsUpdate> pUpds;
        winrt::check_hresult(pFound->EnumerateUpdates(CbsApplicabilityApplicable, CbsSelectabilityRootClass, pUpds.put()));

        join_op1 = joinUpdates(pUpds);
        join_op1.Progress([&](const auto &, const uint32_t &pr){
            prog1 = pr;
            report_prog(10 + uint32_t(std::floor(0.9 * (prog1 + prog2) / 2)));
        });
    }
    {
        winrt::com_ptr<IEnumCbsUpdate> pUpds;
        winrt::check_hresult(pFound->EnumerateUpdates(CbsApplicabilityNeedsParent, CbsSelectabilityAllClass, pUpds.put()));

        join_op2 = joinUpdates(pUpds);
        join_op2.Progress([&](const auto &, const uint32_t &pr){
            prog2 = pr;
            report_prog(10 + uint32_t(std::floor(0.9 * (prog1 + prog2) / 2)));
        });
    }

    co_await join_op1;
    co_await join_op2;

    report_prog(100);
    
    co_return m_mapEle.Lookup(GetRoot()).Children();
}

void FeatureTreeModel::AddDependency(
            const winrt::hstring& szParentUpdate,
            const winrt::hstring& szSonName,
            const winrt::hstring& szSonDesc,
            FeatureState eSonState,
            const winrt::hstring& szSonUpdate)
{
    if (m_mapFa.HasKey(szSonUpdate)) return;
    m_mapFa.Insert(szSonUpdate, szParentUpdate);
    
    if (m_mapEle.HasKey(szSonUpdate)) {
        auto sonNode = m_mapEle.Lookup(szSonUpdate);
        sonNode.Name(szSonName);
        sonNode.Description(szSonDesc);
        sonNode.State(eSonState);
        sonNode.Identity(szSonUpdate);
    } else {
        auto newSonNode = ele_t(m_sessionClient, szSonName, szSonDesc, szSonUpdate, eSonState, multi_threaded_observable_vector<ele_t>(), m_img);
        m_mapEle.Insert(szSonUpdate, newSonNode);
    }

    if (!m_mapEle.HasKey(szParentUpdate)) {
        auto newParentNode = ele_t(m_sessionClient, L"", L"", L"", FeatureState::Invalid, multi_threaded_observable_vector<ele_t>(), m_img);
        m_mapEle.Insert(szParentUpdate, newParentNode);
    }
    
    m_mapEle.Lookup(szParentUpdate).Children().Append(m_mapEle.Lookup(szSonUpdate));

    cntUpdates++;
}

winrt::hstring FeatureTreeModel::GetFather(const winrt::hstring& szUpdateName) const
{
    static winrt::hstring nullResult = L"(null)";
    if (auto opt = m_mapFa.TryLookup(szUpdateName); opt.has_value()) {
        return *opt;
    } else {
        return nullResult;
    }
}

winrt::hstring FeatureTreeModel::GetRoot() const
{
    static winrt::hstring strRootName = L"#ROOT#";
    return strRootName;
}

void FeatureTreeModel::ClearTree()
{
    m_mapEle.Clear();
    m_mapFa.Clear();
    cntUpdates = 1u;
    m_mapEle.Insert(GetRoot(), ele_t(m_sessionClient, GetRoot(), L"", L"", FeatureState::Unavailable, multi_threaded_observable_vector<ele_t>(), m_img));
}

}

