#pragma once

#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Data.Json.h>

namespace winrt::UFCase {
    inline auto g_appConfig = Windows::Data::Json::JsonObject();
    inline hstring g_appConfigPath;

    inline IAsyncAction ReadAppConfigFromFile(hstring const &path = g_appConfigPath) {
        using namespace Windows::Storage;
        using namespace Windows::Data::Json;

        StorageFile cfg_file {nullptr};
        
        if (path.starts_with(L"ms-appx://")) {
            cfg_file = co_await StorageFile::GetFileFromApplicationUriAsync(Uri(path));
        } else {
            cfg_file = co_await StorageFile::GetFileFromPathAsync(path);
        }
        if (!cfg_file || !cfg_file.IsAvailable()) throw_hresult(E_ACCESSDENIED);
        auto content = co_await FileIO::ReadTextAsync(cfg_file);
        
        g_appConfig = JsonObject::Parse(content);
        co_return;
    }

    inline IAsyncAction WriteAppConfigToFile(hstring const &path = g_appConfigPath) {
        using namespace Windows::Storage;
        
        auto cfg_file = co_await StorageFile::GetFileFromPathAsync(path);
        if (static_cast<bool>(cfg_file.Attributes() & FileAttributes::ReadOnly))
            throw_hresult(E_ACCESSDENIED);
        co_await FileIO::WriteTextAsync(cfg_file, g_appConfig.ToString());
        co_return;
    }
}
