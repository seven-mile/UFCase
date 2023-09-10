#pragma once

namespace winrt::UFCase::implementation
{

    template <typename T> struct ImplPropertyChangedT
    {
        winrt::event_token PropertyChanged(winrt::Data::PropertyChangedEventHandler const &value)
        {
            return m_propertyChanged.add(value);
        }
        void PropertyChanged(winrt::event_token const &token)
        {
            m_propertyChanged.remove(token);
        }

        void NotifyPropChange(hstring prop = L"")
        {
            m_propertyChanged((T &)*this, winrt::Data::PropertyChangedEventArgs{prop});
        }

      private:
        winrt::event<winrt::Data::PropertyChangedEventHandler> m_propertyChanged;
    };

} // namespace winrt::UFCase::implementation
