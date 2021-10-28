#include "pch.h"

#include <fstream>

namespace winrt::UFCase {
    using Windows::Data::Json::JsonObject;

    JsonObject g_appConfig = JsonObject();
    hstring g_appConfigPath;

    void ReadAppConfigFromFile(hstring const &path) {
        std::ifstream fs{path.c_str()};
        std::istreambuf_iterator<char> beg(fs), end; 
        std::wstring buffer(beg, end);
        g_appConfig = Windows::Data::Json::JsonObject::Parse(buffer);
        fs.close();
    }

    void LoadDefaultAppConfig() {
        g_appConfig = Windows::Data::Json::JsonObject::Parse(LR"(
{
  "stack": {
    "source": 0,
    "argBootdrive": "D:\\MyCache\\Eb"
  },
  "sysInfo": {
    "autoRefresh": true
  }
}
        )");
    }

    void WriteAppConfigToFile(hstring const &path) {
        std::wfstream fs{path.c_str(), std::ios::ate | std::ios::out};
        auto resStr = g_appConfig.ToString();
        fs.write(resStr.c_str(), resStr.size());
        fs.close();
    }
}