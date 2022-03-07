#pragma once

#include "CbsProviderManager.h"

#include "SysInfoStaticViewModel.g.h"

#include "ImageModel.h"

namespace winrt::UFCase::implementation
{
    struct SysInfoStaticViewModel : SysInfoStaticViewModelT<SysInfoStaticViewModel>
    {
        SysInfoStaticViewModel(uint64_t hImgModel);

        // machine-specific online info
        static hstring FirmwareType();
        static hstring Manufacturer();
        static hstring CPUArchitecture();
        static hstring CPUDisplayName();

        // image-specific OS info
        hstring OSVersion();
        hstring OSArchitecture();
        hstring IsWinPE();

    private:
        ImageModel &m_model;
    };

}

namespace winrt::UFCase::factory_implementation
{
    struct SysInfoStaticViewModel : SysInfoStaticViewModelT<SysInfoStaticViewModel, implementation::SysInfoStaticViewModel>
    {
    };

}
