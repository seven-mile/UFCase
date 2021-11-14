#pragma once

#include "AddSourceContentDialog.g.h"


namespace winrt::UFCase::implementation
{
    struct AddSourceContentDialog : AddSourceContentDialogT<AddSourceContentDialog>
    {
        AddSourceContentDialog(Window parent);

        hstring SourcePath();

        void BrowserButton_Click(IInspectable const& sender, RoutedEventArgs const& args);

        Window parent{ nullptr };
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct AddSourceContentDialog : AddSourceContentDialogT<AddSourceContentDialog, implementation::AddSourceContentDialog>
    {
    };
}
