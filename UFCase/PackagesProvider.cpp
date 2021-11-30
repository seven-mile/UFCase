#include "pch.h"
#include "PackagesProvider.h"
#if __has_include("PackagesProvider.g.cpp")
#include "PackagesProvider.g.cpp"
#endif

namespace winrt::UFCase::implementation
{
    PackagesProvider::PackagesProvider()
    {
        // default example elements
        m_pkgs.Append(PackageViewModel::LoadFromIdentity(L"PackageProvider", L"Package_for_RollupFix~31bf3856ad364e35~amd64~~22000.348.1.8"));
        m_pkgs.Append(PackageViewModel::LoadFromIdentity(L"PackageProvider", L"Microsoft-Windows-WordPad-FoD-Package~31bf3856ad364e35~amd64~~10.0.22000.1"));
        m_pkgs.Append(PackageViewModel::LoadFromIdentity(L"PackageProvider", L"Microsoft-Windows-FodMetadata-Package~31bf3856ad364e35~amd64~~10.0.22000.1"));
        m_pkgs.Append(PackageViewModel::LoadFromIdentity(L"PackageProvider", L"Microsoft-Windows-Client-LanguagePack-Package~31bf3856ad364e35~amd64~en-US~10.0.22000.318"));
    }
    PackagesProvider::list_t PackagesProvider::Packages()
    {
        return m_pkgs;
    }
}
