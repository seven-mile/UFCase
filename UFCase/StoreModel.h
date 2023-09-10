#pragma once

#include "Model.h"

#include "csiapi.h"
#include "isolation.h"

namespace winrt::UFCase
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

    class ImageModel;

    class ComponentModel;

    class StoreModel : public Model<StoreModel>
    {
        friend class ImageModel;
        friend class ComponentModel;

        ImageModel &image;
        com_ptr<IStore2> sxs_store;
        com_ptr<ICSIStore> csi_store;

        com_ptr<IIdentityAuthority> ident_auth;
        com_ptr<IAppIdAuthority> appid_auth;

        std::shared_ptr<WcpUtil::WcpGuard> wcp_guard;

        std::unordered_map<ULONGLONG, uint64_t> components;

        StoreModel(ImageModel *image, com_ptr<IStore2> pSxSStore, com_ptr<ICSIStore> pCSIStore,
                   com_ptr<IIdentityAuthority> ident_auth, com_ptr<IAppIdAuthority> appid_auth,
                   std::shared_ptr<WcpUtil::WcpGuard> wcp_guard);

        ~StoreModel();

        std::optional<ComponentModel *> OpenComponent(com_ptr<IDefinitionIdentity> pDefIdent);
        std::vector<ComponentModel *> CreateModelsFromIEnumASM(com_ptr<IEnumSTORE_ASSEMBLY> pEnum);

      public:
        static StoreModel *Create(ImageModel *image);

        std::optional<ComponentModel *> OpenComponent(hstring id);
        std::vector<ComponentModel *> Components();
        std::vector<ComponentModel *> MatchComponents(hstring ref_id);
    };

} // namespace winrt::UFCase
