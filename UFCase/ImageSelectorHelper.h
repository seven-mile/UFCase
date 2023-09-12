#pragma once

namespace winrt::UFCase
{
    IAsyncOperationWithProgress<IObservableVector<struct ImageViewModel>, hstring> SearchImages();

} // namespace winrt::UFCase
