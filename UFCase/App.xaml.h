#pragma once

#include "App.xaml.g.h"

namespace winrt::UFCase::implementation
{
    struct App : AppT<App>
    {
        App();

        IAsyncAction OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        UFCase::MainWindow window{ nullptr };
    };
}
