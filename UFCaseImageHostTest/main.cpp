#include "pch.h"

#include <guiddef.h>
#include <combaseapi.h>

#include <winrt/UFCaseImageHost.h>

using namespace winrt;
using namespace Windows::Foundation;


// {BFB04A77-8632-4EE0-8E67-93A4712BE42F}
static const GUID CLSID_UFCaseClass = 
{ 0xbfb04a77, 0x8632, 0x4ee0, { 0x8e, 0x67, 0x93, 0xa4, 0x71, 0x2b, 0xe4, 0x2f } };

int main()
{
    init_apartment();

    auto cl =
        winrt::create_instance<UFCaseImageHost::Class>(CLSID_UFCaseClass, CLSCTX_LOCAL_SERVER);

    auto x = cl.MyProperty();
    wprintf(L"got from server: %x\n", x);

    wprintf(L"please input number:\n");
    while (true) {
      int input;
      wscanf(L"%d", &input);


      cl.MyProperty(input);

    }

    return 0;
}
