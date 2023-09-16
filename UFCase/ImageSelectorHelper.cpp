#include "pch.h"
#include "ImageSelectorHelper.h"

#include "HostManager.h"

#include "ImageViewModel.h"

#include "PathUtil.h"
#include "AsyncUtil.h"

#include <wil/resource.h>

#include <unordered_set>
#include <mutex>

namespace winrt::UFCase
{

    using list_t = IObservableVector<ImageViewModel>;

    static std::unordered_set<Isolation::ImageModel> model_set;

    static IAsyncAction ImagePullData(ImageViewModel vm)
    {
        auto inner = get_self<implementation::ImageViewModel>(vm);
        co_await RunUITaskAsync([&]() -> IAsyncAction { co_await inner->PullData(); });
    }

    static Isolation::Host GetOrStartHost(std::filesystem::path const &bootdrive)
    {
        Isolation::HostManagerSingleton sg{};
        auto mgr_ref = sg.Current();
        auto mgr = get_self<Isolation::implementation::HostManager>(mgr_ref);
        return mgr->GetOrStartHost(bootdrive);
    }

    IAsyncActionWithProgress<hstring> SearchOnlineImage(ImageViewModel &vm)
    {
        auto report_prog = co_await winrt::get_progress_token();

        auto bootdrive = GetOnlineBootdrive();
        report_prog(std::format(L"Initializing online image [{}]", bootdrive.c_str()).c_str());

        auto online_host = GetOrStartHost(bootdrive);
        auto image = online_host.Image();
        model_set.insert(image);
        vm = UFCase::ImageViewModel{image};

        report_prog(L"Loading information of online image");
        co_await ImagePullData(vm);

        co_return;
    }

    IAsyncActionWithProgress<hstring> SearchMountedImage(list_t result)
    {
        auto report_prog = co_await winrt::get_progress_token();

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
            std::filesystem::path bootdrive = pathMount;
            if (!std::filesystem::exists(bootdrive))
            {
                continue;
            }
            report_prog(L"Initializing mounted image");

            auto host = GetOrStartHost(bootdrive);
            auto image = host.Image();
            if (!model_set.count(image))
            {
                model_set.insert(image);
                ImageViewModel vm{image};
                report_prog(
                    std::format(L"Loading information of mounted image [{}]", pathMount).c_str());
                co_await ImagePullData(vm);
                result.Append(vm);
            }
        }
        co_return;
    }

    IAsyncActionWithProgress<hstring> SearchOfflineImages(list_t result)
    {
        auto report_prog = co_await winrt::get_progress_token();

        auto ensure_bootdrive = [](std::filesystem::path path) -> bool {
            return std::filesystem::exists(path) && std::filesystem::exists(path / L"Windows");
        };

        std::wstring bootdrive = L"A:\\";
        for (auto &ch = bootdrive[0]; ch <= L'Z'; ch++)
        {
            report_prog(std::format(L"Initializing offline image [{}]", bootdrive).c_str());
            if (ensure_bootdrive(bootdrive))
            {
                auto host = GetOrStartHost(bootdrive);
                auto image = host.Image();
                if (!model_set.count(image))
                {
                    model_set.insert(image);
                    ImageViewModel vm{image};

                    report_prog(
                        std::format(L"Loading information of offline image [{}]", bootdrive.c_str())
                            .c_str());
                    co_await ImagePullData(vm);

                    result.Append(vm);
                }
            }
        }
        co_return;
    }

    IAsyncOperationWithProgress<list_t, hstring> SearchImages()
    {
        auto result_list = multi_threaded_observable_vector<ImageViewModel>();

        model_set.clear();

        auto report_prog = co_await winrt::get_progress_token();

        ImageViewModel online_vm{nullptr};

        auto forward_progress = [&](auto const &op) {
            op.Progress([&](auto &, auto prog) { report_prog(prog); });
            return op;
        };

        co_await forward_progress(SearchOnlineImage(online_vm));
        result_list.InsertAt(0, online_vm);

        co_await forward_progress(SearchMountedImage(result_list));
        co_await forward_progress(SearchOfflineImages(result_list));

        co_return result_list;
    }

} // namespace winrt::UFCase
