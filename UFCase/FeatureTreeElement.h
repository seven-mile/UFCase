#pragma once

#include "FeatureTreeElement.g.h"

namespace winrt::UFCase::implementation
{
    struct FeatureTreeElement : FeatureTreeElementT<FeatureTreeElement>
    {
        using child_t = IObservableVector<UFCase::FeatureTreeElement>;
        FeatureTreeElement(hstring name, hstring desc, bool enabled, child_t children);

        hstring Name();
        void Name(const hstring &value);

        hstring Description();
        void Description(const hstring &value);

        bool IsEnabled();
        void IsEnabled(bool value);

        child_t Children();

        IconSource Icon();
        void Icon(IconSource const &value);

        Primitives::FlyoutBase ContextMenu();
        void ContextMenu(Primitives::FlyoutBase const &value);

    private:
        hstring m_name;
        hstring m_desc;
        bool m_is_enabled;
        child_t m_children;
        IconSource m_icon {nullptr};
        Primitives::FlyoutBase m_menu {nullptr};
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeatureTreeElement : FeatureTreeElementT<FeatureTreeElement, implementation::FeatureTreeElement>
    {
    };
}
