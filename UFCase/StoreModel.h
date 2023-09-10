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

class StoreModel : public Model<StoreModel>
{

    friend class ImageModel;
    ImageModel &image;
    com_ptr<IStore2> sxs_store;
    com_ptr<ICSIStore> csi_store;

    std::shared_ptr<WcpUtil::WcpGuard> wcp_guard;

    StoreModel(ImageModel *image, com_ptr<IStore2> pSxSStore,
               com_ptr<ICSIStore> pCSIStore,
               std::shared_ptr<WcpUtil::WcpGuard> wcp_guard);

  public:
    static StoreModel *Create(ImageModel *image);
};

} // namespace winrt::UFCase
