#include "pch.h"
#include "FeatureTreeElement.h"
#if __has_include("FeatureTreeElement.g.cpp")
#include "FeatureTreeElement.g.cpp"
#endif

namespace winrt::UFCase::implementation
{
    FeatureTreeElement::FeatureTreeElement(hstring name, hstring desc, bool enabled, child_t children)
    {
        m_name = name;
        m_desc = desc;
        m_is_enabled = enabled;
        m_children = children;
    }

    hstring FeatureTreeElement::Name()
    {
        return m_name;
    }
    void FeatureTreeElement::Name(const hstring &value)
    {
        m_name = value;
    }
    hstring FeatureTreeElement::Description()
    {
        return m_desc;
    }
    void FeatureTreeElement::Description(const hstring& value)
    {
        m_desc = value;
    }
    bool FeatureTreeElement::IsEnabled()
    {
        return m_is_enabled;
    }
    void FeatureTreeElement::IsEnabled(bool value)
    {
        m_is_enabled = value;
    }
    Windows::Foundation::Collections::IObservableVector<UFCase::FeatureTreeElement> FeatureTreeElement::Children()
    {
        return m_children;
    }
}
