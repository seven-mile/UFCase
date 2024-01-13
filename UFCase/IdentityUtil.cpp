#include "pch.h"
#include "IdentityUtil.h"

#include <ranges>

namespace winrt::UFCase::IdentityUtil
{

    UFCase::Identity GetIdentityFromAsmDep(UFCase::Host::Manifest::AssemblyDependency const &dep)
    {
        auto dep_asm_ident = dep.Identity();
        UFCase::Identity dep_ident;
        dep_ident.Name(MapIdentityValue(dep_asm_ident.Name()));
        dep_ident.Version(MapIdentityValue(dep_asm_ident.Version()));
        dep_ident.PublicKeyToken(MapIdentityValue(dep_asm_ident.PublicKeyToken()));
        dep_ident.ProcessorArchitecture(MapIdentityValue(dep_asm_ident.ProcessorArchitecture()));
        dep_ident.Culture(MapIdentityValue(dep_asm_ident.Language()));

        return dep_ident;
    }

    UFCase::Identity GetIdentityFromComponent(UFCase::ComponentViewModel const &comp)
    {
        UFCase::Identity comp_ident;
        comp_ident.Name(MapIdentityValue(comp.Name()));
        comp_ident.Version(MapIdentityValue(comp.Version()));
        comp_ident.PublicKeyToken(MapIdentityValue(comp.PublicKeyToken()));
        comp_ident.ProcessorArchitecture(MapIdentityValue(comp.ProcessorArchitecture()));
        comp_ident.Culture(MapIdentityValue(comp.Culture()));

        return comp_ident;
    }

    // Name~PublicKeyToken~Architecture~Culture~Version
    // Containers-ApplicationGuard-Package~31bf3856ad364e35~amd64~~10.0.22621.2792
    UFCase::Identity GetIdentityFromPkgKeyForm(hstring const &pkg_key_form)
    {
        UFCase::Identity res;

        auto tokens = pkg_key_form | std::views::split('~') |
                      std::views::transform([](auto &&range) {
                          return hstring(std::wstring(range.begin(), range.end()));
                      }) |
                      std::views::common;

        auto it = tokens.begin();

        auto emit = [&]<class T, class R>(R (T::*field)(param::hstring const &) const) {
            if (it != tokens.end())
            {
                (res.*field)(MapIdentityValue(*it++));
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

    struct FOUR_PART_VERSION {
        uint16_t Major;
        uint16_t Minor;
        uint16_t Build;
        uint16_t Revision;

        FOUR_PART_VERSION() = default;
        FOUR_PART_VERSION(std::wstring const &version_string)
        {
            std::wstringstream ss(version_string);
            wchar_t ch;
            ss >> Major >> ch >> Minor >> ch >> Build >> ch >> Revision;
        }
    };

    bool RoughMatch(UFCase::Identity lhs, UFCase::Identity rhs)
    {
        if (!MatchingField(lhs.Name(), rhs.Name()))
        {
            return false;
        }

        if (!MatchingField(lhs.Culture(), rhs.Culture()))
        {
            return false;
        }

        if (!MatchingField(lhs.PublicKeyToken(), rhs.PublicKeyToken()))
        {
            return false;
        }

        if (!MatchingField(lhs.ProcessorArchitecture(), rhs.ProcessorArchitecture()))
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

} // namespace winrt::UFCase::IdentityUtil
