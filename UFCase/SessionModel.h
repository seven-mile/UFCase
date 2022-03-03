#pragma once
#include "Model.h"
#include "CbsApi.h"

#include <set>

namespace winrt::UFCase {

    class ImageModel;
    class PackageModel;

    class SessionModel : public Model<SessionModel>
    {
        friend class ImageModel;

        ImageModel &image;
        _CbsSessionOption option;
        com_ptr<ICbsSession> session;
        std::unordered_map<hstring, uint64_t> packages;

        SessionModel(ImageModel* image, _CbsSessionOption option);
        static SessionModel* Create(ImageModel* image, _CbsSessionOption option = CbsSessionOptionNone);

        PackageModel* OpenPackageWithoutHash(com_ptr<ICbsIdentity> identity);
    public:
        ~SessionModel();

        void SaveChanges();

        // 0x1b0 0x130
        std::vector<PackageModel*> Packages(DWORD option = 0x1b0);
        PackageModel* OpenPackage(com_ptr<ICbsIdentity> identity);
        PackageModel* OpenPackage(hstring const& identity);

        PackageModel* FoundationPackage();
        PackageModel* ProductPackage();
    };

}
