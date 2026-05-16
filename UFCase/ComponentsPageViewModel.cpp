#include "pch.h"
#include "ComponentsPageViewModel.h"
#if __has_include("ComponentsPageNavigationContext.g.cpp")
#include "ComponentsPageNavigationContext.g.cpp"
#endif
#if __has_include("ComponentsPageViewModel.g.cpp")
#include "ComponentsPageViewModel.g.cpp"
#endif

#include <winrt/UFCase.Isolation.h>

#include "AsyncUtil.h"
#include "IdentityUtil.h"

#include <memory>

namespace winrt::UFCase::implementation
{
    ComponentsPageViewModel::ComponentsPageViewModel(UFCase::ImageViewModel image) : m_image(image)
    {
        m_components = multi_threaded_observable_vector<UFCase::ComponentListItem>();
    }

    ComponentsPageViewModel::ComponentRecord *ComponentsPageViewModel::FindComponentRecord(
        uint32_t record_id)
    {
        auto it = m_record_index_by_id.find(record_id);
        if (it == m_record_index_by_id.end() || it->second >= m_records.size())
        {
            return nullptr;
        }
        return std::addressof(m_records[it->second]);
    }

    ComponentsPageViewModel::ComponentRecord *ComponentsPageViewModel::FindComponentRecord(
        UFCase::ComponentListItem const &item)
    {
        return item ? FindComponentRecord(get_self<ComponentListItem>(item)->RecordId()) : nullptr;
    }

    Isolation::ComponentModel ComponentsPageViewModel::SelectedComponentModel()
    {
        if (!m_selected)
        {
            return nullptr;
        }

        auto record = FindComponentRecord(m_selected);
        return record ? record->Model : nullptr;
    }

    UFCase::ComponentDetails ComponentsPageViewModel::EnsureComponentDetails(
        UFCase::ComponentListItem const &item)
    {
        auto record = FindComponentRecord(item);
        if (!record)
        {
            return nullptr;
        }

        if (!record->Details)
        {
            record->Details = ReadComponentDetailsSnapshot(record->Model);
        }
        return make<ComponentDetails>(*record->Details);
    }

    void ComponentsPageViewModel::SelectComponentByIndex(int32_t index)
    {
        m_selected_index = index;
        if (index < 0 || static_cast<size_t>(index) >= m_records.size())
        {
            SelectedComponent(nullptr);
        }
        else
        {
            SelectedComponent(m_records[index].Item);
        }
        NotifyPropChange(L"SelectedComponentIndex");
    }

    bool ComponentsPageViewModel::MatchingComponent(ComponentRecord const &record)
    {
        if (m_nav_ctx.Type() == ComponentsPageNavigationContextType::SelectCompId)
        {
            return record.Item.Name() == m_nav_ctx.SelectCompId();
        }
        else if (m_nav_ctx.Type() == ComponentsPageNavigationContextType::SelectCompIdentity)
        {
            UFCase::Identity comp_ident;
            comp_ident.Name(IdentityUtil::MapIdentityValue(record.Item.Name()));
            comp_ident.Version(IdentityUtil::MapIdentityValue(record.Item.Version()));
            comp_ident.PublicKeyToken(IdentityUtil::MapIdentityValue(record.Item.PublicKeyToken()));
            comp_ident.ProcessorArchitecture(
                IdentityUtil::MapIdentityValue(record.Item.ProcessorArchitecture()));
            comp_ident.Culture(IdentityUtil::MapIdentityValue(record.Item.Culture()));
            return IdentityUtil::RoughMatch(comp_ident, m_nav_ctx.SelectCompIdentity());
        }
        return false;
    }

    IAsyncActionWithProgress<uint32_t> ComponentsPageViewModel::PullData(
        apartment_context ui_thread)
    {
        auto lifetime{get_strong()};

        co_await resume_background();

        switch (m_state)
        {
        case ComponentsPageViewModelState::Loading:
            co_return;
        default:
            m_state = ComponentsPageViewModelState::Loading;
            break;
        }

        auto report_progress = co_await get_progress_token();
        auto load_generation = ++m_load_generation;

        m_components.Clear();
        m_records.clear();
        m_record_index_by_id.clear();
        m_record_id_by_name.clear();
        m_selected = nullptr;
        m_selected_index = -1;
        m_selected_details = nullptr;

        auto store = m_image.get().Store();

        auto comps = store.GetComponentCollection();

        // if no reference restriction, estimate 15000 components
        // if there is reference restriction, this should be fast enough
        // and do not need a progress bar
        SIZE_T comps_count = 15000;

        bool matched_flag = false;
        uint32_t next_record_id = 1;
        for (SIZE_T idx = 0; auto comp_ : comps)
        {
            auto comp = comp_.as<Isolation::ComponentModel>();
            auto record_id = next_record_id++;
            auto comp_vm = make<ComponentListItem>(record_id, ReadComponentListSnapshot(comp));
            // todo: batching for better performance
            ComponentRecord record{record_id, comp_vm, comp, std::nullopt};
            if (MatchingComponent(record))
            {
                RunUITask([=, lifetime = lifetime] {
                    if (load_generation != m_load_generation)
                    {
                        return;
                    }
                    auto record_index = m_records.size();
                    m_records.push_back(record);
                    m_record_index_by_id.emplace(record.RecordId, record_index);
                    m_record_id_by_name.emplace(std::wstring(record.Item.Name().c_str()),
                                                record.RecordId);
                    // todo: fix the selection bug
                    // reference: https://stackoverflow.com/questions/12108464/let-listview-scroll-to-selected-item
                    // also: oneway / twoway binding bizarre
                    m_components.Append(comp_vm);
                    SelectComponentByIndex(static_cast<int32_t>(record_index));
                    Navigated.invoke(*this, m_nav_ctx);
                });
                matched_flag = true;
            }
            else
            {
                RunUITask([=, lifetime = lifetime] {
                    if (load_generation == m_load_generation)
                    {
                        auto record_index = m_records.size();
                        m_records.push_back(record);
                        m_record_index_by_id.emplace(record.RecordId, record_index);
                        m_record_id_by_name.emplace(std::wstring(record.Item.Name().c_str()),
                                                    record.RecordId);
                        m_components.Append(comp_vm);
                    }
                });
            }

            ++idx;
            if (idx <= comps_count)
            {
                report_progress(static_cast<uint32_t>(idx * 100 / comps_count));
            }
        }

        co_await ui_thread;
        if (load_generation != m_load_generation)
        {
            co_return;
        }

        NotifyPropChange(L"Components");
        NotifyPropChange(L"SelectedComponentIndex");
        NotifyPropChange(L"SelectedComponentDetails");

        report_progress(100);

        if (!matched_flag)
        {
            m_selected = nullptr;
            m_selected_index = -1;
            m_selected_details = nullptr;
            NotifyPropChange(L"SelectedComponentIndex");
            NotifyPropChange(L"SelectedComponentDetails");
            Navigated.invoke(*this, m_nav_ctx);
        }

        m_state = ComponentsPageViewModelState::Idle;

        co_return;
    }

    fire_and_forget ComponentsPageViewModel::Navigate(
        UFCase::ComponentsPageNavigationContext const &nav_ctx)
    {
        apartment_context ui_thread{};

        m_nav_ctx = nav_ctx;

        co_await resume_background();

        if (m_state == ComponentsPageViewModelState::Uninitialized)
        {
            co_await GlobalRes::MainProgServ().InsertTask(PullData(ui_thread), 100);
        }
        else
        {
            // find the component and select it
            if (m_nav_ctx && m_nav_ctx.Type() != UFCase::ComponentsPageNavigationContextType::None)
            {
                int32_t component_index_to_select{-1};
                if (m_nav_ctx.Type() == ComponentsPageNavigationContextType::SelectCompId)
                {
                    auto it = m_record_id_by_name.find(
                        std::wstring(m_nav_ctx.SelectCompId().c_str()));
                    if (it != m_record_id_by_name.end())
                    {
                        auto index_it = m_record_index_by_id.find(it->second);
                        if (index_it != m_record_index_by_id.end())
                        {
                            component_index_to_select = static_cast<int32_t>(index_it->second);
                        }
                    }
                }
                else
                {
                    for (size_t record_index = 0; record_index < m_records.size(); ++record_index)
                    {
                        auto const &record = m_records[record_index];
                        if (MatchingComponent(record))
                        {
                            component_index_to_select = static_cast<int32_t>(record_index);
                            break;
                        }
                    }
                }
                co_await ui_thread;
                SelectComponentByIndex(component_index_to_select);
                Navigated.invoke(*this, m_nav_ctx);
            }
        }

        co_return;
    }

} // namespace winrt::UFCase::implementation
