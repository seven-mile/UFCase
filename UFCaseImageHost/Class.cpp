#include "pch.h"
#include "Class.h"
#include "Class.g.cpp"

namespace winrt::UFCaseImageHost::implementation
{
    int32_t Class::MyProperty()
    {
        return 42;
    }

    void Class::MyProperty(int32_t  value )
    {
        wprintf(L"value: %d\n", value);
    }

    CoCreatableCppWinRtClass(Class);
}
