#pragma once

#include "AddSourceContentDialog.g.h"

namespace winrt::UFCase::implementation
{
    struct AddSourceContentDialog : AddSourceContentDialogT<AddSourceContentDialog>
    {
        AddSourceContentDialog();

        hstring SourcePath();

        fire_and_forget BrowseButton_Click(IInspectable const &sender, RoutedEventArgs const &args);
    };
} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct AddSourceContentDialog
        : AddSourceContentDialogT<AddSourceContentDialog, implementation::AddSourceContentDialog>
    {
    };
} // namespace winrt::UFCase::factory_implementation
