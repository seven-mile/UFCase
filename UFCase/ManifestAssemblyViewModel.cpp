#include "pch.h"
#include "ManifestAssemblyViewModel.h"
#if __has_include("ManifestAssemblyViewModel.g.cpp")
#include "ManifestAssemblyViewModel.g.cpp"
#endif

#include <winrt/UFCase.Host.Manifest.h>

#include <wil/resource.h>

#include "AsyncUtil.h"

#include <numeric>

namespace winrt::UFCase::implementation
{

    hstring to_hstring(UFCase::Host::Manifest::RegistryValueType type)
    {
        /*
        enum class RegistryValueType : int32_t
        {
            RegNone = 0,
            RegSz = 1,
            RegExpandSz = 2,
            RegBinary = 3,
            RegDword = 4,
            RegDwordBigEndian = 5,
            RegLink = 6,
            RegMultiSz = 7,
            RegResourceList = 8,
            RegFullResourceDescriptor = 9,
            RegResourceRequirementsList = 10,
            RegQword = 11,
        };
        */

        switch (type)
        {
        case UFCase::Host::Manifest::RegistryValueType::RegNone:
            return L"REG_NONE";
        case UFCase::Host::Manifest::RegistryValueType::RegSz:
            return L"REG_SZ";
        case UFCase::Host::Manifest::RegistryValueType::RegExpandSz:
            return L"REG_EXPAND_SZ";
        case UFCase::Host::Manifest::RegistryValueType::RegBinary:
            return L"REG_BINARY";
        case UFCase::Host::Manifest::RegistryValueType::RegDword:
            return L"REG_DWORD";
        case UFCase::Host::Manifest::RegistryValueType::RegDwordBigEndian:
            return L"REG_DWORD_BIG_ENDIAN";
        case UFCase::Host::Manifest::RegistryValueType::RegLink:
            return L"REG_LINK";
        case UFCase::Host::Manifest::RegistryValueType::RegMultiSz:
            return L"REG_MULTI_SZ";
        case UFCase::Host::Manifest::RegistryValueType::RegResourceList:
            return L"REG_RESOURCE_LIST";
        case UFCase::Host::Manifest::RegistryValueType::RegFullResourceDescriptor:
            return L"REG_FULL_RESOURCE_DESCRIPTOR";
        case UFCase::Host::Manifest::RegistryValueType::RegResourceRequirementsList:
            return L"REG_RESOURCE_REQUIREMENTS_LIST";
        case UFCase::Host::Manifest::RegistryValueType::RegQword:
            return L"REG_QWORD";
        default:
            return L"Unknown";
        }
    }

    hstring to_hstring(UFCase::Host::Manifest::RegistryValue val)
    {
        switch (val.Type())
        {
        case UFCase::Host::Manifest::RegistryValueType::RegNone:
            return L"";
        case UFCase::Host::Manifest::RegistryValueType::RegSz:
        case UFCase::Host::Manifest::RegistryValueType::RegExpandSz:
        case UFCase::Host::Manifest::RegistryValueType::RegLink:
            return unbox_value_or<hstring>(val.Data(), L"type error");
        case UFCase::Host::Manifest::RegistryValueType::RegBinary:
            return L"Binary data";
        case UFCase::Host::Manifest::RegistryValueType::RegDword:
        case UFCase::Host::Manifest::RegistryValueType::RegDwordBigEndian:
            return winrt::to_hstring(unbox_value<int32_t>(val.Data()));
        case UFCase::Host::Manifest::RegistryValueType::RegMultiSz: {
            std::wstring result;
            auto list = unbox_value<com_array<hstring>>(val.Data());

            return std::accumulate(list.begin(), list.end(), hstring{},
                                   [](auto &&a, auto &&b) { return a + L" | " + b; });
        }
        case UFCase::Host::Manifest::RegistryValueType::RegResourceList:
            return L"Resource list data";
        case UFCase::Host::Manifest::RegistryValueType::RegFullResourceDescriptor:
            return L"Full resource descriptor data";
        case UFCase::Host::Manifest::RegistryValueType::RegResourceRequirementsList:
            return L"Resource requirements list data";
        case UFCase::Host::Manifest::RegistryValueType::RegQword:
            return winrt::to_hstring(unbox_value<int64_t>(val.Data()));
        default:
            return L"Unknown";
        }
    }

    hstring to_hstring(UFCase::Host::Manifest::AssemblyIdentity identity)
    {
        return winrt::format(
                   L"{}, Culture={}, Version={}, PublicKeyToken={}, ProcessorArchitecture={}",
                   identity.Name(), identity.Language(), identity.Version(),
                   identity.PublicKeyToken(), identity.ProcessorArchitecture())
            .c_str();
    }

    IAsyncActionWithProgress<uint32_t> ManifestAssemblyViewModel::PullData()
    {
        apartment_context ui_thread{};
        auto report_progress = co_await get_progress_token();

        auto g = wil::scope_exit([&] { report_progress(100); });

        m_files = multi_threaded_observable_vector<FileItem>();
        m_regs = multi_threaded_observable_vector<RegItem>();
        m_deps = multi_threaded_observable_vector<hstring>();

        co_await resume_background();

        if (m_state == ManifestAssemblyViewModelState::Loading)
        {
            co_return;
        }

        m_asm = m_model.CookedManifest();
        m_name = to_hstring(m_asm.Identity());
        m_manifest_text = m_model.Manifest();

        report_progress(50);

        for (auto &file : m_asm.Files())
        {
            FileItem item{.DestinationName = file.DestinationName(),
                          .DestinationPath = file.DestinationPath(),
                          .Hash = file.Hash(),
                          .HashAlgorithm = file.HashAlgorithm()};

            RunUITask([=] { m_files.Append(item); });
        }

        report_progress(75);

        for (auto &key : m_asm.Keys())
        {
            for (auto &val : key.Values())
            {
                RegItem item{
                    .Name = key.Name(), .Type = to_hstring(val.Type()), .Value = to_hstring(val)};

                RunUITask([=] { m_regs.Append(item); });
            }
        }

        report_progress(90);

        for (auto &dep : m_asm.Dependencies())
        {
            auto dep_str = to_hstring(dep.Identity());

            RunUITask([=] { m_deps.Append(dep_str); });
        }

        report_progress(100);

        co_await ui_thread;

        NotifyPropChange();

        m_state = ManifestAssemblyViewModelState::Idle;

        co_return;
    }
    void ManifestAssemblyViewModel::LocateDependentAssembly(int32_t index)
    {
        if (m_state != ManifestAssemblyViewModelState::Idle)
        {
            return;
        }

        if (index < 0 || (uint32_t)index >= m_deps.Size())
        {
            return;
        }

        auto deps = m_asm.Dependencies();
        auto &dep = deps[index];

        // todo: communicate with main window, and show the results
        // POC:
        //   MainNavigationService().NavigateTo(L"Components", NavContext { query: {
        //   ...dep.Identity() } }); MainWindow().Activate();

        OutputDebugString(winrt::format(L"Locating assembly: {} {}    //{}\n",
                                        dep.Identity().Name(), dep.Identity().Version(),
                                        dep.Identity().KeyForm())
                              .c_str());
    }
} // namespace winrt::UFCase::implementation
