#include "pch.h"
#include "ImageSelectorHelper.h"

#include "ImageModel.h"
#include "ImageViewModel.h"

#include "PathUtil.h"
#include "AsyncUtil.h"

#include <wil/resource.h>

#include <unordered_set>
#include <mutex>

namespace winrt::UFCase
{

    using list_t = IObservableVector<ImageViewModel>;

    static std::unordered_set<ImageModel *> model_set;
    static std::mutex model_set_mutex;
    static list_t result_list;

    IAsyncActionWithProgress<uint32_t> SearchOnlineImage(ImageViewModel &result)
    {
        auto report_prog = co_await winrt::get_progress_token();
        constexpr int MAX_PROG = 10;

        auto image = ImageModel::Create(GetOnlineBootdrive());
        result = ImageViewModel{image->GetHandle()};
        report_prog(MAX_PROG / 2);

        auto inner = get_self<implementation::ImageViewModel>(result);
        co_await RunUITaskAsync([&]() -> IAsyncAction { co_await inner->PullData(); });
        report_prog(MAX_PROG);

        co_return;
    }

    IAsyncActionWithProgress<uint32_t> SearchMountedImage(list_t result)
    {
        auto report_prog = co_await winrt::get_progress_token();
        constexpr int MAX_PROG = 45;

        // admin needed
        if (!IsUserAnAdmin())
        {
            report_prog(MAX_PROG);
            co_return;
        }

        wil::unique_hkey hkeyImgList;
        try
        {
            winrt::check_win32(::RegOpenKey(HKEY_LOCAL_MACHINE,
                                            L"SOFTWARE\\Microsoft\\WIMMount\\Mounted Images",
                                            wil::out_param(hkeyImgList)));
        }
        catch (winrt::hresult_error const &)
        {
            // No image mounted ever
            co_return;
        }
        // the name is a guid, so the length is fixed
        const int GUID_LENGTH = 36;
        wchar_t nameGuid[GUID_LENGTH + 1];

        DWORD cImages;
        winrt::check_win32(::RegQueryInfoKey(hkeyImgList.get(), nullptr, nullptr, nullptr, &cImages,
                                             nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                             nullptr));

        for (DWORD dwIndex = 0; dwIndex < cImages; dwIndex++)
        {
            auto code = ::RegEnumKey(hkeyImgList.get(), 0, nameGuid, _countof(nameGuid));
            // if (code == ERROR_NO_MORE_ITEMS) break;
            winrt::check_win32(code);
            // wil::unique_hkey hkeyCurImg;
            // RegOpenKey(hkeyImgList.get(), nameGuid, wil::out_param(hkeyCurImg));
            wchar_t pathMount[MAX_PATH];
            DWORD dwType{}, cbData{};
            winrt::check_win32(::RegGetValue(hkeyImgList.get(), nameGuid, L"Mount Path", NULL,
                                             &dwType, pathMount, &cbData));
            auto image = ImageModel::Create(pathMount);
            if (std::scoped_lock lock{model_set_mutex}; !model_set.count(image))
            {
                model_set.insert(image);
                result.Append(ImageViewModel{image->GetHandle()});
            }
            report_prog(MAX_PROG * (dwIndex + 1) / cImages);
        }
        co_return;
    }

    IAsyncActionWithProgress<uint32_t> SearchOfflineImages(list_t result)
    {
        auto report_prog = co_await winrt::get_progress_token();
        constexpr int MAX_PROG = 45;

        // admin needed
        if (!IsUserAnAdmin())
        {
            report_prog(MAX_PROG);
            co_return;
        }

        auto ensure_bootdrive = [](std::filesystem::path path) -> bool {
            return std::filesystem::exists(path) && std::filesystem::exists(path / L"Windows");
        };

        std::wstring bootdrive = L"A:";
        for (auto &ch = bootdrive[0]; ch <= L'Z'; ch++)
        {
            if (ensure_bootdrive(bootdrive))
            {
                auto image = ImageModel::Create(bootdrive);
                if (std::scoped_lock lock{model_set_mutex}; !model_set.count(image))
                {
                    model_set.insert(image);
                    result.Append(ImageViewModel{image->GetHandle()});
                }
            }
            report_prog(MAX_PROG * (ch - L'A' + 1) / 26);
        }
        co_return;
    }

    IAsyncActionWithProgress<uint32_t> SearchImages()
    {
        if (result_list)
            co_return;

        model_set.clear();
        result_list = multi_threaded_observable_vector<ImageViewModel>();

        auto report_prog = co_await winrt::get_progress_token();

        // Online part
        ImageViewModel online_vm{nullptr};
        auto op_online = SearchOnlineImage(online_vm);
        auto op_mounted = SearchMountedImage(result_list);
        auto op_offline = SearchOfflineImages(result_list);
        uint32_t prog_online = 0, prog_mounted = 0, prog_offline = 0;

        op_online.Progress([&](auto &, uint32_t prog) {
            prog_online = prog;
            report_prog(prog_online + prog_mounted + prog_offline);
        });
        op_mounted.Progress([&](auto &, uint32_t prog) {
            prog_mounted = prog;
            report_prog(prog_online + prog_mounted + prog_offline);
        });
        op_offline.Progress([&](auto &, uint32_t prog) {
            prog_offline = prog;
            report_prog(prog_online + prog_mounted + prog_offline);
        });

        co_await op_online;
        result_list.InsertAt(0, online_vm);

        co_await op_mounted;
        co_await op_offline;

        report_prog(100);

        co_return;
    }

    list_t GetImageSearchResult()
    {
        assert(result_list);
        return result_list;
    }

} // namespace winrt::UFCase
