#include "pch.h"
#include "SSShimHelper.h"

#include <comdef.h>

HRESULT SSShimHelper::GetStack(
    std::filesystem::path const& pathWindir, std::wstring const& filename, std::filesystem::path& pathStack)
{
    if (!m_dll) RETURN_IF_FAILED(LoadDll());

    if (pathWindir != m_curWindir) {
        if (m_pCookie) {
            RETURN_IF_FAILED(m_pReleaseFunc(m_pCookie));
        }
        _SSS_OFFLINE_IMAGE image{ sizeof _SSS_OFFLINE_IMAGE };
        _SSS_BIND_PARAMETERS param{ sizeof _SSS_BIND_PARAMETERS };

        _bstr_t bstrWindir{ pathWindir.c_str() };

        image.pcwszWindir = bstrWindir;
        int disposition;
        param.pOfflineImage = &image;

        static _SSS_ARCHITECTURE arrArchs[] = {
        #ifdef _AMD64_
            _SSS_ARCHITECTURE::AMD64,
            _SSS_ARCHITECTURE::X86,
        #else
            _SSS_ARCHITECTURE::X86,
            _SSS_ARCHITECTURE::AMD64,
        #endif
        };
        param.cntArchs = sizeof(arrArchs) / sizeof(arrArchs[0]);
        param.arrArchs = arrArchs;

        RETURN_IF_FAILED(m_pBindFunc(&param, &m_pCookie, &disposition));
        m_curWindir = pathWindir;
    }
    size_t len = 0;
    RETURN_IF_FAILED(m_pGetLenFunc(0, m_pCookie, filename.c_str(), &len));
    std::wstring buffer;
    buffer.assign(len + 1, L'\0');
    RETURN_IF_FAILED(m_pGetPathFunc(0, m_pCookie, filename.c_str(), len, buffer.data(), &len));
    pathStack = buffer.c_str();

    return S_OK;
}

SSShimHelper::~SSShimHelper()
{
    if (m_pCookie) THROW_IF_FAILED(m_pReleaseFunc(m_pCookie));
    if (m_dll) FreeLibrary(m_dll);
}

HRESULT SSShimHelper::LoadDll()
{
    m_dll = LoadLibrary(L"SSShim.dll");
    if (!m_dll) return HRESULT_FROM_WIN32(ERROR_INVALID_LIBRARY);

    m_pBindFunc = reinterpret_cast<decltype(m_pBindFunc)>
        (GetProcAddress(m_dll, "SssBindServicingStack"));
    m_pGetLenFunc = reinterpret_cast<decltype(m_pGetLenFunc)>
        (GetProcAddress(m_dll, "SssGetServicingStackFilePathLength"));
    m_pGetPathFunc = reinterpret_cast<decltype(m_pGetPathFunc)>
        (GetProcAddress(m_dll, "SssGetServicingStackFilePath"));
    m_pReleaseFunc = reinterpret_cast<decltype(m_pReleaseFunc)>
        (GetProcAddress(m_dll, "SssReleaseServicingStack"));

    if (!m_pBindFunc || !m_pGetLenFunc || !m_pGetPathFunc || !m_pReleaseFunc)
        return HRESULT_FROM_WIN32(ERROR_PROC_NOT_FOUND);

    return S_OK;
}
