#pragma once

#include "App.xaml.g.h"

#include "HostGuard.h"

namespace winrt::UFCase::implementation
{
    struct App : AppT<App>
    {
        App();

        fire_and_forget OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const &);

      private:
        UFCase::MainWindow window{nullptr};
        UFCase::SplashWindow splash{nullptr};

        HostGuard host_guard;
    };

} // namespace winrt::UFCase::implementation
