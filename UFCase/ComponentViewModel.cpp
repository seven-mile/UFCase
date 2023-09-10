#include "pch.h"
#include "ComponentViewModel.h"
#if __has_include("ComponentViewModel.g.cpp")
#include "ComponentViewModel.g.cpp"
#endif

#include "csiapi.h"

namespace winrt::UFCase::implementation
{
    ComponentViewModel::ComponentViewModel(uint64_t handle)
        : m_model(ComponentModel::GetInstance(handle))
    {
        Prefetch();
    }

    hstring ComponentViewModel::TextFormRaw()
    {
        return m_model.TextForm();
    }

    hstring ComponentViewModel::KeyFormRaw()
    {
        return m_model.KeyForm();
    }

    hstring ComponentViewModel::ManifestRaw()
    {
        return m_model.Manifest();
    }

    hstring ComponentViewModel::StatusRaw()
    {
        switch (m_model.Status())
        {
        case CSI_COMPONENT_STATUS_PRESTAGED:
            return L"Prestaged";
        case CSI_COMPONENT_STATUS_STAGED:
            return L"Staged";
        case CSI_COMPONENT_STATUS_PINNED:
            return L"Pinned";
        case CSI_COMPONENT_STATUS_INSTALLED_MATCH:
            return L"Installed";
        case CSI_COMPONENT_STATUS_INSTALLED_MISMATCH:
            return L"InstalledMismatch";
        default:
            return L"Unknown";
        }
    }

    hstring ComponentViewModel::PayloadPathRaw()
    {
        return m_model.PayloadPath();
    }

    Collections::IObservableVector<ComponentFileViewModel> ComponentViewModel::FilesRaw()
    {
        auto result = multi_threaded_observable_vector<ComponentFileViewModel>();

        auto flag_to_hstring = [](DWORD file_flag) {
            switch (file_flag)
            {
            case STORE_ASSEMBLY_FILE_STATUS_FLAG_PRESENT:
                return L"Present";
            default:
                return L"Unknown";
            }
        };

        for (auto &f : m_model.Files())
        {
            result.Append(ComponentFileViewModel{.Name = f.pszFileName,
                                                 .Status = flag_to_hstring(f.dwFileStatusFlags)});
        }

        return result;
    }

} // namespace winrt::UFCase::implementation
