#pragma once

#include <winrt/base.h>

#include <winrt/UFCase.h>
#include <winrt/UFCase.Host.Manifest.h>

namespace winrt::UFCase::IdentityUtil
{

    inline bool MatchingField(hstring const &lhs, hstring const &rhs)
    {
        if (lhs == L"*" || rhs == L"*")
        {
            return true;
        }
        return lhs == rhs;
    }

    inline hstring MapIdentityValue(hstring value)
    {
        if (value == L"neutral")
        {
            return L"";
        }
        return value;
    }

    bool RoughMatch(UFCase::Identity lhs, UFCase::Identity rhs);

    UFCase::Identity GetIdentityFromAsmDep(UFCase::Host::Manifest::AssemblyDependency const &dep);

    UFCase::Identity GetIdentityFromComponent(UFCase::ComponentViewModel const &comp);

    // Name~PublicKeyToken~Architecture~Culture~Version
    // Containers-ApplicationGuard-Package~31bf3856ad364e35~amd64~~10.0.22621.2792
    UFCase::Identity GetIdentityFromPkgKeyForm(hstring const &pkg_key_form);

} // namespace winrt::UFCase
