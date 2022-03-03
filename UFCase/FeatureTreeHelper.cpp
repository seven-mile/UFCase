#include "pch.h"
#include "FeatureTreeHelper.h"
#include "FeatureModel.h"

#include "MallocUtil.h"
#include "CbsProviderManager.h"
#include "CbsUtil.h"

#include <functional>

#include <wil/resource.h>

namespace winrt::UFCase
{

    static std::unordered_map<uint64_t, std::vector<uint64_t>> child_ids;

    IAsyncOperationWithProgress<IObservableVector<FeatureViewModel>, uint32_t>
        ConstructUpdateTree(ImageModel &image)
    {
        child_ids.clear();

        auto& session = *image.OpenSession();

        auto report_prog = co_await get_progress_token();
        apartment_context exception_context;


        //co_await resume_background();
        auto res = single_threaded_observable_vector<FeatureViewModel>();

        auto found = *session.FoundationPackage();

        report_prog(10);

        auto joinUpdates = [=](const std::vector<FeatureModel*> &updates) -> IAsyncActionWithProgress<uint32_t> {

            auto report_prog = co_await get_progress_token();

            const uint32_t ENUM_UPDATE_PROG = 30; // 30%
            report_prog(ENUM_UPDATE_PROG);

            //co_await resume_background();

            uint32_t idx = 0, all = static_cast<uint32_t>(updates.size());

            for (auto& update : updates) {
                report_prog(ENUM_UPDATE_PROG + uint32_t(std::floor(1.0 * idx / all * (100 - ENUM_UPDATE_PROG))));

                auto &&parents = update->GetParentFeatureCollection();
                child_ids[parents.size() ? update->GetHandle() : 0].push_back(parents[0]->GetHandle());
                idx++;
            }
            co_return;
        };

        auto op1 = joinUpdates(found.GetPackageFeatureCollection());
             //op2 = joinUpdates(found.GetPackageFeatureCollection())
        op1.Progress([&](const auto&, const uint32_t& pr) {
            report_prog(30 + 0.6*pr);
        });

        co_await(op1);

        std::function<void(IObservableVector<FeatureViewModel>, uint64_t)> dfs;
        dfs = [&](IObservableVector<FeatureViewModel> child, uint64_t cur) {
            child.Clear();
            for (auto child_id : child_ids[cur]) {
                FeatureViewModel vm{ child_id };
                dfs(vm.Children(), child_id);
            }
        };

        dfs(res, 0);
        report_prog(100);

        co_return res;
    }

}

