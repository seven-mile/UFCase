#include "pch.h"
#include "AddSourceContentDialog.xaml.h"
#if __has_include("AddSourceContentDialog.g.cpp")
#include "AddSourceContentDialog.g.cpp"
#endif

#include <winrt/Windows.Storage.Pickers.h>
// This include file is needed for the XAML Native Window Interop.
#include <microsoft.ui.xaml.window.h>
#include <shobjidl_core.h>

#include <wil/resource.h>

#include "GlobalUtil.h"

namespace winrt
{
    using namespace Windows::Storage::Pickers;
}

namespace winrt::UFCase::implementation
{
    AddSourceContentDialog::AddSourceContentDialog()
    {
    }

    hstring AddSourceContentDialog::SourcePath()
    {
        return this->SourceTextBox().Text();
    }

    fire_and_forget AddSourceContentDialog::BrowseButton_Click(IInspectable const &,
                                                               RoutedEventArgs const &)
    {
        auto lifetime = get_strong();

        co_await resume_background();

        auto fd = create_instance<IFileDialog>(CLSID_FileOpenDialog);
        check_hresult(fd->SetOptions(FOS_PICKFOLDERS));

        check_hresult(fd->SetTitle(L"Select a source folder"));

        HWND hwndOwner;
        GlobalRes::MainWnd().as<IWindowNative>()->get_WindowHandle(
            reinterpret_cast<HWND *>(&hwndOwner));

        auto hr = fd->Show(hwndOwner);

        if (hr == HRESULT_FROM_WIN32(ERROR_CANCELLED)) {
            co_return;
        } else if (FAILED(hr)) {
            throw_hresult(hr);
        }

        com_ptr<IShellItem> item;
        check_hresult(fd->GetResult(item.put()));

        hstring path = L"";
        {
            wil::unique_cotaskmem_string sh_path;
            // maybe the shell item has no path
            if (SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, wil::out_param(sh_path))))
                path = sh_path.get();
        }

        auto txtBox = SourceTextBox();

        txtBox.DispatcherQueue().TryEnqueue([path, txtBox]() { txtBox.Text(path.c_str()); });
    }

} // namespace winrt::UFCase::implementation
