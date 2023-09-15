#include "pch.h"
#include "HostGuard.h"

#include <wil/resource.h>
#include <wil/cppwinrt_wrl.h>
#include <sddl.h>

CoCreatableClassWrlCreatorMapInclude(HostManagerSingleton);

// 0x11 = (COM_RIGHTS_EXECUTE | COM_RIGHTS_EXECUTE_LOCAL |
// COM_RIGHTS_ACTIVATE_LOCAL) O:PSG:BU   Owner : principal self, Group : Built -
// in users (A;;0x11;;;WD)  Allow SDDL_EVERYONE (A;;0x11;;;AC)  Allow ALL
// APPLICATION PACKAGES
static const wchar_t *const c_ComSecurityDescriptor =
    L"O:PSG:BUD:(A;;11;;;WD)(A;;11;;;AC)S:(ML;;NX;;;LW)";

static HRESULT InitializeComSecurity()
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

namespace winrt::UFCase
{
    using ModuleType = ::Microsoft::WRL::Module<::Microsoft::WRL::OutOfProc>;

    HostGuard::HostGuard()
    {
        com_ptr<IGlobalOptions> globalOptions;
        THROW_IF_FAILED(CoCreateInstance(CLSID_GlobalOptions, nullptr, CLSCTX_INPROC,
                                         IID_PPV_ARGS(&globalOptions)));
        LOG_IF_FAILED(globalOptions->Set(COMGLB_RO_SETTINGS, COMGLB_FAST_RUNDOWN));

        LOG_IF_FAILED(InitializeComSecurity());

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
