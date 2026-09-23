#include "pch.h"
#include "FeaturesPageViewModel.h"
#if __has_include("FeaturesPageViewModel.g.cpp")
#include "FeaturesPageViewModel.g.cpp"
#endif

#include "CbsApi.h"

#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

namespace winrt::UFCase::implementation
{
    FeaturesPageViewModel::FeatureRecord *FeaturesPageViewModel::FindFeatureRecord(
        uint32_t record_id)
    {
        auto it = m_record_index_by_id.find(record_id);
        if (it == m_record_index_by_id.end() || it->second >= m_records.size())
        {
            return nullptr;
        }
        return std::addressof(m_records[it->second]);
    }

    FeaturesPageViewModel::FeatureRecord *FeaturesPageViewModel::FindFeatureRecord(
        UFCase::FeatureTreeItem const &item)
    {
        return item ? FindFeatureRecord(get_self<FeatureTreeItem>(item)->RecordId()) : nullptr;
    }

    FeaturesPageViewModel::FeatureRecord *FeaturesPageViewModel::SelectedFeatureRecord()
    {
        return FindFeatureRecord(m_selected);
    }

    fire_and_forget FeaturesPageViewModel::LoadSelectedFeatureDetails(
        UFCase::FeatureTreeItem item, uint64_t details_generation)
    {
        auto lifetime{get_strong()};
        auto record = FindFeatureRecord(item);
        if (!record)
        {
            co_return;
        }

        auto record_id = record->RecordId;
        auto model = record->Model;
        if (record->Details)
        {
            m_selected_details = make<FeatureDetails>(*record->Details);
            NotifyPropChange(L"SelectedFeatureDetails");
            NotifyCommandsCanExecuteChanged();
            co_return;
        }

        apartment_context ui_thread{};
        co_await resume_background();
        std::optional<FeatureDetailsSnapshot> details;
        try
        {
            details = ReadFeatureDetailsSnapshot(model);
        }
        catch (hresult_error const &error)
        {
            OutputDebugString(winrt::format(L"failed to load feature details: 0x{:08X}\n",
                                            static_cast<uint32_t>(error.code()))
                                  .c_str());
        }
        catch (...)
        {
            OutputDebugString(L"failed to load feature details\n");
        }

        co_await ui_thread;
        if (!details || details_generation != m_details_generation || !m_selected ||
            get_self<FeatureTreeItem>(m_selected)->RecordId() != record_id)
        {
            co_return;
        }

        if (auto current_record = FindFeatureRecord(record_id))
        {
            current_record->Details = std::move(details);
            m_selected_details = make<FeatureDetails>(*current_record->Details);
            NotifyPropChange(L"SelectedFeatureDetails");
            NotifyCommandsCanExecuteChanged();
        }
    }

    void FeaturesPageViewModel::RefreshFeatureRecord(FeatureRecord &record)
    {
        get_self<FeatureTreeItem>(record.Item)->UpdateSnapshot(
            ReadFeatureTreeItemSnapshot(record.Model));
        record.Details.reset();
        if (m_selected && get_self<FeatureTreeItem>(m_selected)->RecordId() == record.RecordId)
        {
            m_selected_details = nullptr;
            auto details_generation = ++m_details_generation;
            NotifyPropChange(L"SelectedFeatureDetails");
            NotifyCommandsCanExecuteChanged();
            LoadSelectedFeatureDetails(record.Item, details_generation);
        }
    }

    IAsyncActionWithProgress<uint32_t> FeaturesPageViewModel::PullData()
    {
        auto lifetime{get_strong()};
        winrt::apartment_context ui_thread{};

        co_await resume_background();

        switch (m_state)
        {
        case FeaturesPageViewModelState::Loading:
            co_return;
        default:
            m_state = FeaturesPageViewModelState::Loading;
            break;
        }

        auto report_progress = co_await get_progress_token();
        auto load_generation = ++m_load_generation;
        report_progress(10);

        auto foundation = Session().FoundationPackage();

        std::vector<Isolation::FeatureModel> roots;
        std::vector<Isolation::FeatureModel> children;
        for (auto feature :
             foundation.GetFeatureCollection(CbsApplicabilityApplicable, CbsSelectabilityRootClass))
        {
            roots.push_back(feature);
        }
        report_progress(30);

        for (auto feature :
             foundation.GetFeatureCollection(CbsApplicabilityNeedsParent, CbsSelectabilityAllClass))
        {
            children.push_back(feature);
        }
        report_progress(50);

        std::unordered_map<std::wstring, Isolation::FeatureModel> model_by_name;
        std::unordered_map<std::wstring, std::vector<std::wstring>> children_by_parent;

        auto add_feature = [&](Isolation::FeatureModel const &feature) {
            auto name = std::wstring(feature.Name().c_str());
            model_by_name.emplace(name, feature);

            auto parents = feature.GetParentFeatureCollection().First();
            auto parent_name = parents.HasCurrent()
                                   ? std::wstring(parents.Current().Name().c_str())
                                   : std::wstring{};
            children_by_parent[parent_name].push_back(name);
        };

        for (auto const &feature : roots)
        {
            add_feature(feature);
        }
        for (auto const &feature : children)
        {
            add_feature(feature);
        }
        report_progress(70);

        auto new_root_features = multi_threaded_observable_vector<UFCase::FeatureTreeItem>();
        std::vector<FeatureRecord> new_records;
        std::unordered_map<uint32_t, size_t> new_record_index_by_id;
        std::unordered_map<std::wstring, uint32_t> new_record_id_by_name;
        uint32_t next_record_id = 1;

        std::function<UFCase::FeatureTreeItem(std::wstring const &, uint32_t)> build_feature;
        build_feature = [&](std::wstring const &name,
                            uint32_t parent_record_id) -> UFCase::FeatureTreeItem {
            auto model = model_by_name.at(name);
            auto record_id = next_record_id++;
            auto item = make<FeatureTreeItem>(record_id, ReadFeatureTreeItemSnapshot(model));
            auto record_index = new_records.size();
            new_records.push_back(
                FeatureRecord{record_id, item, model, parent_record_id, {}, std::nullopt});
            new_record_index_by_id.emplace(record_id, record_index);
            new_record_id_by_name.emplace(name, record_id);

            for (auto const &child_name : children_by_parent[name])
            {
                auto child_item = build_feature(child_name, record_id);
                auto child_record_id = get_self<FeatureTreeItem>(child_item)->RecordId();
                new_records[record_index].ChildRecordIds.push_back(child_record_id);
                item.Children().Append(child_item);
            }
            return item;
        };

        for (auto const &root_name : children_by_parent[std::wstring{}])
        {
            new_root_features.Append(build_feature(root_name, 0));
        }
        report_progress(90);

        co_await ui_thread;
        if (load_generation != m_load_generation)
        {
            co_return;
        }

        m_features = new_root_features;
        m_records = std::move(new_records);
        m_record_index_by_id = std::move(new_record_index_by_id);
        m_record_id_by_name = std::move(new_record_id_by_name);
        m_selected = nullptr;
        m_selected_details = nullptr;
        ++m_details_generation;

        m_state = FeaturesPageViewModelState::Idle;
        NotifyPropChange(L"RootFeatures");
        NotifyPropChange(L"SelectedFeature");
        NotifyPropChange(L"SelectedFeatureDetails");
        NotifyCommandsCanExecuteChanged();

        report_progress(100);
        co_return;
    }
} // namespace winrt::UFCase::implementation
