#pragma once

#include "ImageModel.g.h"

#include "../UFCase/CbsApi.h"

#include <filesystem>

namespace winrt::UFCase::Isolation::implementation
{
    struct ImageModel : ImageModelT<ImageModel>
    {
        ImageModel(std::filesystem::path bootdrive) : m_bootdrive(bootdrive)
        {
            Initialize();
        }

        Isolation::SessionModel OpenSession(DWORD option = CbsSessionOptionNone);

        Isolation::SessionModel BasicSession();
        Isolation::StoreModel SxsStore();

        hstring Bootdrive();
        hstring WinDir();

        ImageType Type();
        ImageVersion Version();
        hstring Edition();
        hstring Architecture();
        bool IsWinPE();

      private:
        std::filesystem::path m_bootdrive;
        Isolation::SessionModel basic_sess{nullptr};
        Isolation::StoreModel sxs_store{nullptr};

        void Initialize();
    };
} // namespace winrt::UFCase::Isolation::implementation

// namespace winrt::UFCase::Isolation::factory_implementation
//{
//    struct ImageModel : ImageModelT<ImageModel, implementation::ImageModel>
//    {
//    };
//}
