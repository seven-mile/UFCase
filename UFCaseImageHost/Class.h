#pragma once

#include "Class.g.h"
#include <wil/cppwinrt_wrl.h>

namespace winrt::UFCaseImageHost::implementation
{
    [uuid("BFB04A77-8632-4EE0-8E67-93A4712BE42F")] struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);

        Windows::Foundation::Collections::IVector<UFCase::ImageViewModel> GetImages() {
          return multi_threaded_vector<UFCase::ImageViewModel>();
        }
    };
} // namespace winrt::UFCaseImageHost::implementation

namespace winrt::UFCaseImageHost::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
} // namespace winrt::UFCaseImageHost::factory_implementation
