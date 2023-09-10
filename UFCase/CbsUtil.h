#pragma once

#include <vector>

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

template <class T, typename IntT = ULONG, class IEnumT>
inline std::vector<winrt::com_ptr<T>> GetIEnumComPtrVector(winrt::com_ptr<IEnumT> pEnum)
{
  std::vector<winrt::com_ptr<T>> v;

  IntT k;

  do {
    winrt::com_ptr<T> ptr;
    pEnum->Next(1, ptr.put(), &k);
    if (ptr) v.push_back(ptr);
  } while (k);

  return v;
}

template <class T, typename IntT = ULONG, class IEnumT>
inline std::vector<T> GetIEnumStructVector(winrt::com_ptr<IEnumT> pEnum)
{
  std::vector<T> v;
  IntT *pk = new IntT;
  T ptr;

  while (true) {
    [[maybe_unused]] HRESULT _hr = pEnum->Next(1, &ptr, pk);
    if (*pk) v.push_back(ptr);
    else break;
  }

  return v;
}


}

