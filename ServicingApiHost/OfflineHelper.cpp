#include "pch.h"
#include "OfflineHelper.h"

#include "CbsApi.h"

inline auto GetGlobalMalloc() {
    static IMalloc* pMalloc = nullptr;
    if (!pMalloc)
        THROW_IF_FAILED(CoGetMalloc(1, &pMalloc));
    return pMalloc;
}

HRESULT OfflineHelper::Initialize(std::filesystem::path const& pathCore, wil::com_ptr<IClassFactory>& pFactory)
{
    LoadDll(pathCore);

    static auto Func1 = [](uint64_t) -> uint64_t { return 1ull; };
    static auto Func2 = []() {};

    RETURN_IF_FAILED(m_pInit(GetGlobalMalloc(), Func1, Func2, Func2, Func2, Func2, Func2, pFactory.put()));

    return S_OK;
}

HRESULT OfflineHelper::Finalize()
{
    if (!m_dll || !m_pFree) return S_OK;

    RETURN_IF_FAILED(m_pFree());

    RETURN_IF_WIN32_BOOL_FALSE(FreeLibrary(m_dll));

    return S_OK;
}

HRESULT OfflineHelper::LoadDll(std::filesystem::path const& pathCore)
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
