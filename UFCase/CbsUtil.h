#pragma once

namespace winrt::UFCase {

inline hstring ParseCbsTimeStampString(const wchar_t* ts_str) {
    auto timeStamp = std::wcstoull(ts_str, nullptr, 10);
    LARGE_INTEGER liTmp;
    liTmp.QuadPart = timeStamp;
    FILETIME fileTimeTmp, fileLocalTimeTmp;
    fileTimeTmp.dwLowDateTime = liTmp.LowPart;
    fileTimeTmp.dwHighDateTime = liTmp.HighPart;

    // Optional
    FileTimeToLocalFileTime(&fileTimeTmp, &fileLocalTimeTmp);

    SYSTEMTIME sysTimeTmp;
    FileTimeToSystemTime(&fileLocalTimeTmp, &sysTimeTmp);

    return std::format(L"{}/{:02}/{:02} {}:{:02}:{:02}",
        sysTimeTmp.wYear,
        sysTimeTmp.wMonth,
        sysTimeTmp.wDay,
        sysTimeTmp.wHour,
        sysTimeTmp.wMinute,
        sysTimeTmp.wSecond).c_str();
}

template<class T, class IEnumT>
inline std::vector<com_ptr<T>> GetIEnumComPtrVector(com_ptr<IEnumT> pEnum)
{
    std::vector<com_ptr<T>> v{};
    ULONG k;
    do {
        com_ptr<T> ptr;
        pEnum->Next(1lu, ptr.put(), &k);
        if (ptr) v.push_back(ptr);
    } while (k);

    return v;
}

inline com_ptr<ICbsPackage> FindFoundationPkg(com_ptr<ICbsSession> pSess)
{
    com_ptr<ICbsIdentity> pId;
    check_hresult(pSess->CreateCbsIdentity(pId.put()));

    check_hresult(pId->LoadFromStringId(L"@Foundation"));

    com_ptr<ICbsPackage> pPkg;
    check_hresult(pSess->OpenPackage(0, pId.get(), nullptr, pPkg.put()));

    // unmarshalling
    return pPkg.as<ICbsPackage>();
}

inline hstring GetCbsInstallStateString(_CbsInstallState state) {
    switch (state) {
        case CbsInstallStatePartiallyInstalled: return L"CbsInstallStatePartiallyInstalled";
        case CbsInstallStateCancel: return L"CbsInstallStateCancel";
        case CbsInstallStateSuperseded: return L"CbsInstallStateSuperseded";
        case CbsInstallStateDefault: return L"CbsInstallStateDefault";
        case CbsInvalidStatePermanent: return L"CbsInvalidStatePermanent";
        case CbsInvalidStateInstalled: return L"CbsInvalidStateInstalled";
        case CbsInvalidStateStaged: return L"CbsInvalidStateStaged";
        case CbsInvalidStateResolved: return L"CbsInvalidStateResolved";
        case CbsInstallStateUnknown: return L"CbsInstallStateUnknown";
        case CbsInstallStateAbsent: return L"CbsInstallStateAbsent";
        case CbsInstallStateResolving: return L"CbsInstallStateResolving";
        case CbsInstallStateResolved: return L"CbsInstallStateResolved";
        case CbsInstallStateStaging: return L"CbsInstallStateStaging";
        case CbsInstallStateStaged: return L"CbsInstallStateStaged";
        case CbsInstallStateUninstallRequested: return L"CbsInstallStateUninstallRequested";
        case CbsInstallStateInstallRequested: return L"CbsInstallStateInstallRequested";
        case CbsInstallStateInstalled: return L"CbsInstallStateInstalled";
        case CbsInstallStatePermanent: return L"CbsInstallStatePermanent";
        default: return L"CbsInstallStateInvalid";
    }
}

}

