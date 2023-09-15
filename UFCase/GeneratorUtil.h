#pragma once

#include <coroutine>
#include <iterator>
#include <memory>
#include <utility>

namespace winrt::UFCase
{
    struct GeneratorEnd
    {
    };

    template <typename HandleType, typename ValueType> struct GeneratorIter
    {
        using iterator_category = std::input_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = std::remove_reference_t<ValueType>;
        using reference =
            std::conditional_t<std::is_reference_v<ValueType>, ValueType, ValueType &>;
        using pointer = std::add_pointer_t<ValueType>;

        bool operator!=(const GeneratorEnd &)
        {
            return !h.done();
        }
        GeneratorIter &operator++()
        {
            h();
            return *this;
        }
        value_type &operator*()
        {
            return h.promise().value();
        }

        HandleType h;
    };

    template <typename T> class Generator
    {
      public:
        struct promise_type;
        using handle_type = std::coroutine_handle<promise_type>;
        struct promise_type
        {
            using pointer = std::add_pointer_t<T>;
            pointer value_;

            auto co()
            {
                return handle_type::from_promise(*this);
            }
            auto get_return_object()
            {
                return Generator(co());
            }
            std::suspend_always initial_suspend()
            {
                return {};
            }
            std::suspend_always final_suspend() noexcept
            {
                return {};
            }
            void unhandled_exception()
            {
                throw;
            }

            std::suspend_always yield_value(T &value)
            {
                value_ = std::addressof(value);
                return {};
            }
            std::suspend_always yield_value(T &&value)
            {
                value_ = std::addressof(value);
                return {};
            }
            void return_void()
            {
            }

            T &value()
            {
                return *value_;
            }
        };

        explicit Generator(handle_type h) : h_(h)
        {
        }

        Generator(Generator &&g)
        {
            h_ = g.h_;
            begin_ = g.begin_;
            g.h_ = nullptr;
        }

        ~Generator()
        {
            if (h_)
            {
                h_.destroy();
            }
        }

        auto end() const
        {
            return GeneratorEnd{};
        }
        auto begin()
        {
            auto it = GeneratorIter<handle_type, T>{h_};
            if (!begin_)
            {
                ++it;
                begin_ = true;
            }
            return it;
        }

      private:
        handle_type h_;
        bool begin_ = false;
    };

} // namespace winrt::UFCase
