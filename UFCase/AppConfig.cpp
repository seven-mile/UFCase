#include "pch.h"
#include "AppConfig.h"

#include <fstream>

#include <winrt/Windows.Storage.h>

namespace winrt::UFCase
{
    using namespace Windows::Data::Json;

    void AppConfig::ReadAppConfigFromFile()
    {
        std::ifstream fs{AppConfig::Current().appConfigPath.c_str()};
        std::istreambuf_iterator<char> beg(fs), end;
        std::wstring buffer(beg, end);
        AppConfig::Current().appConfig = Windows::Data::Json::JsonObject::Parse(buffer);
        fs.close();
    }

    void AppConfig::WriteAppConfigToFile()
    {
        auto resStr = AppConfig::Current().appConfig.ToString();
        // {} etc... empty config
        if (resStr.size() < 3)
            return;
        std::wfstream fs{AppConfig::Current().appConfigPath.c_str(), std::ios::ate | std::ios::out};
        fs.write(resStr.c_str(), resStr.size());
        fs.close();
    }

    void AppConfig::ReadAppConfigFromFile(hstring const &path)
    {
        AppConfig::Current().appConfigPath = path;
        AppConfig::ReadAppConfigFromFile();
    }

    void AppConfig::WriteAppConfigToFile(hstring const &path)
    {
        AppConfig::Current().appConfigPath = path;
        AppConfig::WriteAppConfigToFile();
    }

} // namespace winrt::UFCase
