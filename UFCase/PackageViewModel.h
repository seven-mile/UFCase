#pragma once

#include "CbsApi.h"
#include "PackageViewModel.g.h"

#include "PackageModel.h"

namespace winrt::UFCase::implementation
{
    struct PackageViewModel : PackageViewModelT<PackageViewModel>
    {
        PackageModel &m_model;

        PackageViewModel(uint64_t hModel);

        uint64_t Handle();

        hstring Identity();
        hstring ReleaseType();
        hstring State();
        hstring Name();
        hstring Description();
        hstring RestartRequired();
        hstring ProductName();
        hstring ProductVersion();
        hstring Company();
        hstring Copyright();
        hstring SupportInformation();
        hstring CreationTime();
        hstring LastUpdateTime();
        hstring InstallTime();
        hstring InstallPackageName();
        hstring InstallLocation();
        hstring InstallClient();
        hstring InstallUserName();
        bool IsApplicable();
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackageViewModel : PackageViewModelT<PackageViewModel, implementation::PackageViewModel>
    {
    };
}
