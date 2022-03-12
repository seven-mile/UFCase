#pragma once
#include "ImageModel.h"

namespace winrt::UFCase {
    IAsyncOperationWithProgress<IObservableVector<struct PackageViewModel>, uint32_t> ConstructPackageList(ImageModel& image);
}
