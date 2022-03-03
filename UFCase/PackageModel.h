#pragma once
#include "Model.h"

#include "CbsApi.h"

namespace winrt::UFCase {

    class FeatureModel;
    class SessionModel;

    class PackageModel : public Model<PackageModel>
    {
        friend class SessionModel;
        SessionModel &session;
        com_ptr<ICbsPackage> package;
        std::unordered_map<hstring, uint64_t> updates;

        PackageModel(SessionModel *session, com_ptr<ICbsPackage> package) : session(*session), package(package) { }
        static PackageModel* Create(SessionModel* session, com_ptr<ICbsPackage> package);
    public:
    
        hstring Identity();
        hstring ReleaseType();
        _CbsInstallState State();
        hstring Name();
        hstring Description();
        hstring RestartRequired();
        hstring ProductName();
        hstring ProductVersion();
        hstring Company();
        hstring Copyright();
        hstring SupportInformation();
        hstring CreationTime();
        hstring LastUpdateTime();
        hstring InstallTime();
        hstring InstallPackageName();
        hstring InstallLocation();
        hstring InstallClient();
        hstring InstallUserName();
        bool IsApplicable();
        void Install();
        void Remove();
        void Stage();
        FeatureModel* OpenFeature(hstring const &name);
        std::vector<FeatureModel*> GetPackageFeatureCollection(
            _CbsApplicability appl = CbsApplicabilityNotApplicable,
            _CbsSelectability sele = CbsSelectabilityRootClass);
    };

}
