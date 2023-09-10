#pragma once

namespace winrt::UFCase
{

    class HardwareInfoModel
    {
      public:
        static hstring GetFirmwareType();
        static hstring GetManufacturer();
        static hstring GetCPUArchitecture();
        static hstring GetCPUDisplayName();
    };

} // namespace winrt::UFCase
