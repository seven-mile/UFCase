#include "pch.h"
#include "PackagesPageViewModel.h"
#if __has_include("PackagesPageNavigationContext.g.cpp")
#include "PackagesPageNavigationContext.g.cpp"
#endif
#if __has_include("PackagesPageViewModel.g.cpp")
#include "PackagesPageViewModel.g.cpp"
#endif

#include "IdentityUtil.h"

#include <memory>

namespace winrt::UFCase::implementation
{
    PackagesPageViewModel::PackageRecord *PackagesPageViewModel::FindPackageRecord(
        uint32_t record_id)
    {
        auto it = m_record_index_by_id.find(record_id);
        if (it == m_record_index_by_id.end() || it->second >= m_records.size())
        {
            return nullptr;
        }
        return std::addressof(m_records[it->second]);
    }

    PackagesPageViewModel::PackageRecord *PackagesPageViewModel::FindPackageRecord(
        UFCase::PackageListItem const &item)
    {
        return item ? FindPackageRecord(get_self<PackageListItem>(item)->RecordId()) : nullptr;
    }

    Isolation::PackageModel PackagesPageViewModel::SelectedPackageModel()
    {
        if (!m_selected)
        {
            return nullptr;
        }

        auto record = FindPackageRecord(m_selected);
        return record ? record->Model : nullptr;
    }

    UFCase::PackageDetails PackagesPageViewModel::EnsurePackageDetails(
        UFCase::PackageListItem const &item)
    {
        auto record = FindPackageRecord(item);
        if (!record)
        {
            return nullptr;
        }

        if (!record->Details)
        {
            record->Details = ReadPackageDetailsSnapshot(record->Model);
        }
        return make<PackageDetails>(*record->Details);
    }
    bool PackagesPageViewModel::MatchingPackage(PackageRecord const &record)
    {
        if (!m_nav_ctx)
            return false;

        if (m_nav_ctx.Type() == UFCase::PackagesPageNavigationContextType::SelectPkgStringId)
        {
            return record.Item.Identity() == m_nav_ctx.SelectPkgStringId();
        }
        else if (m_nav_ctx.Type() == UFCase::PackagesPageNavigationContextType::SelectPkgIdentity)
        {
            auto pkg_ident = IdentityUtil::GetIdentityFromPkgKeyForm(record.Item.Identity());
            return IdentityUtil::RoughMatch(pkg_ident, m_nav_ctx.SelectPkgIdentity());
        }
        return false;
    }

    IAsyncActionWithProgress<uint32_t> PackagesPageViewModel::PullData(apartment_context ui_thread)
    {
        auto load_generation = ++m_load_generation;
        m_packages = multi_threaded_observable_vector<UFCase::PackageListItem>();
        m_records.clear();
        m_record_index_by_id.clear();
        m_record_id_by_identity.clear();
        m_selected = {nullptr};
        m_selected_details = {nullptr};

        co_await resume_background();

        switch (m_state)
        {
        case PackagesPageViewModelState::Loading:
            co_return;
        default:
            m_state = PackagesPageViewModelState::Loading;
            break;
        }

        auto report_prog = co_await get_progress_token();
        auto session = m_image.get().OpenSession();
        report_prog(25);

        auto &&pkgs = session.GetPackageCollection(0x70);
        report_prog(50);
        uint32_t cnt = 0;
        uint32_t next_record_id = 1;

        // todo: batching task submissions for better performance
        for (auto pkg : pkgs)
        {
            auto record_id = next_record_id++;
            auto pkg_item = make<PackageListItem>(record_id, ReadPackageListSnapshot(pkg));
            RunUITask([=] {
                if (load_generation == m_load_generation)
                {
                    auto record_index = m_records.size();
                    m_records.push_back(PackageRecord{record_id, pkg_item, pkg, std::nullopt});
                    m_record_index_by_id.emplace(record_id, record_index);
                    m_record_id_by_identity.emplace(std::wstring(pkg_item.Identity().c_str()),
                                                    record_id);
                    m_packages.Append(pkg_item);
                }
            });
            report_prog(static_cast<uint32_t>(50 + 50 * ++cnt / pkgs.Size()));
        }

        co_await ui_thread;
        if (load_generation != m_load_generation)
        {
            co_return;
        }

        NotifyPropChange(L"Packages");
        NotifyPropChange(L"SelectedPackage");
        NotifyPropChange(L"SelectedPackageDetails");

        m_state = PackagesPageViewModelState::Idle;

        co_return;
    }

    fire_and_forget PackagesPageViewModel::Navigate(
        UFCase::PackagesPageNavigationContext const &nav_ctx)
    {
        apartment_context ui_thread{};

        m_nav_ctx = nav_ctx;

        co_await resume_background();

        if (m_state == PackagesPageViewModelState::Uninitialized)
        {
            co_await GlobalRes::MainProgServ().InsertTask(PullData(ui_thread), 100);
        }

        // find the package and select it
        if (m_nav_ctx && m_nav_ctx.Type() != UFCase::PackagesPageNavigationContextType::None)
        {
            UFCase::PackageListItem package_to_select{nullptr};
            if (m_nav_ctx.Type() == UFCase::PackagesPageNavigationContextType::SelectPkgStringId)
            {
                auto it = m_record_id_by_identity.find(
                    std::wstring(m_nav_ctx.SelectPkgStringId().c_str()));
                if (it != m_record_id_by_identity.end())
                {
                    if (auto record = FindPackageRecord(it->second))
                    {
                        package_to_select = record->Item;
                    }
                }
            }
            else
            {
                for (auto const &record : m_records)
                {
                    if (MatchingPackage(record))
                    {
                        package_to_select = record.Item;
                        break;
                    }
                }
            }
            co_await ui_thread;
            SelectedPackage(package_to_select);
        }

        Navigated.invoke(*this, m_nav_ctx);

        co_return;
    }

} // namespace winrt::UFCase::implementation
