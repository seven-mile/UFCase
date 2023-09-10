#pragma once

#include "ModelManager.h"

namespace winrt::UFCase
{

    template <typename Derived> class Model
    {
        uint64_t handle;

      protected:
        Model()
        {
            static_assert(std::derived_from<Derived, Model>, "not derived from Model class");
            handle = ModelManager<Derived>::Insert((Derived *)(this));
        }

      public:
        uint64_t GetHandle() const
        {
            assert(handle);
            return handle;
        }

        static Derived &GetInstance(uint64_t handle)
        {
            return ModelManager<Derived>::GetModel(handle);
        }
    };

} // namespace winrt::UFCase
