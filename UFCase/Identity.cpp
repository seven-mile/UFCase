#include "pch.h"
#include "Identity.h"
#if __has_include("Identity.g.cpp")
#include "Identity.g.cpp"
#endif

#include "IdentityUtil.h"

#include <ranges>

namespace winrt::UFCase::implementation
{

    hstring Identity::GetKeyForm()
    {
        std::wstring result;
        result += m_name;

        if (!m_version.empty())
        {
            result += L", Version=" + m_version;
        }

        if (!m_culture.empty())
        {
            result += L", Culture=" + m_culture;
        }

        if (!m_public_key_token.empty())
        {
            result += L", PublicKeyToken=" + m_public_key_token;
        }

        if (!m_processor_architecture.empty())
        {
            result += L", ProcessorArchitecture=" + m_processor_architecture;
        }

        if (!m_version_scope.empty())
        {
            result += L", VersionScope=" + m_version_scope;
        }
        return result.c_str();
    }

    hstring Identity::GetTildeForm()
    {
        std::wstring result;
        result =
            std::format(L"{}~{}~{}~{}~{}", m_name, m_public_key_token, m_processor_architecture,
                        m_culture == L"neutral" ? L"" : m_culture, m_version);
        return result.c_str();
    }

    hstring Identity::GetDisplayForm()
    {
        if (m_type == IdentityType::Component)
        {
            return GetKeyForm();
        }
        else if (m_type == IdentityType::Package)
        {
            return GetTildeForm();
        }
        else
        {
            throw hresult_invalid_argument{};
        }
    }

} // namespace winrt::UFCase::implementation
