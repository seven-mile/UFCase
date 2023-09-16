#pragma once

#include "FeatureModel.g.h"

#include "../UFCase/CbsApi.h"

namespace winrt::UFCase::Isolation::implementation
{
    struct FeatureModel : FeatureModelT<FeatureModel>
    {
        FeatureModel(Isolation::PackageModel pkg, com_ptr<ICbsUpdate> feature)
            : m_feature(feature), m_package(pkg)
        {
        }

        hstring Name();
        CbsInstallState CurrentState();
        CbsInstallState RequestedState();
        hstring DisplayName();
        hstring Description();
        hstring DisplayFile();
        hstring Restart();
        hstring PsfName();
        hstring DownloadSize();
        hstring SetMembership();
        Isolation::PackageModel ContentPackage();
        void Enable();
        void Disable();
        Windows::Foundation::Collections::IVector<Isolation::FeatureModel>
        GetParentFeatureCollection();

      private:
        com_ptr<ICbsUpdate> m_feature;
        Isolation::PackageModel m_package;
        com_ptr<ICbsUpdate> GetInterface()
        {
            return m_feature;
        }
    };
} // namespace winrt::UFCase::Isolation::implementation

// namespace winrt::UFCase::Isolation::factory_implementation
//{
//     struct FeatureModel : FeatureModelT<FeatureModel, implementation::FeatureModel>
//     {
//     };
// } // namespace winrt::UFCase::Isolation::factory_implementation
