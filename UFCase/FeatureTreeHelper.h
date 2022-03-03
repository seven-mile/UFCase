#pragma once

#include "FeatureViewModel.g.h"
#include "ImageModel.h"
#include "SessionModel.h"

#include <vector>
#include <string>

namespace winrt::UFCase
{
    winrt::IAsyncOperationWithProgress<winrt::IObservableVector<FeatureViewModel>, uint32_t> ConstructUpdateTree(ImageModel &image);
}


