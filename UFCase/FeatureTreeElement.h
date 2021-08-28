#pragma once

#include "FeatureTreeElement.g.h"

namespace winrt::UFCase::implementation
{
    struct FeatureTreeElement : FeatureTreeElementT<FeatureTreeElement>
    {
        using child_t = Windows::Foundation::Collections::IObservableVector<UFCase::FeatureTreeElement>;
        FeatureTreeElement(hstring name, hstring desc, bool enabled, child_t children);

        hstring Name();
        void Name(const hstring &value);

        hstring Description();
        void Description(const hstring &value);

        bool IsEnabled();
        void IsEnabled(bool value);

        child_t Children();

    private:
        hstring m_name;
        hstring m_desc;
        bool m_is_enabled;
        child_t m_children;
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct FeatureTreeElement : FeatureTreeElementT<FeatureTreeElement, implementation::FeatureTreeElement>
    {
    };
}
