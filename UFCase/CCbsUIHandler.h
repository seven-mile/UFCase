#pragma once
#include "pch.h"
#include "CbsApi.h"

#include <functional>

namespace winrt::UFCase
{

    struct CCbsUIHandler : public implements<CCbsUIHandler, ICbsUIHandler>
    {
        CCbsUIHandler(std::function<void(uint32_t)> const &progress,
                      std::function<void(hresult)> const &error)
            : OnProgress(progress), OnError(error)
        {
        }

        std::function<void(uint32_t)> OnProgress;
        std::function<void(hresult)> OnError;

        HRESULT STDMETHODCALLTYPE Initiate(IEnumCbsUpdate *, int *) override
        {
            return S_OK;
        }

        HRESULT STDMETHODCALLTYPE Terminate(void) override
        {
            return S_OK;
        }

        HRESULT STDMETHODCALLTYPE Error(HRESULT hr, PCWSTR, int *) override
        {
            OnError(hr);
            return S_OK;
        }

        HRESULT STDMETHODCALLTYPE ResolveSource(PCWSTR, ICbsIdentity *, PCWSTR, PWSTR *,
                                                int *) override
        {
            return S_OK;
        }

        HRESULT STDMETHODCALLTYPE Progress(_CbsInstallState, UINT cur, UINT all, int *) override
        {
            OnProgress(static_cast<uint32_t>(std::round(100.0 * cur / all)));
            return S_OK;
        }

        HRESULT STDMETHODCALLTYPE EnteringStage(UINT, _CbsOperationStage, int, int) override
        {
            return S_OK;
        }

        HRESULT STDMETHODCALLTYPE ProgressEx(_CbsInstallState, UINT, UINT, UINT, int *) override
        {
            return S_OK;
        }
    };

} // namespace winrt::UFCase
