#include "pch.h"
#include "HostManagerSingleton.h"
#if __has_include("HostManagerSingleton.g.cpp")
#include "HostManagerSingleton.g.cpp"
#endif

#include <wil/cppwinrt_wrl.h>

namespace winrt::UFCase::Isolation::implementation
{
    CoCreatableCppWinRtClass(HostManagerSingleton);
} // namespace winrt::UFCase::implementation
