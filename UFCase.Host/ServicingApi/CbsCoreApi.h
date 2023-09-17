
#include <Windows.h>
#include <combaseapi.h>

typedef HRESULT(WINAPI *PCBS_CORE_INITIALIZE_FUNCTION)(
    _In_ IMalloc *pMalloc, _In_ int(WINAPI *LockProc)(int), _In_ void (*UnlockProc)(),
    _In_ void (*InstCreated)(), _In_ void (*InstDestroyed)(), _In_ void (*ReqShutdownNow)(),
    _In_ void (*ReqShutdownProcessing)(), _Out_ IClassFactory **ppClassFactory);

typedef HRESULT(WINAPI *PCBS_CORE_FINALIZE_FUNCTION)();
