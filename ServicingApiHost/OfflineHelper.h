#pragma once

#include <filesystem>

struct OfflineHelper {

    HRESULT Initialize(std::filesystem::path const& pathCore, wil::com_ptr<IClassFactory>& pFactory);
    HRESULT Finalize();

private:

    using CbsCoreInitialize_t = HRESULT(__stdcall)(IMalloc*, UINT64(WINAPI*)(UINT64), void (*)(), void (*)(), void (*)(), void (*)(), void (*)(), IClassFactory**);
    using CbsCoreFinalize_t = HRESULT(__stdcall)();

    CbsCoreInitialize_t* m_pInit;
    CbsCoreFinalize_t* m_pFree;

    HRESULT LoadDll(std::filesystem::path const& pathCore);
    HINSTANCE m_dll = nullptr;
};