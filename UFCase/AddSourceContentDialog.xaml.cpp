#include "pch.h"
#include "AddSourceContentDialog.xaml.h"
#if __has_include("AddSourceContentDialog.g.cpp")
#include "AddSourceContentDialog.g.cpp"
#endif

#include <winrt/Windows.Storage.Pickers.h>
// This include file is needed for the XAML Native Window Interop.
#include <microsoft.ui.xaml.window.h>
#include <shobjidl_core.h>

namespace winrt {
    using namespace Windows::Storage::Pickers;
}

namespace winrt::UFCase::implementation
{
    AddSourceContentDialog::AddSourceContentDialog(Window parent) : parent(parent)
    {
        InitializeComponent();
    }

    hstring AddSourceContentDialog::SourcePath()
    {
        return this->SourceTextBox().Text();
    }

    void AddSourceContentDialog::BrowserButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        FolderPicker fp;
        
        HWND hWndParent;
        check_hresult(parent.as<IWindowNative>()->get_WindowHandle(&hWndParent));
        fp.as<IInitializeWithWindow>()->Initialize(hWndParent);

        fp.CommitButtonText(L"Add source");
        fp.SuggestedStartLocation(PickerLocationId::ComputerFolder);
        fp.ViewMode(PickerViewMode::List);
        fp.PickSingleFolderAsync().Completed([txtBox = this->SourceTextBox()](auto const&op, auto const&) {
            txtBox.DispatcherQueue().TryEnqueue([op, txtBox]() {
                txtBox.Text(op.GetResults().Path());
            });
        });
    }
}
