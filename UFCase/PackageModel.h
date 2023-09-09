#pragma once
#include "Model.h"

#include "CbsApi.h"
#include "GitObject.h"

namespace winrt::UFCase {

    class FeatureModel;
    class SessionModel;

    class PackageModel : public Model<PackageModel>,
                         public GitObject<ICbsPackage>
    {
        friend class SessionModel;
        friend class FeatureModel;
        SessionModel &session;
        std::unordered_map<hstring, uint64_t> updates;

        PackageModel(SessionModel *session, com_ptr<ICbsPackage> package) : session(*session), GitObject(package) { }
        static PackageModel* Create(SessionModel* session, com_ptr<ICbsPackage> package);
    public:

        SessionModel* Session() const;
    
        hstring Identity() const;
        hstring ReleaseType() const;
        _CbsInstallState State() const;
        hstring Name() const;
        hstring Description() const;
        hstring RestartRequired() const;
        hstring ProductName() const;
        hstring ProductVersion() const;
        hstring Company() const;
        hstring Copyright() const;
        hstring SupportInformation() const;
        hstring CreationTime() const;
        hstring LastUpdateTime() const;
        hstring InstallTime() const;
        hstring InstallPackageName() const;
        hstring InstallLocation() const;
        hstring InstallClient() const;
        hstring InstallUserName() const;
        bool IsApplicable() const;
        void Install() const;
        void Remove() const;
        void Stage() const;
        FeatureModel* OpenFeature(hstring const &name);
        std::vector<FeatureModel*> GetPackageFeatureCollection(
            _CbsApplicability appl = CbsApplicabilityNotApplicable,
            _CbsSelectability sele = CbsSelectabilityRootClass);
    };

}
