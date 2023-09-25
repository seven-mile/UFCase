#include "pch.h"
#include "PackageManifestViewerWindowViewModel.h"
#if __has_include("PackageManifestViewerWindowViewModel.g.cpp")
#include "PackageManifestViewerWindowViewModel.g.cpp"
#endif

#include <wil/resource.h>

#include <winrt/UFCase.Isolation.h>

#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Data.Xml.Dom.h>

#include "AsyncUtil.h"

#include <filesystem>
#include <numeric>

namespace winrt::UFCase::implementation
{
    PackageManifestViewerWindowViewModel::PackageManifestViewerWindowViewModel(
        UFCase::Isolation::PackageModel model)
        : m_model(model)
    {
    }

    IAsyncActionWithProgress<uint32_t> PackageManifestViewerWindowViewModel::PullData()
    {
        apartment_context ui_thread;
        auto report_prog = co_await get_progress_token();

        auto g = wil::scope_exit([&]() noexcept { report_prog(100); });

        m_components = multi_threaded_observable_vector<UFCase::Identity>();
        m_packages = multi_threaded_observable_vector<UFCase::Identity>();
        m_drivers = multi_threaded_observable_vector<UFCase::Identity>();
        m_parents = multi_threaded_observable_vector<UFCase::Identity>();

        co_await resume_background();

        m_title = L"Package: " + m_model.Identity();

        auto manifest_path = m_model.ManifestFilePath();

        if (std::filesystem::exists(manifest_path.c_str()))
        {
            auto file = co_await Windows::Storage::StorageFile::GetFileFromPathAsync(manifest_path);

            m_manifest_text = co_await Windows::Storage::FileIO::ReadTextAsync(file);

            co_await ParseManifest(file);
        }

        co_await ui_thread;

        NotifyPropChange();

        co_return;
    }

    IAsyncActionWithProgress<uint32_t> PackageManifestViewerWindowViewModel::ParseManifest(
        Windows::Storage::StorageFile file)
    {
        auto doc = co_await Windows::Data::Xml::Dom::XmlDocument::LoadFromFileAsync(file);

        auto asm_ns = box_value(L"xmlns:ns='urn:schemas-microsoft-com:asm.v3'");

        auto node = doc.SelectSingleNodeNS(L"/ns:assembly", asm_ns);

        for (auto comp_ident_node :
             node.SelectNodesNS(L"./ns:package/ns:update/ns:component/ns:assemblyIdentity", asm_ns))
        {
            auto ident = ParseIdentity(comp_ident_node, IdentityType::Component);
            RunUITask([=] { m_components.Append(ident); });
        }

        for (auto pkg_ident_node :
             node.SelectNodesNS(L"./ns:package/ns:update/ns:package/ns:assemblyIdentity", asm_ns))
        {
            auto ident = ParseIdentity(pkg_ident_node, IdentityType::Package);
            RunUITask([=] { m_packages.Append(ident); });
        }

        for (auto drv_ident_node :
             node.SelectNodesNS(L"./ns:package/ns:update/ns:driver/ns:assemblyIdentity", asm_ns))
        {
            auto ident = ParseIdentity(drv_ident_node, IdentityType::Component);
            RunUITask([=] { m_drivers.Append(ident); });
        }

        for (auto parent_ident_node :
             node.SelectNodesNS(L"./ns:package/ns:parent/ns:assemblyIdentity", asm_ns))
        {
            auto ident = ParseIdentity(parent_ident_node, IdentityType::Package);
            RunUITask([=] { m_parents.Append(ident); });
        }
    }

    UFCase::Identity PackageManifestViewerWindowViewModel::ParseIdentity(
        Windows::Data::Xml::Dom::IXmlNode node, IdentityType type)
    {
        UFCase::Identity ident{};

        ident.Type(type);

        ident.ImageRoot(m_model.Session().Image().Bootdrive());

        for (auto attr : node.Attributes())
        {
            auto name = attr.NodeName();
            auto value = unbox_value<hstring>(attr.NodeValue());

            if (name == L"name")
            {
                ident.Name(value);
            }
            else if (name == L"version")
            {
                ident.Version(value);
            }
            else if (name == L"publicKeyToken")
            {
                ident.PublicKeyToken(value);
            }
            else if (name == L"language")
            {
                ident.Culture(value);
            }
            else if (name == L"processorArchitecture")
            {
                ident.ProcessorArchitecture(value);
            }
            else if (name == L"versionScope")
            {
                ident.VersionScope(value);
            }
        }

        return ident;
    }
} // namespace winrt::UFCase::implementation
