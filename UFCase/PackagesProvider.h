#pragma once

#include "PackagesProvider.g.h"

namespace winrt::UFCase::implementation
{
    struct PackagesProvider : PackagesProviderT<PackagesProvider>
    {
        using ele_t = UFCase::PackageViewModel;
        using list_t = winrt::IObservableVector<ele_t>;

        PackagesProvider();

        list_t m_pkgs = single_threaded_observable_vector<ele_t>();
        list_t Packages();

    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackagesProvider : PackagesProviderT<PackagesProvider, implementation::PackagesProvider>
    {
    };
}
