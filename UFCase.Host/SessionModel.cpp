#include "pch.h"
#include "SessionModel.h"
#if __has_include("SessionModel.g.cpp")
#include "SessionModel.g.cpp"
#endif

#include "CCbsUIHandler.h"

#include "Utils/ComUtil.h"
#include "Utils/MallocUtil.h"
#include "Utils/StackUtil.h"
#include "ServicingApi/CbsCoreApi.h"

#include "PackageModel.h"

static const CLSID CLSID_CbsSession = {
    0x752073A1, 0x23F2, 0x4396, {0x85, 0xF0, 0x8F, 0xDB, 0x87, 0x9E, 0xD0, 0xED}};

namespace winrt::UFCase::Isolation::implementation
{
    constexpr auto CBSCORE_DLL_FILENAME = L"CbsCore.dll";

    CbsCoreGuard::CbsCoreGuard(winrt::com_ptr<IMalloc> pMalloc, hstring windir)
    {
        check_pointer(LoadLibrary(FindSStackDll(windir, CBSCORE_DLL_FILENAME).c_str()));

        auto pfnCbsCoreInitialize =
            GetFunction<PCBS_CORE_INITIALIZE_FUNCTION>(CBSCORE_DLL_FILENAME, "CbsCoreInitialize");

        auto nf1 = [](int) { return 0; };
        auto nf2 = [] {};
        check_hresult(
            pfnCbsCoreInitialize(pMalloc.get(), nf1, nf2, nf2, nf2, nf2, nf2, m_factory.put()));
    }

    CbsCoreGuard::~CbsCoreGuard()
    {
        if (m_factory)
        {
            m_factory = nullptr;
        }

        auto pfnCbsCoreFinalize =
            GetFunction<PCBS_CORE_FINALIZE_FUNCTION>(CBSCORE_DLL_FILENAME, "CbsCoreFinalize");
        check_hresult(pfnCbsCoreFinalize());

        FreeLibrary(check_pointer(GetModuleHandle(CBSCORE_DLL_FILENAME)));
    }

    std::shared_ptr<CbsCoreGuard> CbsCoreGuard::GetStrong(hstring windir)
    {
        static std::weak_ptr<CbsCoreGuard> weak;

        if (auto strong = weak.lock(); strong)
            return strong;

        // no available, renew
        com_ptr<IMalloc> pMalloc;
        check_hresult(::CoGetMalloc(1, pMalloc.put()));
        auto strong = std::make_shared<CbsCoreGuard>(pMalloc, windir);
        weak = strong;
        return strong;
    }

    void SessionModel::Initialize(DWORD option_)
    {
        auto option = static_cast<::_CbsSessionOption>(option_);

        if (m_image.Type() == ImageType::Online)
        {
            m_session = create_instance<ICbsSession>(CLSID_CbsSession, CLSCTX_LOCAL_SERVER);
            check_hresult(m_session->Initialize(option, L"UFCase", nullptr, nullptr));
        }
        else
        {
            m_core = CbsCoreGuard::GetStrong(m_image.WinDir());
            check_hresult(
                m_core->m_factory->CreateInstance(nullptr, IID_ICbsSession, m_session.put_void()));

            check_hresult(m_session->Initialize(option, L"UFCase", m_image.Bootdrive().c_str(),
                                                m_image.WinDir().c_str()));
        }

        THROW_IF_FAILED(CoSetProxyBlanket(m_session.get(), RPC_C_AUTHN_DEFAULT, RPC_C_AUTHZ_NONE,
                                          nullptr, RPC_C_AUTHN_LEVEL_CALL,
                                          RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE));
    }

    Isolation::PackageModel SessionModel::OpenPackage(com_ptr<ICbsIdentity> identity)
    {
        com_ptr<ICbsPackage> package;
        check_hresult(GetInterface()->OpenPackage(0, identity.get(), nullptr, package.put()));
        package = package.as<ICbsPackage>();
        return make<implementation::PackageModel>(*get_strong(), package);
    }

    void SessionModel::AddSource(hstring const &source_dir)
    {
        check_hresult(GetInterface().as<ICbsSession8>()->AddSource(0, source_dir.c_str()));
    }

    Windows::Foundation::IAsyncActionWithProgress<uint32_t> SessionModel::SaveChanges()
    {
        // use bg thread to save changes
        co_await resume_background();

        auto report_progress = co_await get_progress_token();

        if (auto sess = GetInterface().try_as<ICbsSession8>())
        {
            auto ui_handler = make<CCbsUIHandler>([&](uint32_t val) { report_progress(val); },
                                                  [](hresult hr) { throw_hresult(hr); });

            check_hresult(sess->RegisterCbsUIHandler(ui_handler.get()));
        }

        _CbsRequiredAction action{};
        check_hresult(GetInterface()->Finalize(&action));

        co_return;
    }

    Windows::Foundation::Collections::IVector<Isolation::PackageModel> SessionModel::
        GetPackageCollection(DWORD flag)
    {
        com_ptr<IEnumCbsIdentity> ids;

        check_hresult(GetInterface()->EnumeratePackages(flag, ids.put()));
        auto res = single_threaded_vector<Isolation::PackageModel>();
        for (auto &&id : GetIEnumComPtrVector<ICbsIdentity>(ids))
        {
            res.Append(this->OpenPackage(id));
        }
        return res;
    }

    Isolation::PackageModel SessionModel::OpenPackage(hstring const &identity)
    {
        com_ptr<ICbsIdentity> id;
        check_hresult(GetInterface()->CreateCbsIdentity(id.put()));
        check_hresult(id->LoadFromStringId(identity.c_str()));
        return this->OpenPackage(id);
    }

    Isolation::PackageModel SessionModel::FoundationPackage()
    {
        return this->OpenPackage(L"@Foundation");
    }

    Isolation::PackageModel SessionModel::ProductPackage()
    {
        return this->OpenPackage(L"@Product");
    }

    void SessionModel::PerformOperation(CbsOperationType operation_)
    {
        auto operation = static_cast<::_CbsOperationType>(operation_);
        if (auto session10 = GetInterface().try_as<ICbsSession10>())
        {
            check_hresult(session10->PerformOperation(0, operation));
        }
        else
        {
            throw hresult_no_interface{};
        }
    }

} // namespace winrt::UFCase::Isolation::implementation
