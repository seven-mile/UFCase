#pragma once

#include "ComponentDetails.g.h"
#include "ComponentListItem.g.h"

#include <winrt/UFCase.Isolation.h>

namespace winrt::UFCase::implementation
{
    struct ComponentListSnapshot
    {
        hstring TextForm;
        hstring KeyForm;
        hstring Name;
        hstring Culture;
        hstring Version;
        hstring PublicKeyToken;
        hstring ProcessorArchitecture;
        hstring VersionScope;
        hstring Status;
    };

    struct ComponentDetailsSnapshot
    {
        hstring TextForm;
        hstring KeyForm;
        hstring Name;
        hstring PayloadPath;
        hstring Manifest;
    };

    ComponentListSnapshot ReadComponentListSnapshot(Isolation::ComponentModel const &model);
    ComponentDetailsSnapshot ReadComponentDetailsSnapshot(Isolation::ComponentModel const &model);

    struct ComponentListItem : ComponentListItemT<ComponentListItem>
    {
        ComponentListItem(uint32_t record_id, ComponentListSnapshot data);

        uint32_t RecordId() const
        {
            return m_record_id;
        }

        hstring TextForm();
        hstring KeyForm();
        hstring Name();
        hstring Culture();
        hstring Version();
        hstring PublicKeyToken();
        hstring ProcessorArchitecture();
        hstring VersionScope();
        hstring Status();

      private:
        uint32_t m_record_id{};
        ComponentListSnapshot m_data;
    };

    struct ComponentDetails : ComponentDetailsT<ComponentDetails>
    {
        ComponentDetails(ComponentDetailsSnapshot data);

        hstring TextForm();
        hstring KeyForm();
        hstring Name();
        hstring PayloadPath();
        hstring Manifest();

      private:
        ComponentDetailsSnapshot m_data;
    };
} // namespace winrt::UFCase::implementation
