#pragma once

#include "RelayCommand.g.h"

#include <functional>

namespace winrt::UFCase::implementation
{
    struct RelayCommand : RelayCommandT<RelayCommand>
    {
        event_token CanExecuteChanged(EventHandler<IInspectable> handler) {
            return _can_execute_changed.add(handler);
        }

        void CanExecuteChanged(event_token token) {
            _can_execute_changed.remove(token);
        }

        bool CanExecute(IInspectable parameter) { return _can_execute_callback(parameter); }
        void Execute(IInspectable parameter) { _execute_callback(parameter); }

        RelayCommand(
            std::function<void(IInspectable)> executeCallback,
            std::function<bool(IInspectable)> canExecuteCallback = [](IInspectable) { return true; })
                : _execute_callback(executeCallback), _can_execute_callback(canExecuteCallback) { }

        void RaiseCanExecuteChanged() {
            _can_execute_changed(*this, nullptr);
        }

    private:
        event<EventHandler<IInspectable>> _can_execute_changed;
        std::function<void(IInspectable)> _execute_callback;
        std::function<bool(IInspectable)> _can_execute_callback;
    };
}
