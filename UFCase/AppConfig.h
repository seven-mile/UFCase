#pragma once

#include <winrt/Windows.Data.Json.h>

#define GetNamedInt GetNamedNumber
#define APPCONFIG_String winrt::hstring
#define APPCONFIG_Number double
#define APPCONFIG_Int int
#define APPCONFIG_Boolean bool

#define APPCONFIG_PARAM_String winrt::param::hstring const &
#define APPCONFIG_PARAM_Number double
#define APPCONFIG_PARAM_Int int
#define APPCONFIG_PARAM_Boolean bool

#define DEFINE_APPCONFIG_ITEM(ITEM_NAME, ITEM_TYPE, SETTING_ID, DEFAULT_VALUE)                     \
    inline static auto Get##ITEM_NAME()->APPCONFIG_##ITEM_TYPE                                     \
    {                                                                                              \
        return static_cast<APPCONFIG_##ITEM_TYPE>(                                                 \
            AppConfig::Current().appConfig.GetNamed##ITEM_TYPE(L##SETTING_ID, DEFAULT_VALUE));     \
    }                                                                                              \
    inline static void Set##ITEM_NAME(APPCONFIG_PARAM_##ITEM_TYPE value)                           \
    {                                                                                              \
        AppConfig::Current().appConfig.SetNamedValue(                                              \
            L##SETTING_ID, Windows::Data::Json::JsonValue::Parse(winrt::to_hstring(value)));       \
    }

namespace winrt::UFCase
{
    struct AppConfig
    {
        static AppConfig &Current()
        {
            static AppConfig *singleton = new AppConfig{};
            return *singleton;
        }

        DEFINE_APPCONFIG_ITEM(StackSource, Int, "stack.source", 0);
        DEFINE_APPCONFIG_ITEM(StackArgBootdrive, String, "stack.argBootdrive", L"");
        DEFINE_APPCONFIG_ITEM(SysinfoAutoRefresh, Boolean, "sysInfo.autoRefresh", true);

        static void ReadAppConfigFromFile();
        static void WriteAppConfigToFile();
        static void ReadAppConfigFromFile(hstring const &path);
        static void WriteAppConfigToFile(hstring const &path);

      private:
        Windows::Data::Json::JsonObject appConfig;
        hstring appConfigPath;
    };

} // namespace winrt::UFCase

#undef GetNamedInt
#undef DEFINE_APPCONFIG_ITEM
#undef APPCONFIG_String
#undef APPCONFIG_Number
#undef APPCONFIG_Int
#undef APPCONFIG_Boolean
#undef APPCONFIG_PARAM_String
#undef APPCONFIG_PARAM_Number
#undef APPCONFIG_PARAM_Int
#undef APPCONFIG_PARAM_Boolean
