#pragma once

#include "MainProgressService.g.h"

#include "GlobalUtil.h"
#include "AsyncUtil.h"

#include <wil/resource.h>

#include <unordered_map>
#include <format>

namespace winrt::UFCase::implementation
{
    struct MainProgressService : MainProgressServiceT<MainProgressService>
    {
        MainProgressService() {
            GlobalRes::MainProgServ(*this);
        }

        uint32_t CurrentProgress() {
            if (!_weight_sum) return 100;

            return static_cast<uint32_t>(std::round(1.0 * _progress_product_sum / _weight_sum));
        }

        Visibility Visibility() {
            if (!_weight_sum) {
                return Visibility::Collapsed;
            }
            return Visibility::Visible;
        }

        void ReportStateChange() {
            RunUITask([self = get_strong()]() {
                //OutputDebugString(L"Now notify progress state change.\n");
                self->_property_changed(*self, Data::PropertyChangedEventArgs{ L"CurrentProgress" });
                self->_property_changed(*self, Data::PropertyChangedEventArgs{ L"Visibility" });
            });
        }

        IAsyncAction InsertTask(IAsyncActionWithProgress<uint32_t> provider, uint32_t weight) {
            //_progress_list.insert(std::make_pair(provider, weight));
            if (weight == 0) co_return;
            _weight_sum += weight;
            _progress_list[provider] = 0;

            HANDLE comp_event = CreateEvent(NULL, FALSE, FALSE, nullptr);

            provider.Progress([this, weight](auto const &provider, uint32_t prog) {
                auto prev_total_prog = CurrentProgress();

                auto& cur_prog = _progress_list[provider];
                assert(prog >= cur_prog);
                _progress_product_sum += (prog - cur_prog) * weight;
                //OutputDebugString(std::format(L"==-= update prog: {} -> {} size = {}, [{} / {}]\n",
                //    cur_prog, prog, _progress_list.size(), _progress_product_sum, _weight_sum).c_str());
                cur_prog = prog;

                if (CurrentProgress() != prev_total_prog)
                    ReportStateChange();
            });

            provider.Completed([this, weight, comp_event](auto const& provider, auto const&) {
                _progress_product_sum -= _progress_list[provider] * weight;
                _weight_sum -= weight;
                _progress_list.erase(provider);

                //OutputDebugString(std::format(L"==-= completed: size = {}, [{} / {}]\n",
                //    _progress_list.size(), _progress_product_sum, _weight_sum).c_str());

                ReportStateChange();
                SetEvent(comp_event);
            });

            co_await resume_on_signal(comp_event);
            CloseHandle(comp_event);

            co_return;
        }

        std::unordered_map<IAsyncActionWithProgress<uint32_t>, uint32_t> _progress_list;
        uint32_t _progress_product_sum = 0, _weight_sum = 0;

        event<Data::PropertyChangedEventHandler> _property_changed{};

        event_token PropertyChanged(Data::PropertyChangedEventHandler handler) {
            return _property_changed.add(handler);
        }

        void PropertyChanged(event_token token) {
            _property_changed.remove(token);
        }
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct MainProgressService : MainProgressServiceT<MainProgressService, implementation::MainProgressService>
    {
    };
}
