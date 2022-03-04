#pragma once
#include "Model.h"
#include "CbsApi.h"

namespace winrt::UFCase {

    class PackageModel;

    class FeatureModel : public Model<FeatureModel>
    {
        com_ptr<ICbsUpdate> update;
        PackageModel &package;

        FeatureModel(com_ptr<ICbsUpdate> update, PackageModel *package)
            : update(update), package(*package) {  }

        friend class PackageModel;
        static FeatureModel* Create(com_ptr<ICbsUpdate> update, PackageModel *parent);
    public:

        hstring Name() const;
        _CbsInstallState State() const;
        hstring DisplayName() const;
        hstring Description() const;
        hstring DisplayFile() const;
        hstring Restart() const;
        hstring PsfName() const;
        hstring DownloadSize() const;
        hstring SetMembership() const;
        PackageModel *RawParentPackage() const;
        void Enable();
        void Disable();
        std::vector<FeatureModel*> GetParentFeatureCollection() const;
    };

}

