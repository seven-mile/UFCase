#pragma once

#include "PackagesPageNavigationContext.g.h"
#include "PackagesPageViewModel.g.h"

#include <winrt/Windows.Storage.h>
#include <winrt/Microsoft.UI.Xaml.Documents.h>
#include <winrt/UFCase.Isolation.h>

#include "XamlUtil.h"
#include "PropChgUtil.h"

#include <ShlObj.h>

#include <fstream>
#include <filesystem>
#include <wil/stl.h>

namespace winrt::UFCase::implementation
{

    struct PackagesPageNavigationContext
        : PackagesPageNavigationContextT<PackagesPageNavigationContext>
    {
        PackagesPageNavigationContext() = default;

        static UFCase::PackagesPageNavigationContext GetFromId(hstring const &val)
        {
            auto res = UFCase::PackagesPageNavigationContext();
            res.Type(PackagesPageNavigationContextType::SelectPkgStringId);
            res.SelectPkgStringId(val);
            return res;
        }

        static UFCase::PackagesPageNavigationContext GetFromIdentity(UFCase::Identity const &val)
        {
            auto res = UFCase::PackagesPageNavigationContext();
            res.Type(PackagesPageNavigationContextType::SelectPkgIdentity);
            res.SelectPkgIdentity(val);
            return res;
        }

        PackagesPageNavigationContextType Type()
        {
            return m_type;
        }

        void Type(PackagesPageNavigationContextType const &value)
        {
            m_type = value;
        }

        hstring SelectPkgStringId()
        {
            return m_sel_pkg;
        }

        void SelectPkgStringId(hstring value)
        {
            m_sel_pkg = value;
        }

        UFCase::Identity SelectPkgIdentity()
        {
            return m_sel_pkg_identity;
        }

        void SelectPkgIdentity(UFCase::Identity value)
        {
            m_sel_pkg_identity = value;
        }

        hstring m_sel_pkg;
        UFCase::Identity m_sel_pkg_identity;
        PackagesPageNavigationContextType m_type = PackagesPageNavigationContextType::None;
    };

    struct PackagesPageViewModel : PackagesPageViewModelT<PackagesPageViewModel>,
                                   ImplPropertyChangedT<PackagesPageViewModel>
    {
        PackagesPageViewModel(UFCase::ImageViewModel image) : m_image(image)
        {
        }

        PackagesPageViewModel(UFCase::ImageViewModel image,
                              UFCase::PackagesPageNavigationContext nav_ctx)
            : m_image(image), m_nav_ctx(nav_ctx)
        {
        }

        PackagesPageViewModelState State()
        {
            return m_state;
        }

        UFCase::ImageViewModel Image()
        {
            return m_image.get();
        }

        IObservableVector<UFCase::PackageViewModel> Packages()
        {
            return m_packages;
        }

        UFCase::PackageViewModel SelectedPackage()
        {
            return m_selected;
        }

        void SelectedPackage(UFCase::PackageViewModel value)
        {
            m_selected = value;
            NotifyPropChange(L"SelectedPackage");
        }

        UFCase::PackagesPageNavigationContext NavContext()
        {
            return m_nav_ctx;
        }

        void NavContext(UFCase::PackagesPageNavigationContext value)
        {
            m_nav_ctx = value;
        }

        IAsyncActionWithProgress<uint32_t> PullData(bool is_nav = true);

        HandleCommandAsync(PackageShowManifest)
        {
            if (!m_selected)
                co_return;

            auto m_model = m_selected.Model();

            if (!GlobalRes::WindowServ().TryActivateWindow(m_model))
            {
                UFCase::PackageManifestViewerWindowViewModel vm{m_model};
                UFCase::PackageManifestViewerWindow wnd{vm};

                GlobalRes::WindowServ().RegisterWindow(m_model, wnd);

                wnd.Closed(
                    [=](auto &&, auto &&) { GlobalRes::WindowServ().UnregisterWindow(m_model); });

                wnd.Activate();
            }
        }

        HandleCommand(PackageShowInFileExplorer)
        {
            if (!m_selected)
            {
                return;
            }

#pragma warning(push)
#pragma warning(disable : 4090)
            if (ITEMIDLIST *pidl = ILCreateFromPath(m_selected.ManifestFilePath().c_str()))
            {
                LOG_IF_FAILED(SHOpenFolderAndSelectItems(pidl, 0, 0, 0));
                ILFree(pidl);
            }
#pragma warning(pop)
        }

        HandleCommand(PackageShowInRegistry)
        {
            if (!m_selected)
            {
                return;
            }

            ::RegSetKeyValue(HKEY_CURRENT_USER,
                             L"Software\\Microsoft\\Windows\\CurrentVersion\\Applets\\Regedit",
                             L"LastKey", REG_SZ, m_selected.RegistryPath().c_str(),
                             (m_selected.RegistryPath().size() + 1) * sizeof(wchar_t));

            ::ShellExecute(nullptr, L"open", L"regedit", L"", L"", SW_SHOW);
            LOG_IF_FAILED(HRESULT_FROM_WIN32(GetLastError()));
        }

      private:
        PackagesPageViewModelState m_state{PackagesPageViewModelState::Uninitialized};
        weak_ref<UFCase::ImageViewModel> m_image{nullptr};
        IObservableVector<UFCase::PackageViewModel> m_packages{nullptr};
        UFCase::PackageViewModel m_selected{nullptr};
        UFCase::PackagesPageNavigationContext m_nav_ctx;
    };

} // namespace winrt::UFCase::implementation

namespace winrt::UFCase::factory_implementation
{
    struct PackagesPageViewModel
        : PackagesPageViewModelT<PackagesPageViewModel, implementation::PackagesPageViewModel>
    {
    };

    struct PackagesPageNavigationContext
        : PackagesPageNavigationContextT<PackagesPageNavigationContext,
                                         implementation::PackagesPageNavigationContext>
    {
    };
} // namespace winrt::UFCase::factory_implementation
