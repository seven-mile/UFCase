#pragma once

#include <map>
#include <any>
#include <shared_mutex>
#include <optional>

namespace winrt::UFCase
{

    template <typename ClassT> class ClassCacheStore
    {

        std::shared_mutex mtx;
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
        // static ClassCacheStore<ClassT> &Instance()
        //{
        //     static ClassCacheStore<ClassT> instance;
        //     return instance;
        // }

        static std::shared_ptr<ClassCacheStore<ClassT>> GetStrong()
        {
            static std::shared_ptr<ClassCacheStore<ClassT>> instance =
                std::make_shared<ClassCacheStore<ClassT>>();
            return instance;
        }

        template <typename RetT> void Set(ClassT *cls, RetT((ClassT::*field)()), RetT const &value)
        {
            std::unique_lock g{mtx};
            caches[{cls, Conv(field)}] = value;
        }

        template <typename RetT> void Invalidate(ClassT *cls, RetT((ClassT::*field)()))
        {
            std::unique_lock g{mtx};
            caches.erase({cls, Conv(field)});
        }

        void Invalidate()
        {
            std::unique_lock g{mtx};
            caches.clear();
        }

        template <typename RetT> std::optional<RetT> Get(ClassT *cls, RetT((ClassT::*field)()))
        {
            std::shared_lock g{mtx};
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

        inline static ClassCacheStore<ClassT> store;

      public:
        PropertyCache(ClassT &self, MemberT prop) : self(self), prop(prop)
        {
        }
        ~PropertyCache()
        {
            ClassCacheStore<ClassT>::GetStrong()->Invalidate(&self, prop);
        }

        RetT operator()()
        {
            if (auto val = ClassCacheStore<ClassT>::GetStrong()->Get(&self, prop); val.has_value())
            {
                return *val;
            }
            else
            {
                auto new_val = (self.*prop)();
                ClassCacheStore<ClassT>::GetStrong()->Set(&self, prop, new_val);
                return new_val;
            }
        }
    };

} // namespace winrt::UFCase
