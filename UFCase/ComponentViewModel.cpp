#include "pch.h"
#include "ComponentViewModel.h"
#if __has_include("ComponentDetails.g.cpp")
#include "ComponentDetails.g.cpp"
#endif
#if __has_include("ComponentListItem.g.cpp")
#include "ComponentListItem.g.cpp"
#endif

#include "../UFCase.Host/ServicingApi/Isolation.h"

namespace winrt::UFCase::implementation
{
    static hstring FormatComponentStatus(Isolation::CsiComponentStatus status)
    {
        switch (status)
        {
        case Isolation::CsiComponentStatus::Prestaged:
            return L"Prestaged";
        case Isolation::CsiComponentStatus::Staged:
            return L"Staged";
        case Isolation::CsiComponentStatus::Pinned:
            return L"Pinned";
        case Isolation::CsiComponentStatus::Installed:
            return L"Installed";
        case Isolation::CsiComponentStatus::InstalledMismatch:
            return L"InstalledMismatch";
        default:
            return L"Unknown";
        }
    }

    static hstring GetComponentDisplayName(Isolation::ComponentModel const &model)
    {
        if (auto name = model.GetAttribute(L"Name"); name.empty())
        {
            return L"(unnamed)";
        }
        else
        {
            return name;
        }
    }

    ComponentListSnapshot ReadComponentListSnapshot(Isolation::ComponentModel const &model)
    {
        return ComponentListSnapshot{
            .TextForm = model.TextForm(),
            .KeyForm = model.KeyForm(),
            .Name = GetComponentDisplayName(model),
            .Culture = model.GetAttribute(L"Culture"),
            .Version = model.GetAttribute(L"Version"),
            .PublicKeyToken = model.GetAttribute(L"PublicKeyToken"),
            .ProcessorArchitecture = model.GetAttribute(L"ProcessorArchitecture"),
            .VersionScope = model.GetAttribute(L"VersionScope"),
            .Status = FormatComponentStatus(model.Status()),
        };
    }

    ComponentDetailsSnapshot ReadComponentDetailsSnapshot(Isolation::ComponentModel const &model)
    {
        return ComponentDetailsSnapshot{
            .TextForm = model.TextForm(),
            .KeyForm = model.KeyForm(),
            .Name = GetComponentDisplayName(model),
            .PayloadPath = model.PayloadPath(),
            .Manifest = model.Manifest(),
        };
    }

    ComponentListItem::ComponentListItem(uint32_t record_id, ComponentListSnapshot data)
        : m_record_id(record_id), m_data(std::move(data))
    {
    }

    hstring ComponentListItem::TextForm() { return m_data.TextForm; }
    hstring ComponentListItem::KeyForm() { return m_data.KeyForm; }
    hstring ComponentListItem::Name() { return m_data.Name; }
    hstring ComponentListItem::Culture() { return m_data.Culture; }
    hstring ComponentListItem::Version() { return m_data.Version; }
    hstring ComponentListItem::PublicKeyToken() { return m_data.PublicKeyToken; }
    hstring ComponentListItem::ProcessorArchitecture() { return m_data.ProcessorArchitecture; }
    hstring ComponentListItem::VersionScope() { return m_data.VersionScope; }
    hstring ComponentListItem::Status() { return m_data.Status; }

    ComponentDetails::ComponentDetails(ComponentDetailsSnapshot data) : m_data(std::move(data)) {}

    hstring ComponentDetails::TextForm() { return m_data.TextForm; }
    hstring ComponentDetails::KeyForm() { return m_data.KeyForm; }
    hstring ComponentDetails::Name() { return m_data.Name; }
    hstring ComponentDetails::PayloadPath() { return m_data.PayloadPath; }
    hstring ComponentDetails::Manifest() { return m_data.Manifest; }

} // namespace winrt::UFCase::implementation
