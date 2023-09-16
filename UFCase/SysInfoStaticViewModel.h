#pragma once

#include "SysInfoStaticViewModel.g.h"

#include <winrt/UFCase.Isolation.h>

namespace winrt::UFCase::implementation
{
    struct SysInfoStaticViewModel : SysInfoStaticViewModelT<SysInfoStaticViewModel>
    {
        SysInfoStaticViewModel(Isolation::ImageModel model);

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
        Isolation::ImageModel m_model;
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct SysInfoStaticViewModel
        : SysInfoStaticViewModelT<SysInfoStaticViewModel, implementation::SysInfoStaticViewModel>
    {
    };

} // namespace winrt::UFCase::factory_implementation
