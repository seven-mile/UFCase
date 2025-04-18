#pragma once

#include "PackageModel.g.h"

#include "CbsApi.h"

namespace winrt::UFCase::Isolation::implementation
{
    struct PackageModel : PackageModelT<PackageModel>
    {
        PackageModel(Isolation::SessionModel session, com_ptr<ICbsPackage> package)
            : m_session(session), m_package(package)
        {
        }

        Isolation::SessionModel Session();

        hstring Identity();
        hstring ReleaseType();
        CbsInstallState State();
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

        hstring ManifestFilePath();
        hstring RegistryPath();

        void Install();
        void Remove();
        void Stage();
        Isolation::FeatureModel OpenFeature(hstring const &name);
        Windows::Foundation::Collections::IVector<Isolation::FeatureModel> GetFeatureCollection(
            DWORD appl, DWORD sele);

      private:
        Isolation::SessionModel m_session;
        com_ptr<ICbsPackage> m_package;

        com_ptr<ICbsPackage> GetInterface()
        {
            return m_package;
        }
    };
} // namespace winrt::UFCase::Isolation::implementation

// namespace winrt::UFCase::Isolation::factory_implementation
//{
//     struct PackageModel : PackageModelT<PackageModel, implementation::PackageModel>
//     {
//     };
// } // namespace winrt::UFCase::Isolation::factory_implementation
