#pragma once
#include "Model.h"
#include "CbsApi.h"

namespace winrt::UFCase {

    class FeatureModel : public Model<FeatureModel>
    {
        com_ptr<ICbsUpdate> update;
        struct PackageModel &parent;
        FeatureModel(com_ptr<ICbsUpdate> update, PackageModel &parent)
            : update(update), parent(parent) {  }
    public:
        static FeatureModel* Create(com_ptr<ICbsUpdate> update, uint64_t parent);
        static FeatureModel* Create(com_ptr<ICbsUpdate> update, PackageModel &parent);

        hstring Name();
        _CbsInstallState State();
        hstring DisplayName();
        hstring Description();
        hstring DisplayFile();
        hstring Restart();
        hstring PsfName();
        hstring DownloadSize();
        hstring SetMembership();
        PackageModel *RawParentPackage();
        void Enable();
        void Disable();
        std::vector<FeatureModel*> GetParentFeatureCollection();
    };

}

