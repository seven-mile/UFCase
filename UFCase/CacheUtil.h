#pragma once

#include "GlobalUtil.h"

#include <map>
#include <any>
#include <shared_mutex>
#include <optional>

#define ASSERT_UI_THREAD() // assert(Application::Current().Resources())

namespace winrt::UFCase
{

    template <typename ClassT> class ClassCacheStore
    {
        std::map<std::pair<ClassT *, void *>, std::any> caches;

        template <typename RetT> void *Conv(RetT((ClassT::*field)()))
        {
            union {
                void *raw;
                RetT((ClassT::*typed)());
            } conv{};
            conv.typed = field;
            return conv.raw;
        }

      public:

        static std::shared_ptr<ClassCacheStore<ClassT>> GetStrong()
        {
            static std::shared_ptr<ClassCacheStore<ClassT>> instance =
                std::make_shared<ClassCacheStore<ClassT>>();
            return instance;
        }

        template <typename RetT> void Set(ClassT *cls, RetT((ClassT::*field)()), RetT const &value)
        {
            ASSERT_UI_THREAD();
            caches[{cls, Conv(field)}] = value;
        }

        template <typename RetT> void Invalidate(ClassT *cls, RetT((ClassT::*field)()))
        {
            ASSERT_UI_THREAD();
            caches.erase({cls, Conv(field)});
        }

        void Invalidate()
        {
            ASSERT_UI_THREAD();
            caches.clear();
        }

        template <typename RetT> std::optional<RetT> Get(ClassT *cls, RetT((ClassT::*field)()))
        {
            ASSERT_UI_THREAD();
            if (auto it = caches.find({cls, Conv(field)}); it != caches.end())
            {
                return std::any_cast<RetT>(it->second);
            }
            else
            {
                return std::nullopt;
            }
        }
    };

    template <typename RetT, typename ClassT> class PropertyCache
    {
        using MemberT = RetT((ClassT::*)());
        ClassT &self;
        MemberT prop;

        inline static std::shared_ptr<ClassCacheStore<ClassT>> store;

      public:
        PropertyCache(ClassT &self, MemberT prop) : self(self), prop(prop)
        {
            store = ClassCacheStore<ClassT>::GetStrong();
        }
        ~PropertyCache()
        {
            store->Invalidate(&self, prop);
        }

        RetT operator()()
        {
            if (auto val = store->Get(&self, prop); val.has_value())
            {
                return *val;
            }
            else
            {
                auto new_val = (self.*prop)();
                store->Set(&self, prop, new_val);
                return new_val;
            }
        }
    };

} // namespace winrt::UFCase
