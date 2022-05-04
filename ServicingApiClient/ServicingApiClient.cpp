#include <Windows.h>
#include <combaseapi.h>
#include <winrt/base.h>

#include "CbsApi.h"
#include "CbsApi_i.c"

CLSID CLSID_DynamicCbsSession;

int main()
{
  HRESULT hr{};
  hr = ::CoInitialize(NULL);

  hr = CLSIDFromString(L"{f5a84b3e-2af3-4aaf-87a3-a80a1312285c}", &CLSID_DynamicCbsSession);

  winrt::com_ptr<IClassFactory> factory;
  winrt::com_ptr<ICbsSession> sess;

  //hr = ::CoGetClassObject(CLSID_DynamicCbsSession, CLSCTX_LOCAL_SERVER, NULL, IID_IClassFactory, factory.put_void());

  hr = ::CoCreateInstance(CLSID_DynamicCbsSession, NULL, CLSCTX_LOCAL_SERVER, IID_ICbsSession, sess.put_void());

  ::CoUninitialize();
}
