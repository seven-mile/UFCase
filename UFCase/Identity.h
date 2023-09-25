#pragma once

#include "Identity.g.h"

namespace winrt::UFCase::implementation
{
    struct Identity : IdentityT<Identity>
    {
        Identity() = default;

        IdentityType Type()
        {
            return m_type;
        }

        void Type(IdentityType const &value)
        {
            m_type = value;
        }

        hstring Name()
        {
            return m_name;
        }

        void Name(hstring const &value)
        {
            m_name = value;
        }

        hstring Version()
        {
            return m_version;
        }

        void Version(hstring const &value)
        {
            m_version = value;
        }

        hstring PublicKeyToken()
        {
            return m_public_key_token;
        }

        void PublicKeyToken(hstring const &value)
        {
            m_public_key_token = value;
        }

        hstring Culture()
        {
            return m_culture;
        }

        void Culture(hstring const &value)
        {
            m_culture = value;
        }

        hstring ProcessorArchitecture()
        {
            return m_processor_architecture;
        }

        void ProcessorArchitecture(hstring const &value)
        {
            m_processor_architecture = value;
        }

        hstring VersionScope()
        {
            return m_version_scope;
        }

        void VersionScope(hstring const &value)
        {
            m_version_scope = value;
        }

        hstring ImageRoot()
        {
            return m_image;
        }

        void ImageRoot(hstring const &value)
        {
            m_image = value;
        }

        uint64_t GetHashCode()
        {
            // hash a bunch of strings

            std::hash<hstring> hasher;

            uint64_t hash = hasher(m_name);
            hash = (hash << 1) ^ hasher(m_version);
            hash = (hash << 1) ^ hasher(m_public_key_token);
            hash = (hash << 1) ^ hasher(m_culture);
            hash = (hash << 1) ^ hasher(m_processor_architecture);
            hash = (hash << 1) ^ hasher(m_version_scope);
            hash = (hash << 1) ^ hasher(m_image);

            return hash;
        }

        hstring GetDisplayForm();

      private:
        IdentityType m_type;
        hstring m_name;
        hstring m_version;
        hstring m_public_key_token;
        hstring m_culture;
        hstring m_processor_architecture;
        hstring m_version_scope;
        hstring m_image;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct Identity : IdentityT<Identity, implementation::Identity>
    {
    };
} // namespace winrt::UFCase::factory_implementation
