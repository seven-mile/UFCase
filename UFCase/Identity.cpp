#include "pch.h"
#include "Identity.h"
#if __has_include("Identity.g.cpp")
#include "Identity.g.cpp"
#endif

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

    UFCase::Identity Identity::ParsePackageFromTildeForm(hstring const &tilde_form)
    {
        UFCase::Identity res;

        auto tokens = tilde_form | std::views::split('~') | std::views::transform([](auto &&range) {
                          return hstring(std::wstring(range.begin(), range.end()));
                      }) |
                      std::views::common;

        auto it = tokens.begin();

        auto emit = [&]<class T, class R>(R (T::*field)(param::hstring const &) const) {
            if (it != tokens.end())
            {
                (res.*field)(*it++);
            }
            else
            {
                throw std::logic_error("Invalid tilde form");
            }
        };

        emit(&UFCase::Identity::Name);
        emit(&UFCase::Identity::PublicKeyToken);
        emit(&UFCase::Identity::ProcessorArchitecture);
        emit(&UFCase::Identity::Culture);
        emit(&UFCase::Identity::Version);

        if (res.Culture().empty())
        {
            res.Culture(L"neutral");
        }

        return res;
    }

    bool Identity::RoughMatch(UFCase::Identity lhs, UFCase::Identity rhs)
    {
        if (lhs.Name() != rhs.Name())
        {
            return false;
        }

        auto lhs_culture = lhs.Culture();
        if (lhs_culture == L"neutral")
        {
            lhs_culture = L"";
        }
        auto rhs_culture = rhs.Culture();
        if (rhs_culture == L"neutral")
        {
            rhs_culture = L"";
        }

        if (lhs_culture != rhs_culture)
        {
            return false;
        }

        if (lhs.PublicKeyToken() != rhs.PublicKeyToken())
        {
            return false;
        }

        if (lhs.ProcessorArchitecture() != rhs.ProcessorArchitecture())
        {
            return false;
        }

        // exclude revision number from comparison
        FOUR_PART_VERSION lhs_version{lhs.Version().c_str()}, rhs_version{rhs.Version().c_str()};
        if (lhs_version.Major != rhs_version.Major || lhs_version.Minor != rhs_version.Minor ||
            lhs_version.Build != rhs_version.Build)
        {
            return false;
        }

        return true;
    }
} // namespace winrt::UFCase::implementation
