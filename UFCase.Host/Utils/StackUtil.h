
#include "ServicingApi/SSShimApi.h"

#include "Utils/PathUtil.h"

namespace winrt::UFCase::Isolation::implementation
{
    constexpr auto WCP_DLL_FILENAME = L"wcp.dll";
    constexpr auto SSSHIM_DLL_FILENAME = L"SSShim.dll";

    template <class FuncT>
        requires requires { requires std::is_function_v<std::remove_pointer_t<FuncT>>; }
    [[nodiscard]] inline FuncT GetFunction(const std::wstring module, const std::string name)
    {
        return reinterpret_cast<FuncT>(
            GetProcAddress(winrt::check_pointer(GetModuleHandle(module.c_str())), name.c_str()));
    }

    inline std::wstring_view GetViewFromLUC(LUNICODE_STRING const &luc)
    {
        return {luc.Data, static_cast<size_t>(luc.Length)};
    }

    inline std::filesystem::path FindSStackDll(hstring windir, hstring dll)
    {
        winrt::check_pointer(LoadLibrary(SSSHIM_DLL_FILENAME));

        auto pfnSssBindServicingStack = GetFunction<PSSS_BIND_SERVICING_STACK_FUNCTION>(
            SSSHIM_DLL_FILENAME, "SssBindServicingStack");

        auto pfnSssGetServicingStackFilePathLength =
            GetFunction<PSSS_GET_SERVICING_STACK_FILE_PATH_LENGTH_FUNCTION>(
                SSSHIM_DLL_FILENAME, "SssGetServicingStackFilePathLength");

        auto pfnSssGetServicingStackFilePath =
            GetFunction<PSSS_GET_SERVICING_STACK_FILE_PATH_FUNCTION>(
                SSSHIM_DLL_FILENAME, "SssGetServicingStackFilePath");

        SSS_BIND_PARAMETERS param{.cbSize = sizeof(param),
                                  .dwFlags = SSS_BIND_CONDITION_FLAGS_ARCHITECTURE |
                                             SSS_BIND_CONDITION_FLAGS_OFFLINE_IMAGE};
        DWORD arrArchs[] = {
#ifdef _M_AMD64
            PROCESSOR_ARCHITECTURE_AMD64,
#elif _WIN32
            PROCESSOR_ARCHITECTURE_INTEL,
#elif _M_ARM64
            PROCESSOR_ARCHITECTURE_ARM64,
#elif _M_ARM
            PROCESSOR_ARCHITECTURE_ARM,
#endif
        };
        param.cntArchs = _countof(arrArchs);
        param.arrArchs = arrArchs;

        // Still using online servicing stack
        auto strOnlineRoot = wil::GetEnvironmentVariableW(L"SystemRoot");

        SSS_OFFLINE_IMAGE offlineImage = {
            .cbSize = sizeof(*param.pOfflineImage),
            .dwFlags = 0,
            .pcwszWindir = windir.c_str(),
        };

        param.pOfflineImage = &offlineImage;

        wil::unique_process_heap_ptr<SSS_COOKIE> pCookie;

        DWORD dwDisposition;
        THROW_IF_FAILED(pfnSssBindServicingStack(&param, wil::out_param(pCookie), &dwDisposition));

        std::wstring_view strvLocation{GetViewFromLUC(pCookie->ucLocation)};

        UINT64 lenPath = 0;
        winrt::check_hresult(
            pfnSssGetServicingStackFilePathLength(0, pCookie.get(), dll.c_str(), &lenPath));
        assert(lenPath > 0);
        auto bufPath = std::make_unique<wchar_t[]>(static_cast<size_t>(lenPath));
        UINT64 gotLen = 0;
        winrt::check_hresult(pfnSssGetServicingStackFilePath(0, pCookie.get(), dll.c_str(),
                                                             lenPath * 2, bufPath.get(), &gotLen));

        std::filesystem::path result = bufPath.get();

        if (!std::filesystem::exists(result))
        {
            throw winrt::hresult_error{HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)};
        }

        return result;
    }
} // namespace winrt::UFCase::Isolation::implementation
