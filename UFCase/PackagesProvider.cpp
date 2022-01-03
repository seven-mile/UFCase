#include "pch.h"
#include "PackagesProvider.h"
#if __has_include("PackagesProvider.g.cpp")
#include "PackagesProvider.g.cpp"
#endif

#include "MallocUtil.h"
#include <wil/resource.h>

namespace winrt::UFCase::implementation
{
    template<class T, class IEnumT>
    inline std::vector<winrt::com_ptr<T>> GetIEnumComPtrVector(winrt::com_ptr<IEnumT> pEnum)
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

    winrt::event_token PackagesProvider::PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value)
    {
        return m_propertyChanged.add(value);
    }

    void PackagesProvider::PropertyChanged(winrt::event_token const& token)
    {
        m_propertyChanged.remove(token);
    }

    IAsyncOperation<UFCase::PackagesProvider> PackagesProvider::LoadFromImage(UFCase::ImageItem img)
    {
        winrt::apartment_context exception_context;
        co_await winrt::resume_background();

        UFCase::PackagesProvider z;

        auto pz = winrt::get_self<PackagesProvider>(z);
        pz->m_img = img;

        pz->pSess = CbsProviderManager::Current().ApplyFromBootdrive(sessionClient, img.Bootdrive().c_str())->ApplySession();

        LOG_IF_FAILED(pz->pSess->Initialize(CbsSessionOptionNone, L"UFCase", nullptr, nullptr));

        com_ptr<IEnumCbsIdentity> pIds;
        auto hr = pz->pSess->EnumeratePackages(0x1b0, pIds.put());
        for (auto&& id : GetIEnumComPtrVector<ICbsIdentity>(pIds)) {
            unique_malloc_wstring wsId;
            id->GetStringId(wil::out_param(wsId));
            auto &&pkg = PackageViewModel::LoadFromIdentity(sessionClient, wsId.get());
            z.Packages().Append(pkg);
        }

        {
            _CbsRequiredAction ra{ CbsRequiredActionNone };
            LOG_IF_FAILED(pz->pSess->Finalize(&ra));
        }

        co_return z;
    }
    PackagesProvider::list_t PackagesProvider::Packages()
    {
        return m_pkgs;
    }
}
