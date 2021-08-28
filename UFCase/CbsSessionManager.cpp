#include "pch.h"
#include "CbsSessionManager.h"

#include "MallocUtil.h"

#include <comdef.h>

extern "C" CLSID CLSID_CbsSession;

namespace winrt::UFCase {

    CbsSessionManager& CbsSessionManager::instance()
    {
        if (pInst) return *pInst;
        return *(pInst = new CbsSessionManager());
    }

    winrt::hresult CbsSessionManager::SetCustomLogging(std::filesystem::path const &pathLogFile) const
    {
        if (m_curSrc != static_cast<StackSourceInternal>(StackSource::Offline)) {
            return HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
        } else {
            // offline logging in 
            SetEnvironmentVariable(L"COMPONENT_BASED_SERVICING_LOGFILE", pathLogFile.wstring().c_str());
            return S_OK;
        }
    }

    winrt::hresult CbsSessionManager::BindStack(StackSource src, std::filesystem::path const& pathWindir)
    {
        if (m_curSrc != StackSourceInternal::Unbinded) {
            return E_ILLEGAL_STATE_CHANGE;
        }

        if (src == StackSource::Offline) {

            if (!std::filesystem::exists(pathWindir) ||
                !std::filesystem::is_directory(pathWindir)) {
                return E_INVALIDARG;
            }

            RETURN_IF_FAILED(m_ssshim.GetStack(pathWindir, L"CbsCore.dll", m_pathCore));

            if (!std::filesystem::exists(m_pathCore) ||
                !std::filesystem::is_regular_file(m_pathCore)) {
                return HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND);
            }

            // to init a offline util

        } else if (src == StackSource::Online) {
            // have nothing to do
        } else {
            return E_INVALIDARG;
        }

        m_curSrc = static_cast<StackSourceInternal>(src);
        return S_OK;
    }

    void CbsSessionManager::ReleaseStack()
    {
        if (m_curSrc != StackSourceInternal::Offline) {
            m_curSrc = StackSourceInternal::Unbinded;
            return;
        }
        
        THROW_IF_FAILED(m_offline.Finalize());

        m_curSrc = StackSourceInternal::Unbinded;
        m_pathCore.clear();
    }

    winrt::com_ptr<ICbsSession> CbsSessionManager::ApplyNew()
    {
        if (m_curSrc == StackSourceInternal::Unbinded)
            winrt::throw_hresult(HRESULT_FROM_WIN32(ERROR_INVALID_STATE));
        winrt::com_ptr<ICbsSession> pRes;
        if (m_curSrc == StackSourceInternal::Online) {
            THROW_IF_FAILED(CoCreateInstance(CLSID_CbsSession, nullptr, CLSCTX_SERVER, __uuidof(ICbsSession), pRes.put_void()));
        }
        else if (m_curSrc == StackSourceInternal::Offline) {
            winrt::com_ptr<IClassFactory> pFactory;
            THROW_IF_FAILED(m_offline.Initialize(m_pathCore, pFactory));
            THROW_IF_FAILED(pFactory->CreateInstance(nullptr, __uuidof(ICbsSession), pRes.put_void()));
        }
        return pRes;
    }

    winrt::hresult CbsSessionManager::SSShimHelper::GetStack(
        std::filesystem::path const& pathWindir, std::wstring const& filename, std::filesystem::path& pathStack)
    {
        if (!m_dll) RETURN_IF_FAILED(LoadDll());

        if (pathWindir != m_curWindir) {
            if (m_pCookie) {
                RETURN_IF_FAILED(m_pReleaseFunc(m_pCookie));
            }
            _SSS_OFFLINE_IMAGE image { sizeof _SSS_OFFLINE_IMAGE };
            _SSS_BIND_PARAMETERS param { sizeof _SSS_BIND_PARAMETERS };

            _bstr_t bstrWindir {pathWindir.c_str()};

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
            param.cntArchs = sizeof(arrArchs)/sizeof(arrArchs[0]);
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

    CbsSessionManager::SSShimHelper::~SSShimHelper()
    {
        if (m_pCookie) THROW_IF_FAILED(m_pReleaseFunc(m_pCookie));
        if (m_dll) FreeLibrary(m_dll);
    }

    winrt::hresult CbsSessionManager::SSShimHelper::LoadDll()
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

    winrt::hresult CbsSessionManager::OfflineHelper::Initialize(std::filesystem::path const& pathCore, winrt::com_ptr<IClassFactory> &pFactory)
    {
        LoadDll(pathCore);

        static auto Func1 = [](uint64_t) -> uint64_t { return 1ull; };
        static auto Func2 = [](){};

        RETURN_IF_FAILED(m_pInit(GetGlobalMalloc(), Func1, Func2, Func2, Func2, Func2, Func2, pFactory.put()));
        
        return S_OK;
    }

    winrt::hresult CbsSessionManager::OfflineHelper::Finalize()
    {
        if (!m_dll || !m_pFree) return S_OK;

        RETURN_IF_FAILED(m_pFree());

        RETURN_IF_WIN32_BOOL_FALSE(FreeLibrary(m_dll));

        return S_OK;
    }

    winrt::hresult CbsSessionManager::OfflineHelper::LoadDll(std::filesystem::path const &pathCore)
    {
        if (m_dll) {
            THROW_IF_FAILED(Finalize());
        }

        m_dll = LoadLibrary(pathCore.c_str());

        if (!m_dll) return HRESULT_FROM_WIN32(ERROR_INVALID_LIBRARY);

        m_pInit = reinterpret_cast<decltype(m_pInit)>
            (GetProcAddress(m_dll, "CbsCoreInitialize"));
        m_pFree = reinterpret_cast<decltype(m_pFree)>
            (GetProcAddress(m_dll, "CbsCoreFinalize"));
        
        if (!m_pInit || !m_pFree)
            return HRESULT_FROM_WIN32(ERROR_PROC_NOT_FOUND);

        return S_OK;
    }

}


