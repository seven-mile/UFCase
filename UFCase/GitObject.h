#pragma once

#include "GitUtil.h"

namespace winrt::UFCase
{

    template <typename COMInterface> class GitObject
    {
        DWORD cookie{NULL};

      protected:
        GitObject(com_ptr<COMInterface> origin)
        {
            check_hresult(GetGIT()->RegisterInterfaceInGlobal(origin.get(), __uuidof(COMInterface),
                                                              &this->cookie));
        }

        ~GitObject()
        {
            check_hresult(GetGIT()->RevokeInterfaceFromGlobal(this->cookie));
        }

        com_ptr<COMInterface> GetInterface() const
        {
            com_ptr<COMInterface> proxy;
            check_hresult(GetGIT()->GetInterfaceFromGlobal(this->cookie, __uuidof(COMInterface),
                                                           proxy.put_void()));
            return proxy;
        }

    };

} // namespace winrt::UFCase
