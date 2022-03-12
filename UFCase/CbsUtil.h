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

}

