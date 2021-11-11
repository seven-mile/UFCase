#pragma once

#include "CbsProviderManager.h"

#include "SysInfoStaticProvider.g.h"

namespace winrt::UFCase::implementation
{
    struct SysInfoStaticProvider : SysInfoStaticProviderT<SysInfoStaticProvider>
    {
        SysInfoStaticProvider(UFCase::ImageItem img);

        // machine-specific online info
        static hstring FirmwareType();
        static hstring Manufacturer();
        static hstring CPUArchitecture();
        static hstring CPUDisplayName();

        // image-specific OS info
        hstring OSDisplayName();
        hstring OSVersion();
        hstring OSArchitecture();
        bool IsWinPE();

    private:
        com_ptr<ICbsSession> m_pSess;
        // ref: [Product]-[Feature]-Package~[PublicKeyToken]~[Architecture]~[Language]~[Version]
        hstring m_strProdPkgId;
        UFCase::ImageItem m_img;

        void TryInitCbsSession();
        void TryOpenProductPackage();
    };

}

namespace winrt::UFCase::factory_implementation
{
    struct SysInfoStaticProvider : SysInfoStaticProviderT<SysInfoStaticProvider, implementation::SysInfoStaticProvider>
    {
    };

}
