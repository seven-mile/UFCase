#pragma once
#include "Model.h"
#include "GitObject.h"
#include "CbsApi.h"

namespace winrt::UFCase {

    class ImageModel;
    class PackageModel;

    class SessionModel : public Model<SessionModel>,
                         public GitObject<ICbsSession>
    {
        friend class ImageModel;

        ImageModel &image;
        _CbsSessionOption option;
        DWORD session_cookie;
        std::unordered_map<hstring, uint64_t> packages;

        SessionModel(ImageModel* image, com_ptr<ICbsSession> session);
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
