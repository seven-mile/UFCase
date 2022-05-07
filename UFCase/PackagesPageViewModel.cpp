#include "pch.h"
#include "PackagesPageViewModel.h"
#if __has_include("PackagesPageViewModel.g.cpp")
#include "PackagesPageViewModel.g.cpp"
#endif

#include "SessionModel.h"
#include "PackageModel.h"
#include "PackageViewModel.g.h"

namespace winrt::UFCase::implementation
{
    IAsyncActionWithProgress<uint32_t> PackagesPageViewModel::PullData()
    {
        apartment_context ui_thread{};
        m_packages = multi_threaded_observable_vector<UFCase::PackageViewModel>();

        co_await resume_background();

        auto report_prog = co_await get_progress_token();
        auto& session = SessionModel::GetInstance(m_image.OpenSession());
        report_prog(30);

        auto&& pkgs = session.Packages();
        report_prog(70);
        uint32_t cnt = 0;
        
        co_await ui_thread;

        for (auto&& pkg : pkgs) {
            m_packages.Append(UFCase::PackageViewModel(pkg->GetHandle()));
            report_prog(static_cast<uint32_t>(70 + 30 * ++cnt / pkgs.size()));
        }

        m_property_changed(*this, Data::PropertyChangedEventArgs{ L"Packages" });

        co_return;
    }
}
