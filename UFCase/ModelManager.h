#pragma once

#include <concepts>
#include <unordered_map>

namespace winrt::UFCase {

    template<typename T> //requires std::derived_from<T, Model<T>>
    class ModelManager
    {
        inline static uint64_t cnt = 0;
        inline static std::unordered_map<uint64_t, T*> store;
    public:
        static uint64_t Insert(T* model) {
            store[++cnt] = model;
            return cnt;
        }

        static void Erase(uint64_t handle) {
            auto it = store.find(handle);
            if (it == store.end()) return;
            delete it->second;
            store.erase(handle);
        }

        static T& GetModel(uint64_t handle) {
            auto it = store.find(handle);
            assert(it != store.end());
            return *it->second;
        }
    };

}
