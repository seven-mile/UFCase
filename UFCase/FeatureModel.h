#pragma once
#include "Model.h"
#include "CbsApi.h"
#include "GitObject.h"

namespace winrt::UFCase {

    class PackageModel;

    class FeatureModel : public Model<FeatureModel>,
                         public GitObject<ICbsUpdate>
    {
        PackageModel &package;

        FeatureModel(com_ptr<ICbsUpdate> update, PackageModel *package)
            : GitObject(update), package(*package) {  }

        friend class PackageModel;
        static FeatureModel* Create(com_ptr<ICbsUpdate> update, PackageModel *parent);
    public:

        hstring Name() const;
        _CbsInstallState CurrentState() const;
        _CbsInstallState RequestedState() const;
        hstring DisplayName() const;
        hstring Description() const;
        hstring DisplayFile() const;
        hstring Restart() const;
        hstring PsfName() const;
        hstring DownloadSize() const;
        hstring SetMembership() const;
        PackageModel *RawParentPackage() const;
        PackageModel *RawFeaturePackage() const;
        void Enable();
        void Disable();
        std::vector<FeatureModel*> GetParentFeatureCollection() const;
    };

}

