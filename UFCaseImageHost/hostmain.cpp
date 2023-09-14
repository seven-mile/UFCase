#include "pch.h"

#include <wil/cppwinrt_wrl.h>
#include <winrt/UFCaseImageHost.h>

#include <chrono>

namespace winrt
{
    using namespace Windows::ApplicationModel::Core;
    using namespace Windows::Foundation;
} // namespace winrt

using namespace Microsoft::WRL;
using namespace std::chrono;

void *__stdcall winrt_get_activation_factory(std::wstring_view const &name);

struct Server : winrt::implements<Server, winrt::IGetActivationFactory>
{
    auto GetActivationFactory(winrt::hstring const &classId)
    {
        IInspectable factory(winrt_get_activation_factory(classId), winrt::take_ownership_from_abi);

        if (!factory)
        {
            throw winrt::hresult_class_not_available(classId);
        }

        return factory;
    }
};

CoCreatableClassWrlCreatorMapInclude(Class);

const duration c_debounceTimer = 15s;

// 0x11 = (COM_RIGHTS_EXECUTE | COM_RIGHTS_EXECUTE_LOCAL |
// COM_RIGHTS_ACTIVATE_LOCAL) O:PSG:BU   Owner : principal self, Group : Built -
// in users (A;;0x11;;;WD)  Allow SDDL_EVERYONE (A;;0x11;;;AC)  Allow ALL
// APPLICATION PACKAGES
const wchar_t *const c_ComSecurityDescriptor = L"O:PSG:BUD:(A;;11;;;WD)(A;;11;;;AC)S:(ML;;NX;;;LW)";

HRESULT InitializeComSecurity()
{
    wil::unique_hlocal_security_descriptor securityDescriptor;
    RETURN_LAST_ERROR_IF(!ConvertStringSecurityDescriptorToSecurityDescriptorW(
        c_ComSecurityDescriptor, SDDL_REVISION_1, &securityDescriptor, NULL));

    DWORD headerSize = 0;
    DWORD daclSize = 0;
    DWORD saclSize = 0;
    DWORD ownerSize = 0;
    DWORD groupSize = 0;

    // Convert to an absolute SD to extract pointers to different components; we
    // do this to avoid a dependency on internal APIs.
    MakeAbsoluteSD(securityDescriptor.get(), nullptr, &headerSize, nullptr, &daclSize, nullptr,
                   &saclSize, nullptr, &ownerSize, nullptr, &groupSize);

    DWORD totalSize = headerSize + daclSize + saclSize + ownerSize + groupSize;

    wil::unique_hlocal_security_descriptor absoluteSd(
        reinterpret_cast<SECURITY_DESCRIPTOR *>(LocalAlloc(LMEM_FIXED, totalSize)));
    RETURN_IF_NULL_ALLOC(absoluteSd.get());

    BYTE *position = reinterpret_cast<BYTE *>(absoluteSd.get());
    PACL dacl = reinterpret_cast<PACL>(position += headerSize);
    PACL sacl = reinterpret_cast<PACL>(position += daclSize);
    PSID owner = reinterpret_cast<PSID>(position += saclSize);
    PSID group = reinterpret_cast<PSID>(position += ownerSize);

    RETURN_IF_WIN32_BOOL_FALSE(MakeAbsoluteSD(securityDescriptor.get(), absoluteSd.get(),
                                              &headerSize, dacl, &daclSize, sacl, &saclSize, owner,
                                              &ownerSize, group, &groupSize));

    RETURN_IF_FAILED(CoInitializeSecurity(absoluteSd.get(), -1, nullptr, nullptr,
                                          RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IDENTIFY,
                                          nullptr, EOAC_NONE, nullptr));

    return S_OK;
}

winrt::fire_and_forget ServerDebounceTask() noexcept
try
{
    auto &module = Module<OutOfProc>::GetModule();
    module.IncrementObjectCount();
    co_await winrt::resume_after({c_debounceTimer});
    module.DecrementObjectCount();
}
CATCH_LOG()

int main()
{

    // try
    //{
    //     puts("Server running");
    //     winrt::init_apartment();
    //     CoreApplication::RunWithActivationFactories(winrt::make<Server>());
    //     puts("Server stopped");
    // }
    // catch (winrt::hresult_error const& e)
    //{
    //     printf("Server error: %ls\n", e.message().c_str());
    // }

    winrt::init_apartment();

    winrt::com_ptr<IGlobalOptions> globalOptions;
    THROW_IF_FAILED(CoCreateInstance(CLSID_GlobalOptions, nullptr, CLSCTX_INPROC,
                                     IID_PPV_ARGS(&globalOptions)));
    LOG_IF_FAILED(globalOptions->Set(COMGLB_RO_SETTINGS, COMGLB_FAST_RUNDOWN));

    LOG_IF_FAILED(InitializeComSecurity());

    wil::unique_event shutdownEvent(wil::EventOptions::ManualReset);
    // Create WRL OOP module manager. Callback will be called when
    // all objects have disconnected.
#pragma warning(disable : 4324)
    auto &module = Module<OutOfProc>::Create([&]() { shutdownEvent.SetEvent(); });

    // Run debounce task to ensure the server stays up a minimum amount of time
    ServerDebounceTask();

    // Register all WRL objects with COM. At this point COM will start connecting
    // CoCreateInstance requests.
    winrt::check_hresult(module.RegisterObjects());

    // Wait for module to signal that all objects have disconnected
    shutdownEvent.wait(INFINITE);

    // Unregister all objects from COM and shutdown.
    winrt::check_hresult(module.UnregisterObjects());
}
