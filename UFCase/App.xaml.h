#pragma once

#include "App.xaml.g.h"

namespace winrt::UFCase::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const &);

      private:
        UFCase::MainWindow window{nullptr};
    };

} // namespace winrt::UFCase::implementation
