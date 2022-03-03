#pragma once

#include "ModelManager.h"

template<typename Derived>
class Model
{
    uint64_t handle;
protected:
    Model() {
        static_assert(std::derived_from<Derived, Model>, "not derived from Model class");
        handle = ModelManager<Derived>::Insert(this);
    }
public:
    uint64_t GetHandle() {
        assert(handle);
        return handle;
    }

    static Derived &GetInstance(uint64_t handle) {
        return ModelManager<Derived>::GetModel(handle);
    }
};

