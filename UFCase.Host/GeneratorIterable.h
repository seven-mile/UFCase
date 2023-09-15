#pragma once

#include "UFCase.Host.GeneratorIterator.g.h"
#include "UFCase.Host.GeneratorIterable.g.h"

#include "../UFCase/GeneratorUtil.h"

namespace winrt::UFCase::Host::implementation
{
    struct GeneratorIterator : GeneratorIteratorT<GeneratorIterator>
    {
        GeneratorIterator(std::shared_ptr<Generator<IInspectable>> iter)
            : m_iter(iter), m_current(m_iter->begin())
        {
        }

        std::shared_ptr<Generator<IInspectable>> m_iter;
        decltype(m_iter->begin()) m_current;

        IInspectable Current()
        {
            return *m_current;
        }

        bool MoveNext()
        {
            return ++m_current != m_iter->end();
        }

        uint32_t GetMany(winrt::array_view<IInspectable> items)
        {
            uint32_t i = 0;
            for (; i < items.size() && m_current != m_iter->end(); ++i, ++m_current)
            {
                items[i] = *m_current;
            }
            return i;
        }

        bool HasCurrent()
        {
            return m_current != m_iter->end();
        }
    };

    struct GeneratorIterable : GeneratorIterableT<GeneratorIterable>
    {
        std::shared_ptr<Generator<IInspectable>> g;

        template <typename T>
        GeneratorIterable(std::shared_ptr<Generator<T>> iter)
            : g(std::make_shared<Generator<IInspectable>>([iter]() -> Generator<IInspectable> {
                  for (auto &&item : *iter)
                  {
                      co_yield box_value(item);
                  }
              }()))
        {
        }

        Host::GeneratorIterator First()
        {
            return make<GeneratorIterator>(g);
        }
    };
} // namespace winrt::UFCase::Host::implementation
