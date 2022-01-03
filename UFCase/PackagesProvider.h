#pragma once

#include "PackagesProvider.g.h"
#include "CbsProviderManager.h"

namespace winrt::UFCase::implementation
{
    struct PackagesProvider : PackagesProviderT<PackagesProvider>
    {
        using ele_t = UFCase::PackageViewModel;
        using list_t = winrt::IObservableVector<ele_t>;

        winrt::event<winrt::Data::PropertyChangedEventHandler> m_propertyChanged;

        static inline const wchar_t* sessionClient = L"PackagesProvider";
        winrt::com_ptr<ICbsSession> pSess{nullptr};
        UFCase::ImageItem m_img{nullptr};

        PackagesProvider() = default;

        // implement INotifyPropertyChanged
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value);
        void PropertyChanged(winrt::event_token const& token);

        list_t m_pkgs = single_threaded_observable_vector<ele_t>();

        static IAsyncOperation<UFCase::PackagesProvider>
        LoadFromImage(UFCase::ImageItem img);

        list_t Packages();

    };
}

namespace winrt::UFCase::factory_implementation
{
    struct PackagesProvider : PackagesProviderT<PackagesProvider, implementation::PackagesProvider>
    {
    };
}
