#include "pch.h"
#include "PackageListHelper.h"
#include "PackageViewModel.g.h"
#include "ImageModel.h"
#include "SessionModel.h"
#include "PackageModel.h"

namespace winrt::UFCase
{

    IAsyncOperationWithProgress<IObservableVector<PackageViewModel>, uint32_t> ConstructPackageList(ImageModel& image)
    {
        co_await resume_background();

        auto report_prog = co_await get_progress_token();
        auto session = image.OpenSession();
        report_prog(30);
        auto res = single_threaded_observable_vector<UFCase::PackageViewModel>();
        auto&& pkgs = session->Packages();
        report_prog(70);
        uint32_t cnt = 0;
        for (auto&& pkg : pkgs) {
            res.Append(UFCase::PackageViewModel(pkg->GetHandle()));
            report_prog(static_cast<uint32_t>(70 + 30 * ++cnt / pkgs.size()));
        }
        co_return res;
    }

}

