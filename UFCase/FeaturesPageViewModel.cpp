#include "pch.h"
#include "FeaturesPageViewModel.h"
#if __has_include("FeaturesPageViewModel.g.cpp")
#include "FeaturesPageViewModel.g.cpp"
#endif

#include "CbsApi.h"

#include <functional>
#include <unordered_map>
#include <vector>

namespace winrt::UFCase::implementation
{
    // the children of nullptr is the root features
    static std::unordered_map<hstring, std::vector<hstring>> child_models;
    static std::unordered_map<hstring, Isolation::FeatureModel> id_to_models;

    IAsyncActionWithProgress<uint32_t> FeaturesPageViewModel::PullData()
    {
        winrt::apartment_context ui_thread{};
        // switch thread context
        co_await resume_background();

        child_models.clear();

        auto found = Session().FoundationPackage();

        auto report_prog = co_await get_progress_token();
        report_prog(10);

        auto joinUpdates = [](const std::vector<Isolation::FeatureModel> &updates)
            -> IAsyncActionWithProgress<uint32_t> {
            auto report_prog = co_await get_progress_token();

            const uint32_t ENUM_UPDATE_PROG = 30; // 30%
            report_prog(ENUM_UPDATE_PROG);

            // co_await resume_background();

            uint32_t idx = 0, all = static_cast<uint32_t>(updates.size());

            for (auto &update : updates)
            {
                // for debug
                // using namespace std::chrono_literals;
                // co_await 50ms;

                report_prog(ENUM_UPDATE_PROG +
                            uint32_t(std::floor(1.0 * idx / all * (100 - ENUM_UPDATE_PROG))));

                id_to_models.emplace(update.Name(), update);
                auto parents = update.GetParentFeatureCollection().First();
                child_models[parents.HasCurrent() ? parents.Current().Name() : L""].push_back(
                    update.Name());
                idx++;
            }
            co_return;
        };

        std::vector<Isolation::FeatureModel> it1, it2;
        for (auto fm :
             found.GetFeatureCollection(CbsApplicabilityApplicable, CbsSelectabilityRootClass))
            it1.push_back(fm);

        for (auto fm :
             found.GetFeatureCollection(CbsApplicabilityNeedsParent, CbsSelectabilityAllClass))
            it2.push_back(fm);

        auto op1 = joinUpdates(it1), op2 = joinUpdates(it2);
        uint32_t prog1 = 0, prog2 = 0;
        op1.Progress([&](const auto &, const uint32_t &pr) {
            prog1 = pr;
            report_prog(30 + 3 * ((prog1 + prog2) / 2) / 5);
        });
        op2.Progress([&](const auto &, const uint32_t &pr) {
            prog2 = pr;
            report_prog(30 + 3 * ((prog1 + prog2) / 2) / 5);
        });

        co_await op1;
        co_await op2;

        std::function<void(IObservableVector<FeatureViewModel>, Isolation::FeatureModel)> dfs;
        dfs = [&](IObservableVector<FeatureViewModel> child, Isolation::FeatureModel cur) {
            child.Clear();
            for (auto child_name : child_models[cur ? cur.Name() : L""])
            {
                auto child_model = id_to_models.at(child_name);
                FeatureViewModel vm{child_model};
                dfs(vm.Children(), child_model);
                child.Append(vm);
            }
        };

        m_features = multi_threaded_observable_vector<FeatureViewModel>();
        dfs(m_features, 0);
        report_prog(100);

        co_await ui_thread;

        NotifyPropChange(L"RootFeatures");

        co_return;
    }

} // namespace winrt::UFCase::implementation
