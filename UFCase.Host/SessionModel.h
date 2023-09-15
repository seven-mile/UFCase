#pragma once

#include "SessionModel.g.h"

#include "../UFCase/CbsApi.h"

namespace winrt::UFCase::Isolation::implementation
{
    struct SessionModel : SessionModelT<SessionModel>
    {
        SessionModel(Isolation::ImageModel image, DWORD option = 0)
            : m_image(image)
        {
            Initialize(option);
        }

        void AddSource(hstring const &source_dir);
        Windows::Foundation::IAsyncActionWithProgress<uint32_t> SaveChanges();

        // 0x1b0 0x130
        Windows::Foundation::Collections::IVector<Isolation::PackageModel> GetPackageCollection(
            DWORD option = 0x1b0);
        Isolation::PackageModel OpenPackage(com_ptr<ICbsIdentity> identity);
        Isolation::PackageModel OpenPackage(hstring const &identity);

        Isolation::PackageModel FoundationPackage();
        Isolation::PackageModel ProductPackage();

        void PerformOperation(CbsOperationType operation);

      private:
        Isolation::ImageModel m_image;
        com_ptr<ICbsSession> m_session{nullptr};

        com_ptr<ICbsSession> GetInterface()
        {
            return m_session;
        }
        void Initialize(DWORD option);
    };
} // namespace winrt::UFCase::Isolation::implementation

// namespace winrt::UFCase::Isolation::factory_implementation
//{
//     struct SessionModel : SessionModelT<SessionModel, implementation::SessionModel>
//     {
//     };
// } // namespace winrt::UFCase::Isolation::factory_implementation
