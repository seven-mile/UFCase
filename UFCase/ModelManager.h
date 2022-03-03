#pragma once

#include <concepts>
#include <unordered_map>

template<typename T> requires std::derived_from<T, Model<T>>
class ModelManager
{
    static uint64_t cnt = 0;
    static const std::unordered_map<uint64_t, T*> store;
public:
    uint64_t Insert(T* model) {
        store[++cnt] = model;
        return cnt;
    }

    void Erase(uint64_t handle) {
        auto it = store.find(handle);
        if (it == store.end()) return;
        delete it->second;
        store.erase(handle);
    }

    static T& GetModel(uint64_t handle) const {
        auto it = store.find(handle);
        assert(it != store.find(handle));
        return *it->second;
    }
};

