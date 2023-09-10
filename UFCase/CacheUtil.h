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

        template <typename RetT>
        void *Conv(RetT ((ClassT::*field)())) {
            union {
                void *raw;
                RetT ((ClassT::*typed)());
            } conv{};
            conv.typed = field;
            return conv.raw;
        }

    public:
        static ClassCacheStore<ClassT> &Instance() {
            static ClassCacheStore<ClassT> instance;
            return instance;
        }

        template <typename RetT>
        void Set(ClassT *cls, RetT ((ClassT::*field)()), RetT const &value) {
            std::unique_lock g{mtx};
            caches[{cls, Conv(field)}] = value;
        }

        template <typename RetT>
        void Invalidate(ClassT *cls, RetT ((ClassT::*field)())) {
            std::unique_lock g{mtx};
            caches.erase({cls, Conv(field)});
        }

        void Invalidate() {
            std::unique_lock g{mtx};
            caches.clear();
        }

        template <typename RetT>
        std::optional<RetT> Get(ClassT *cls, RetT ((ClassT::*field)())) {
            std::shared_lock g{mtx};
            try {
                return std::any_cast<RetT>(caches.at({cls, Conv(field)}));
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
        ~PropertyCache() {
            ClassCacheStore<ClassT>::Instance().Invalidate(&self, prop);
        }

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
