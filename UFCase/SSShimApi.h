#pragma once
#include <Windows.h>
#include <string>

enum class _SSS_GET_FLAGS
{
    Normal = 0
};

struct LUNICODE_STRING
{
    size_t Length;
    size_t MaximumLength;
    wchar_t* Buffer;

    inline operator std::wstring() {
        return { Buffer, Length / sizeof(wchar_t) };
    }
};

// example: 10.0.19041.1022
struct FOUR_PART_VERSION
{
    short revision;
    short build;
    short minor;
    short major;
};

struct _SSS_OFFLINE_IMAGE
{
    UINT cbSize;
    UINT dwFlags;
    BSTR pcwszWindir;
};

// \in 0111 1111 1111 ((1 << 12) - 1)
class _SSS_BIND_CONDITION_FLAGS {
public:
    enum CONTENT_ENUM : UINT {
        VERSION = 1 << 0,
        ARCHITECTURE = 1 << 1,
        OFFLINE_IMAGE = 1 << 2,
        ALTERNATE_LOCATION = 1 << 3,
        TEMPORARY_LOCATION = 1 << 8,
    };
};

enum class _SSS_ARCHITECTURE : short {
    X86 = 0,
    MIPS,
    ALPHA,
    PPC,
    SHX,
    ARM,
    IA64,
    ALPHA64,
    MSIL,
    AMD64,
    WOW64
};

struct _SSS_COOKIE
{
    FOUR_PART_VERSION fpvVersion;
    LUNICODE_STRING location, windir;
    _SSS_ARCHITECTURE arch;
};

struct _SSS_BIND_PARAMETERS
{
    UINT cbSize;
    UINT dwFlags; // use _SSS_BIND_CONDITION_FLAGS
    FOUR_PART_VERSION fpvVersion;
    size_t cntArchs;
    _SSS_ARCHITECTURE* arrArchs;
    _SSS_OFFLINE_IMAGE* pOfflineImage;
    size_t cntAlts;
    void* arrAlts;
    PWSTR pszTempLoc;
};

using SssBindServicingStack_t =
HRESULT(__stdcall)(_In_ _SSS_BIND_PARAMETERS* pInputParams, _Out_ _SSS_COOKIE** ppCookie, int* pDisp);
using SssGetServicingStackFilePathLength_t =
HRESULT(__stdcall)(_In_ int dwFlags, _In_ _SSS_COOKIE* pCookie, _In_ LPCWSTR pszFile, _Out_ UINT64* pLen);
using SssGetServicingStackFilePath_t =
HRESULT(__stdcall)(_In_ int dwFlags, _In_ _SSS_COOKIE* pCookie, _In_ LPCWSTR pszFile, _In_ UINT64 cchBuffer,
    _Out_ LPWSTR bufferPath, _Out_ UINT64* pGotLen);
using SssReleaseServicingStack_t =
HRESULT(__stdcall)(_In_ _SSS_COOKIE* pCookie);
