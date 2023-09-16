#include "pch.h"
#include "ComponentModel.h"
#if __has_include("ComponentModel.g.cpp")
#include "ComponentModel.g.cpp"
#endif

#include "Utils/CbsUtil.h"

#include "StoreModel.h"

namespace winrt::UFCase::Isolation::implementation
{
    ComponentModel::ComponentModel(Isolation::StoreModel store, com_ptr<IDefinitionIdentity> asm_id)

        : m_store(get_self<implementation::StoreModel>(store)), m_asm_id(asm_id)
    {
    }

    hstring ComponentModel::GetAttribute(hstring ns, hstring attr)
    {
        wil::unique_cotaskmem_string result;
        check_hresult(m_asm_id->GetAttribute(ns.c_str(), attr.c_str(), result.put()));
        return result.get();
    }

    hstring ComponentModel::GetAttribute(hstring attr)
    {
        return GetAttribute(L"", attr);
    }

    hstring ComponentModel::TextForm()
    {
        wil::unique_cotaskmem_string result;
        check_hresult(m_store->m_ident_auth->DefinitionToText(0, m_asm_id.get(), result.put()));
        return result.get();
    }

    hstring ComponentModel::KeyForm()
    {
        wil::unique_cotaskmem_string result;
        check_hresult(
            m_store->m_ident_auth->GenerateDefinitionKey(0, m_asm_id.get(), result.put()));
        return result.get();
    }

    hstring ComponentModel::Manifest()
    {
        com_ptr<::IUnknown> pTManifestRaw;
        IDefinitionIdentity *def_idents[] = {m_asm_id.get()};
        winrt::check_hresult(m_store->m_csi_store->GetComponentManifests(
            0, 1, def_idents, __uuidof(IStream), pTManifestRaw.put()));
        auto pStream = pTManifestRaw.as<IStream>();

        // stream to ascii text
        LARGE_INTEGER pos;
        ULARGE_INTEGER size;
        pos.QuadPart = 0;
        winrt::check_hresult(pStream->Seek(pos, STREAM_SEEK_END, &size));
        winrt::check_hresult(pStream->Seek(pos, STREAM_SEEK_SET, nullptr));

        std::vector<char> buf;
        buf.resize(size.QuadPart);
        ULONG read = 0;
        winrt::check_hresult(pStream->Read(buf.data(), (ULONG)buf.size(), &read));

        const int cchBuffer =
            MultiByteToWideChar(CP_UTF8, 0, buf.data(), static_cast<int>(buf.size()), nullptr, 0);
        // null termination
        auto bufferw = std::make_unique<wchar_t[]>(cchBuffer + 1);
        [[maybe_unused]] const int ret = MultiByteToWideChar(
            CP_UTF8, 0, buf.data(), static_cast<int>(buf.size()), bufferw.get(), cchBuffer);

        assert(ret == cchBuffer);
        check_win32(GetLastError());

        return bufferw.get();
    }

    CsiComponentStatus ComponentModel::Status()
    {
        CSI_COMPONENT_BASIC_INFORMATION basicInfo{sizeof(basicInfo)};
        check_hresult(m_store->m_csi_store->GetComponentInformation(
            0, ICSISTORE_GET_COMPONENT_INFORMATION_CLASS_BASIC, m_asm_id.get(), sizeof(basicInfo),
            &basicInfo));
        return static_cast<CsiComponentStatus>(basicInfo.dwCsiStatus);
    }

    hstring ComponentModel::PayloadPath()
    {
        CSI_COMPONENT_PAYLOAD_INFORMATION payloadInfo{sizeof(payloadInfo)};

        // optional flag: ISTORE_LOCK_ASSEMBLY_PATH_FLAG_NOT_FOUND_RETURNS_NULL
        auto hr = (m_store->m_csi_store->GetComponentInformation(
            0, ICSISTORE_GET_COMPONENT_INFORMATION_CLASS_PAYLOAD, m_asm_id.get(),
            sizeof(payloadInfo), &payloadInfo));
        if (FAILED(hr))
        {
            return L"NOTIMPL";
        }
        com_ptr<::IUnknown> component_lock;
        component_lock.attach(payloadInfo.pComponentLock);
        return payloadInfo.pszPayloadRoot;
    }

    Windows::Foundation::Collections::IVector<ComponentFileModel> ComponentModel::GetFileCollection(
        DWORD dwFlag)
    {
        auto result = single_threaded_vector<ComponentFileModel>();

        com_ptr<::IUnknown> pFilesRaw;
        check_hresult(m_store->m_sxs_store->EnumFiles(
            dwFlag, m_asm_id.get(), __uuidof(IEnumSTORE_ASSEMBLY_FILE), pFilesRaw.put()));
        auto pFiles = pFilesRaw.as<IEnumSTORE_ASSEMBLY_FILE>();

        auto flag_to_hstring = [](DWORD file_flag) {
            switch (file_flag)
            {
            case STORE_ASSEMBLY_FILE_STATUS_FLAG_PRESENT:
                return L"Present";
            default:
                return L"Unknown";
            }
        };

        for (auto &val : GetIEnumStructVector<STORE_ASSEMBLY_FILE, SIZE_T>(pFiles))
        {
            result.Append(ComponentFileModel{
                .Name = val.pszFileName,
                .Status = flag_to_hstring(val.dwFileStatusFlags),
            });
        }

        return result;
    }

} // namespace winrt::UFCase::Isolation::implementation
