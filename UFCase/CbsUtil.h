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
inline std::vector<winrt::com_ptr<T>> GetIEnumComPtrVector(winrt::com_ptr<IEnumT> pEnum)
{
    std::vector<winrt::com_ptr<T>> v{};
    ULONG k;
    do {
        winrt::com_ptr<T> ptr;
        pEnum->Next(1lu, ptr.put(), &k);
        if (ptr) v.push_back(ptr);
    } while (k);

    return v;
}

winrt::com_ptr<ICbsPackage> FindFoundationPkg(winrt::com_ptr<ICbsSession> pSess)
{
    winrt::com_ptr<ICbsIdentity> pId;
    winrt::check_hresult(pSess->CreateCbsIdentity(pId.put()));

    winrt::check_hresult(pId->LoadFromStringId(L"@Foundation"));

    winrt::com_ptr<ICbsPackage> pPkg;
    winrt::check_hresult(pSess->OpenPackage(0, pId.get(), nullptr, pPkg.put()));

    // unmarshalling
    return pPkg.as<ICbsPackage>();
}

}

