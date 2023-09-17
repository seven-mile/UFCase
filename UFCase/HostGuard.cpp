#include "pch.h"
#include "HostGuard.h"

#include <wil/resource.h>
#include <wil/cppwinrt_wrl.h>
#include <sddl.h>

CoCreatableClassWrlCreatorMapInclude(HostManagerSingleton);

namespace winrt::UFCase
{
    using ModuleType = ::Microsoft::WRL::Module<::Microsoft::WRL::OutOfProc>;

    HostGuard::HostGuard()
    {
        com_ptr<IGlobalOptions> globalOptions;
        THROW_IF_FAILED(CoCreateInstance(CLSID_GlobalOptions, nullptr, CLSCTX_INPROC,
                                         IID_PPV_ARGS(&globalOptions)));
        LOG_IF_FAILED(globalOptions->Set(COMGLB_RO_SETTINGS, COMGLB_FAST_RUNDOWN));

        wil::unique_event shutdownEvent(wil::EventOptions::ManualReset);
        // Create WRL OOP module manager. Callback will be called when
        // all objects have disconnected.
#pragma warning(disable : 4324)
        auto &module = ModuleType::Create();

        // Register all WRL objects with COM. At this point COM will start connecting
        // CoCreateInstance requests.
        check_hresult(module.RegisterObjects());
    }

    HostGuard::~HostGuard()
    {
        check_hresult(ModuleType::GetModule().UnregisterObjects());
    }

} // namespace winrt::UFCase
