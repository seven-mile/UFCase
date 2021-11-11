#pragma once

#include "../UFCase/SSShimApi.h"
#include <filesystem>

struct SSShimHelper {
    HRESULT GetStack(
        std::filesystem::path const& pathWindir,
        std::wstring const& filename,
        std::filesystem::path& pathStack);

    ~SSShimHelper();

private:
    HRESULT LoadDll();
    HINSTANCE m_dll{ nullptr };
    SssBindServicingStack_t* m_pBindFunc{ nullptr };
    SssGetServicingStackFilePathLength_t* m_pGetLenFunc{ nullptr };
    SssGetServicingStackFilePath_t* m_pGetPathFunc{ nullptr };
    SssReleaseServicingStack_t* m_pReleaseFunc{ nullptr };
    _SSS_COOKIE* m_pCookie{ nullptr };
    std::filesystem::path m_curWindir;
};

