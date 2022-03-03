#pragma once
#include "Model.h"
#include "FeatureModel.h"

#include "CbsApi.h"

namespace winrt::UFCase {


class PackageModel : public Model<PackageModel>
{
    com_ptr<ICbsPackage> package;

    PackageModel(com_ptr<ICbsPackage> package) : package(package) { }
    PackageModel(hstring const& sessionClient, hstring const& identity);
public:
    static PackageModel* Create(hstring const& sessionClient, hstring const& identity);
    static PackageModel* Create(com_ptr<ICbsPackage> package);
    
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
    FeatureModel* OpenFeature(hstring const &UpdateName);
    std::vector<FeatureModel*> GetPackageFeatureCollection();
};

}
