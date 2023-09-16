#pragma once

#include "StoreModel.g.h"

#include "ServicingApi/Isolation.h"
#include "ServicingApi/CsiApi.h"

#include "Utils/GeneratorUtil.h"

namespace winrt::UFCase::Isolation::implementation
{
    namespace WcpUtil
    {
        class WcpGuard
        {
            PVOID pCookie{nullptr};

          public:
            WcpGuard(winrt::com_ptr<IMalloc> pMalloc);
            ~WcpGuard();

            static std::shared_ptr<WcpGuard> GetStrong();
        };

    } // namespace WcpUtil

    struct StoreModel : StoreModelT<StoreModel>
    {
        StoreModel(Isolation::ImageModel image) : m_image(image)
        {
            Initialize();
        }

      public:
        Isolation::ComponentModel OpenComponent(hstring id);

        Windows::Foundation::Collections::IIterable<IInspectable> GetComponentCollection();
        Windows::Foundation::Collections::IIterable<IInspectable> GetComponentCollection(
            hstring ref_id);

        com_ptr<IStore2> m_sxs_store;
        com_ptr<ICSIStore> m_csi_store;

        com_ptr<IIdentityAuthority> m_ident_auth{nullptr};
        com_ptr<IAppIdAuthority> m_appid_auth{nullptr};

      private:
        Isolation::ImageModel m_image;

        std::shared_ptr<WcpUtil::WcpGuard> wcp_guard{nullptr};

        std::unordered_map<ULONGLONG, uint64_t> components;

        Isolation::ComponentModel OpenComponent(com_ptr<IDefinitionIdentity> pDefIdent);
        Generator<Isolation::ComponentModel> CreateModelsFromIEnumASM(
            com_ptr<IEnumSTORE_ASSEMBLY> pEnum);

        void Initialize();
    };
} // namespace winrt::UFCase::Isolation::implementation

// namespace winrt::UFCase::Isolation::factory_implementation
// {
//     struct StoreModel : StoreModelT<StoreModel, implementation::StoreModel>
//     {
//     };
// } // namespace winrt::UFCase::Isolation::factory_implementation
