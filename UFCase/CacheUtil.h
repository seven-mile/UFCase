#pragma once

#include <map>
#include <any>
#include <shared_mutex>
#include <optional>

namespace winrt::UFCase {

    template <typename ClassT>
    class ClassCacheStore {

        std::shared_mutex mtx;
        std::map<std::pair<ClassT*, void*>, std::any> caches;

    public:
        static ClassCacheStore<ClassT> &Instance() {
            static ClassCacheStore<ClassT> instance;
            return instance;
        }

        template <typename RetT>
        void Set(ClassT *cls, RetT ((ClassT::*field)()), RetT const &value) {
            std::unique_lock g{mtx};
            union {
                void *raw;
                RetT ((ClassT::*typed)());
            } conv{};
            conv.typed = field;
            caches[{cls, conv.raw}] = value;
        }

        void InvalidateAll() {
            std::unique_lock g{mtx};
            caches.clear();
        }

        template <typename RetT>
        std::optional<RetT> Get(ClassT *cls, RetT ((ClassT::*field)())) {
            std::shared_lock g{mtx};
            union {
                void *raw;
                RetT ((ClassT::*typed)());
            } conv{};
            conv.typed = field;
            try {
                return std::any_cast<RetT>(caches.at({cls, conv.raw}));
            } catch (std::out_of_range const &) {
                return std::nullopt;
            }
        }
    };


    template <typename RetT, typename ClassT>
    class PropertyCache {
        using MemberT = RetT ((ClassT::*)());
        ClassT &self;
        MemberT prop;

        inline static ClassCacheStore<ClassT> store;

      public:
        PropertyCache(ClassT &self, MemberT prop): self(self), prop(prop) {}

        RetT operator()() {
            if (auto val = ClassCacheStore<ClassT>::Instance().Get(&self, prop); val.has_value()) {
                return *val;
            } else {
                auto new_val = (self.*prop)();
                ClassCacheStore<ClassT>::Instance().Set(&self, prop, new_val);
                return new_val;
            }
        }
    };

    

}
