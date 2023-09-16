#pragma once

#include <Windows.h>

#include <wtypes.h>

#include "wcpdef.h"

// example: 10.0.19041.1022
typedef struct _FOUR_PART_VERSION
{
    USHORT revision;
    USHORT build;
    USHORT minor;
    USHORT major;
} FOUR_PART_VERSION;

typedef struct _SSS_OFFLINE_IMAGE
{
    UINT cbSize;
    UINT dwFlags;
    LPCWSTR pcwszWindir;
} SSS_OFFLINE_IMAGE;

// \in 0111 1111 1111 ((1 << 12) - 1)
typedef enum _SSS_BIND_CONDITION_FLAGS
{
    SSS_BIND_CONDITION_FLAGS_VERSION = 1 << 0,
    SSS_BIND_CONDITION_FLAGS_ARCHITECTURE = 1 << 1,
    SSS_BIND_CONDITION_FLAGS_OFFLINE_IMAGE = 1 << 2,
    SSS_BIND_CONDITION_FLAGS_ALTERNATE_LOCATION = 1 << 3,
    SSS_BIND_CONDITION_FLAGS_TEMPORARY_LOCATION = 1 << 8,
} SSS_BIND_CONDITION_FLAGS;

typedef struct _SSS_COOKIE
{
    FOUR_PART_VERSION fpvVersion;
    LUNICODE_STRING ucLocation, ucWindir;
    DWORD ulProcessorArchitecture;
} SSS_COOKIE;

typedef struct _SSS_BIND_PARAMETERS
{
    UINT cbSize;
    DWORD dwFlags; // use SSS_BIND_CONDITION_FLAGS
    FOUR_PART_VERSION fpvVersion;
    UINT64 cntArchs;
    DWORD *arrArchs;
    _SSS_OFFLINE_IMAGE *pOfflineImage;
    UINT64 cntAlts;
    void *arrAlts;
    LPWSTR pszTemporaryLocation;
} SSS_BIND_PARAMETERS;

typedef enum _SSS_GET_SERVICING_STACK_FILE_PATH_FLAGS
{
    SSS_GET_SERVICING_STACK_FILE_PATH_NONE = 0,

} SSS_GET_SERVICING_STACK_FILE_PATH_FLAGS;

typedef HRESULT(__stdcall *PSSS_BIND_SERVICING_STACK_FUNCTION)(
    _In_ SSS_BIND_PARAMETERS *pInputParams, _Out_ SSS_COOKIE **ppCookie,
    _Out_ DWORD *dwDisposition);

typedef HRESULT(__stdcall *PSSS_GET_SERVICING_STACK_FILE_PATH_LENGTH_FUNCTION)(
    _In_ int dwFlags, _In_ SSS_COOKIE *pCookie, _In_ LPCWSTR pszFile,
    // pLen is the count of wchar_t in pszFile, including terminating null
    _Out_ UINT64 *pLen);

typedef HRESULT(__stdcall *PSSS_GET_SERVICING_STACK_FILE_PATH_FUNCTION)(
    _In_ int dwFlags, _In_ SSS_COOKIE *pCookie, _In_ LPCWSTR pszFile, _In_ UINT64 cchBuffer,
    _Out_ LPWSTR bufferPath, _Out_ UINT64 *pGotLen);
