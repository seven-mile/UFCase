#pragma once

namespace winrt::UFCase {
    IAsyncActionWithProgress<uint32_t> SearchImages();
    IObservableVector<struct ImageViewModel> GetImageSearchResult();
}


