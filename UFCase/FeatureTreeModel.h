#pragma once

#include "FeatureTreeElement.g.h"
#include "CbsApi.h"

#include <vector>
#include <string>

namespace winrt::UFCase
{
    class FeatureTreeModel
    {
        uint32_t cntUpdates;

        using ele_t = FeatureTreeElement;

        const wchar_t *m_sessionClient = L"FeatureTree";

        winrt::IMap<winrt::hstring, ele_t> m_mapEle
            = multi_threaded_map<winrt::hstring, ele_t>();
        winrt::IMap<winrt::hstring, winrt::hstring> m_mapFa
            = multi_threaded_map<winrt::hstring, winrt::hstring>();
        
        UFCase::ImageItem m_img;
        winrt::com_ptr<ICbsSession> pSess;

        void AddDependency(
            const winrt::hstring& szParentUpdate,
            const winrt::hstring& szSonName,
            const winrt::hstring& szSonDesc,
            FeatureState eSonState,
            const winrt::hstring& szSonUpdate);
        winrt::hstring GetFather(const winrt::hstring& szUpdateName) const;
        winrt::hstring GetRoot() const;
        void ClearTree();

    public:
        FeatureTreeModel(UFCase::ImageItem img);
        ~FeatureTreeModel();

        // delete other for global identity
        FeatureTreeModel(const FeatureTreeModel&) = delete;
        FeatureTreeModel(FeatureTreeModel&&) = delete;

        winrt::IAsyncOperationWithProgress<winrt::IObservableVector<ele_t>, uint32_t> ConstructUpdateTree();
    };

}


