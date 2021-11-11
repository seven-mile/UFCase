#include "pch.h"
#pragma comment(lib, "Ole32.lib")

#include "OfflineHelper.h"
#include "SSShimHelper.h"

#include <sddl.h>
#pragma comment(lib, "Advapi32.lib")

BOOL GetAccessPermissionsForLUAServer(SECURITY_DESCRIPTOR** ppSD)
{
    // Local call permissions to IU, SY
    LPCWSTR lpszSDDL = L"O:BAG:BAD:(A;;0x3;;;IU)(A;;0x3;;;SY)";
    SECURITY_DESCRIPTOR* pSD;
    *ppSD = NULL;

    if (ConvertStringSecurityDescriptorToSecurityDescriptorW(lpszSDDL, SDDL_REVISION_1, (PSECURITY_DESCRIPTOR*)&pSD, NULL))
    {
        *ppSD = pSD;
        return TRUE;
    }

    return FALSE;
}

HRESULT InitializeSecurity(SECURITY_DESCRIPTOR *pSD) {
    HRESULT hr;
    // Absolute SD values
    PSECURITY_DESCRIPTOR pAbsSD = NULL;
    DWORD AbsSdSize = 0;
    PACL  pAbsAcl = NULL;
    DWORD AbsAclSize = 0;
    PACL  pAbsSacl = NULL;
    DWORD AbsSaclSize = 0;
    PSID  pAbsOwner = NULL;
    DWORD AbsOwnerSize = 0;
    PSID  pAbsGroup = NULL;
    DWORD AbsGroupSize = 0;

    MakeAbsoluteSD(
        pSD,
        pAbsSD,
        &AbsSdSize,
        pAbsAcl,
        &AbsAclSize,
        pAbsSacl,
        &AbsSaclSize,
        pAbsOwner,
        &AbsOwnerSize,
        pAbsGroup,
        &AbsGroupSize
    );

    if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
    {
        pAbsSD = (PSECURITY_DESCRIPTOR)LocalAlloc(LMEM_FIXED, AbsSdSize);
        pAbsAcl = (PACL)LocalAlloc(LMEM_FIXED, AbsAclSize);
        pAbsSacl = (PACL)LocalAlloc(LMEM_FIXED, AbsSaclSize);
        pAbsOwner = (PSID)LocalAlloc(LMEM_FIXED, AbsOwnerSize);
        pAbsGroup = (PSID)LocalAlloc(LMEM_FIXED, AbsGroupSize);

        if (!(pAbsSD && pAbsAcl && pAbsSacl && pAbsOwner && pAbsGroup))
        {
            hr = E_OUTOFMEMORY;
            goto Cleanup;
        }
        if (!MakeAbsoluteSD(
            pSD,
            pAbsSD,
            &AbsSdSize,
            pAbsAcl,
            &AbsAclSize,
            pAbsSacl,
            &AbsSaclSize,
            pAbsOwner,
            &AbsOwnerSize,
            pAbsGroup,
            &AbsGroupSize
        ))
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            goto Cleanup;
        }
    }
    else
    {
        hr = HRESULT_FROM_WIN32(GetLastError());
        goto Cleanup;
    }

    // Call CoinitilizeSecurity.
    hr = CoInitializeSecurity(pSD, -1, nullptr, nullptr,
        RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr,
        EOAC_ACCESS_CONTROL | EOAC_ANY_AUTHORITY, nullptr);

Cleanup:
    LocalFree(pAbsAcl);
    LocalFree(pAbsGroup);
    LocalFree(pAbsOwner);
    LocalFree(pAbsSacl);
    LocalFree(pAbsSD);

    return hr;
}

int WINAPI wWinMain(
    _In_ HINSTANCE,
    _In_opt_ HINSTANCE,
    _In_ LPWSTR lpCmdLine,
    _In_ int
)
{
    {
        SECURITY_DESCRIPTOR *pSD;
        wil::verify_BOOL(GetAccessPermissionsForLUAServer(&pSD));
        wil::verify_hresult(InitializeSecurity(pSD));
        wil::verify_BOOL(HeapFree(GetProcessHeap(), 0, pSD));
    }

    std::wstring cmd = lpCmdLine;
    const int GUID_LEN = 38;
    std::filesystem::path pathBootdrv{cmd.substr(GUID_LEN + 1)}, pathCore;

    SSShimHelper m_ssshim;
    wil::verify_hresult(m_ssshim.GetStack(pathBootdrv / L"Windows", L"CbsCore.dll", pathCore));
    
    GUID CLSID_HOST;
    wil::verify_hresult(CLSIDFromString(cmd.substr(0, GUID_LEN).c_str(), &CLSID_HOST));
    // load core from pathCore
    wil::com_ptr<IClassFactory> pFac{};
    OfflineHelper m_offline;
    wil::verify_hresult(m_offline.Initialize(pathCore, pFac));

    // register
    DWORD dwReg{};
    wil::verify_hresult(CoRegisterClassObject(CLSID_HOST, pFac.get(), CLSCTX_LOCAL_SERVER, REGCLS_SINGLEUSE, &dwReg));
    
    // block
    while (true) {
        Sleep(100);
    }

    return 0;
}
