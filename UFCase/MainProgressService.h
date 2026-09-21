#pragma once

#include "MainProgressService.g.h"

#include "GlobalUtil.h"
#include "AsyncUtil.h"
#include "PropChgUtil.h"

#include <wil/resource.h>

#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <format>
#include <mutex>

namespace winrt::UFCase::implementation
{
    struct MainProgressService : MainProgressServiceT<MainProgressService>,
                                 ImplPropertyChangedT<MainProgressService>
    {
        MainProgressService()
        {
            GlobalRes::MainProgServ(*this);
        }

        uint32_t CurrentProgress()
        {
            std::scoped_lock lock(_progress_mutex);
            return CurrentProgressLocked();
        }

        Visibility Visibility()
        {
            std::scoped_lock lock(_progress_mutex);
            return _weight_sum ? Visibility::Visible : Visibility::Collapsed;
        }

        void ReportStateChange()
        {
            RunUITask([self = get_strong()]() {
                // OutputDebugString(L"Now notify progress state change.\n");
                self->NotifyPropChange(L"CurrentProgress");
                self->NotifyPropChange(L"Visibility");
            });
        }

        IAsyncAction InsertTask(IAsyncActionWithProgress<uint32_t> provider, uint32_t weight)
        {
            if (weight == 0)
                co_return;

            auto self = get_strong();
            {
                std::scoped_lock lock(_progress_mutex);
                if (_progress_list.contains(provider))
                    throw_hresult(E_INVALIDARG);

                _weight_sum += weight;
                _progress_list.emplace(provider, 0);
            }

            try
            {
                provider.Progress([weak = get_weak(), weight](auto const &provider, uint32_t prog) {
                    if (auto self = weak.get())
                    {
                        bool changed = false;
                        {
                            std::scoped_lock lock(self->_progress_mutex);
                            auto const entry = self->_progress_list.find(provider);
                            if (entry == self->_progress_list.end())
                                return;

                            auto const previous_progress = self->CurrentProgressLocked();
                            auto &current_progress = entry->second;
                            if (prog < current_progress)
                                return;

                            prog = std::min(prog, 100u);
                            self->_progress_product_sum +=
                                static_cast<uint64_t>(prog - current_progress) * weight;
                            current_progress = prog;
                            changed = self->CurrentProgressLocked() != previous_progress;
                        }

                        if (changed)
                            self->ReportStateChange();
                    }
                });

                co_await provider;
            }
            catch (...)
            {
                RemoveTask(provider, weight);
                throw;
            }

            RemoveTask(provider, weight);
        }

      private:
        uint32_t CurrentProgressLocked() const
        {
            if (!_weight_sum)
                return 100;

            return static_cast<uint32_t>(std::round(
                static_cast<double>(_progress_product_sum) / _weight_sum));
        }

        void RemoveTask(IAsyncActionWithProgress<uint32_t> const &provider, uint32_t weight)
        {
            {
                std::scoped_lock lock(_progress_mutex);
                auto const entry = _progress_list.find(provider);
                if (entry == _progress_list.end())
                    return;

                _progress_product_sum -= static_cast<uint64_t>(entry->second) * weight;
                _weight_sum -= weight;
                _progress_list.erase(entry);
            }

            ReportStateChange();
        }

        std::mutex _progress_mutex;
        std::unordered_map<IAsyncActionWithProgress<uint32_t>, uint32_t> _progress_list;
        uint64_t _progress_product_sum = 0;
        uint64_t _weight_sum = 0;
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct MainProgressService
        : MainProgressServiceT<MainProgressService, implementation::MainProgressService>
    {
    };
} // namespace winrt::UFCase::factory_implementation
