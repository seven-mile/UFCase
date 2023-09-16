#include "pch.h"
#include "ComponentViewModel.h"
#if __has_include("ComponentViewModel.g.cpp")
#include "ComponentViewModel.g.cpp"
#endif

#include "csiapi.h"

namespace winrt::UFCase::implementation
{
    ComponentViewModel::ComponentViewModel(Isolation::ComponentModel model) : m_model(model)
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

    hstring ComponentViewModel::NameRaw()
    {
        if (auto name = m_model.GetAttribute(L"Name"); name.empty())
        {
            return L"(unnamed)";
        }
        else
        {
            return name;
        }
    }

    hstring ComponentViewModel::CultureRaw()
    {
        return m_model.GetAttribute(L"Culture");
    }

    hstring ComponentViewModel::VersionRaw()
    {
        return m_model.GetAttribute(L"Version");
    }

    hstring ComponentViewModel::PublicKeyTokenRaw()
    {
        return m_model.GetAttribute(L"PublicKeyToken");
    }

    hstring ComponentViewModel::ProcessorArchitectureRaw()
    {
        return m_model.GetAttribute(L"ProcessorArchitecture");
    }

    hstring ComponentViewModel::VersionScopeRaw()
    {
        return m_model.GetAttribute(L"VersionScope");
    }

    hstring ComponentViewModel::ManifestRaw()
    {
        return m_model.Manifest();
    }

    hstring ComponentViewModel::StatusRaw()
    {
        switch (m_model.Status())
        {
        case Isolation::CsiComponentStatus::Prestaged:
            return L"Prestaged";
        case Isolation::CsiComponentStatus::Staged:
            return L"Staged";
        case Isolation::CsiComponentStatus::Pinned:
            return L"Pinned";
        case Isolation::CsiComponentStatus::Installed:
            return L"Installed";
        case Isolation::CsiComponentStatus::InstalledMismatch:
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

        for (auto f : m_model.GetFileCollection(ISTORE_ENUM_FILES_FLAG_INCLUDE_INSTALLED_FILES))
        {
            result.Append(ComponentFileViewModel{.Name = f.Name,
                                                 .Status = f.Status});
        }

        return result;
    }

} // namespace winrt::UFCase::implementation
