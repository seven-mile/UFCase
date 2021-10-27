#pragma once

#include "FeatureTreeElement.g.h"

namespace winrt::UFCase::implementation
{
    struct FeatureTreeElement : FeatureTreeElementT<FeatureTreeElement>
    {
        using child_t = IObservableVector<UFCase::FeatureTreeElement>;
        FeatureTreeElement(hstring name, hstring desc, hstring identity, FeatureState state, child_t children);

        // implement INotifyPropertyChanged
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const& value);
        void PropertyChanged(winrt::event_token const& token);

        hstring Name();
        void Name(const hstring &value);
        hstring Description();
        void Description(const hstring &value);
        hstring Identity();
        void Identity(const hstring &value);
        FeatureState State();

        child_t Children();

        hstring ModificationMark();
        void ModificationMark(const hstring &value);
        IconSource Icon();
        void Icon(IconSource const &value);
        Primitives::FlyoutBase ContextMenu();
        void ContextMenu(Primitives::FlyoutBase const &value);

        // Effective Method : Operation with current Cbs Session
        void State(FeatureState const &value);

    private:
        winrt::event<winrt::Data::PropertyChangedEventHandler> m_propertyChanged;

        hstring m_name;
        hstring m_desc;
        hstring m_identity;
        FeatureState m_state = FeatureState::Invalid;
        child_t m_children;
        hstring m_mark = L"";
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
