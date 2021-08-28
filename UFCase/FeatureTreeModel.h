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

        winrt::IMap<winrt::hstring, ele_t> m_mapEle
            = multi_threaded_map<winrt::hstring, ele_t>();
        winrt::IMap<winrt::hstring, winrt::hstring> m_mapFa
            = multi_threaded_map<winrt::hstring, winrt::hstring>();
        
        winrt::com_ptr<ICbsSession> pSess;

        void AddDependency(
            const winrt::hstring& szParentUpdate,
            const winrt::hstring& szSonName,
            const winrt::hstring& szSonDesc,
            bool isSonEnabled,
            const winrt::hstring& szSonUpdate);
        winrt::hstring GetFather(const winrt::hstring& szUpdateName) const;
        winrt::hstring GetRoot() const;
        void ClearTree();

        class CbsHelper {
        public:
            template <class T, class IEnumT>
            static std::vector<winrt::com_ptr<T>> GetIEnumComPtrVector(winrt::com_ptr<IEnumT> pEnum);
            static winrt::com_ptr<ICbsPackage> FindFoundationPkg(winrt::com_ptr<ICbsSession> pSess);
        };

    public:
        FeatureTreeModel();
        ~FeatureTreeModel();

        // delete other for global identity
        FeatureTreeModel(const FeatureTreeModel&) = delete;
        FeatureTreeModel(FeatureTreeModel&&) = delete;

        winrt::IAsyncOperationWithProgress<winrt::IObservableVector<FeatureTreeElement>, uint32_t> ConstructUpdateTree();
    };


    template<class T, class IEnumT>
    inline std::vector<winrt::com_ptr<T>> FeatureTreeModel::CbsHelper::GetIEnumComPtrVector(winrt::com_ptr<IEnumT> pEnum)
    {
        std::vector<winrt::com_ptr<T>> v{};
        ULONG k;
        do {
            winrt::com_ptr<T> ptr;
            pEnum->Next(1lu, ptr.put(), &k);
            if (ptr) v.push_back(ptr);
        } while (k);

        return v;
    }

}


