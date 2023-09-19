#pragma once

#include "GlyphButton.g.h"

#include <winrt/Windows.UI.Xaml.Interop.h>
#include <XamlTypeInfo.xaml.g.h>

namespace winrt::UFCase::implementation
{
    struct GlyphButton : GlyphButtonT<GlyphButton>
    {
        GlyphButton() = default;

        static Microsoft::UI::Xaml::DependencyProperty GlyphProperty()
        {
            static auto glyph_prop = DependencyProperty::Register(
                L"Glyph", xaml_typename<hstring>(), xaml_typename<UFCase::GlyphButton>(),
                PropertyMetadata{box_value(L"")});
            return glyph_prop;
        }

        hstring Glyph()
        {
            return winrt::unbox_value<hstring>(GetValue(GlyphProperty()));
        }

        void Glyph(hstring value)
        {
            SetValue(GlyphProperty(), winrt::box_value(value));
        }

      private:
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct GlyphButton : GlyphButtonT<GlyphButton, implementation::GlyphButton>
    {
    };
} // namespace winrt::UFCase::factory_implementation
