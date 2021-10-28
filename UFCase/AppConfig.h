#pragma once

#include <winrt/Windows.Data.Json.h>

namespace winrt::UFCase {
    extern Windows::Data::Json::JsonObject g_appConfig;
    extern hstring g_appConfigPath;

    void ReadAppConfigFromFile(hstring const &path = g_appConfigPath);
    void LoadDefaultAppConfig();
    void WriteAppConfigToFile(hstring const &path = g_appConfigPath);
}
