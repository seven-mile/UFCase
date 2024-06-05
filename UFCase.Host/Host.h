#pragma once

#include "Host.g.h"

#include "ImageModel.h"

#include <filesystem>

namespace winrt::UFCase::Isolation::implementation
{
    struct Host : HostT<Host>
    {

        Host(guid const &id, std::filesystem::path bootdrive) : m_id(id), m_bootdrive(bootdrive)
        {
        }

        ~Host()
        {
            PostQuitMessage(0);
        }

        guid Id()
        {
            return m_id;
        }

        hstring Bootdrive()
        {
            return m_bootdrive.c_str();
        }

        void Ping()
        {
            wprintf(L"Ping got: OK");
        }

        Isolation::ImageModel Image()
        {
            static Isolation::ImageModel instance = make<implementation::ImageModel>(m_bootdrive);
            return instance;
        }

      private:
        guid m_id;
        std::filesystem::path m_bootdrive;
    };
} // namespace winrt::UFCase::Isolation::implementation
