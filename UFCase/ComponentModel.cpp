#include "pch.h"

#include "ComponentModel.h"

#include "StoreModel.h"

#include "CbsUtil.h"

#include <string>

#include <wil/resource.h>
#include <wil/win32_helpers.h>
#include <wil/stl.h>

namespace winrt::UFCase
{

    ComponentModel::ComponentModel(StoreModel *store, com_ptr<IDefinitionIdentity> asm_id)
        : store(*store), asm_id(asm_id)
    {
    }

    ComponentModel *ComponentModel::Create(StoreModel *store, com_ptr<IDefinitionIdentity> asm_id)
    {
        IDefinitionIdentity *def_idents[] = {
            asm_id.get(),
        };
        BOOL complete = 0;
        HRESULT hr =
            store->sxs_store->AreComponentsCompleteFromIdentities(0, 1, def_idents, &complete);
        if (SUCCEEDED(hr) && complete)
        {
            return new ComponentModel(store, asm_id);
        }
        else
        {
            return nullptr;
        }
    }

    hstring ComponentModel::GetAttribute(hstring ns, hstring attr)
    {
        wil::unique_cotaskmem_string result;
        check_hresult(asm_id->GetAttribute(ns.c_str(), attr.c_str(), result.put()));
        return result.get();
    }

    hstring ComponentModel::GetAttribute(hstring attr)
    {
        return GetAttribute(L"", attr);
    }

    hstring ComponentModel::TextForm()
    {
        wil::unique_cotaskmem_string result;
        check_hresult(store.ident_auth->DefinitionToText(0, asm_id.get(), result.put()));
        return result.get();
    }

    hstring ComponentModel::KeyForm()
    {
        wil::unique_cotaskmem_string result;
        check_hresult(store.ident_auth->GenerateDefinitionKey(0, asm_id.get(), result.put()));
        return result.get();
    }

    hstring ComponentModel::Manifest()
    {
        com_ptr<::IUnknown> pTManifestRaw;
        IDefinitionIdentity *def_idents[] = {asm_id.get()};
        winrt::check_hresult(store.csi_store->GetComponentManifests(
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

    DWORD ComponentModel::Status()
    {
        CSI_COMPONENT_BASIC_INFORMATION basicInfo{sizeof(basicInfo)};
        check_hresult(store.csi_store->GetComponentInformation(
            0, ICSISTORE_GET_COMPONENT_INFORMATION_CLASS_BASIC, asm_id.get(), sizeof(basicInfo),
            &basicInfo));
        return basicInfo.dwCsiStatus;
    }

    hstring ComponentModel::PayloadPath()
    {
        CSI_COMPONENT_PAYLOAD_INFORMATION payloadInfo{sizeof(payloadInfo)};

        // optional flag: ISTORE_LOCK_ASSEMBLY_PATH_FLAG_NOT_FOUND_RETURNS_NULL
        auto hr = (store.csi_store->GetComponentInformation(
            0, ICSISTORE_GET_COMPONENT_INFORMATION_CLASS_PAYLOAD, asm_id.get(), sizeof(payloadInfo),
            &payloadInfo));
        if (FAILED(hr))
        {
            return L"NOTIMPL";
        }
        com_ptr<::IUnknown> component_lock;
        component_lock.attach(payloadInfo.pComponentLock);
        return payloadInfo.pszPayloadRoot;
    }

    std::vector<STORE_ASSEMBLY_FILE> ComponentModel::Files(DWORD dwFlag)
    {
        std::vector<STORE_ASSEMBLY_FILE> result;

        com_ptr<::IUnknown> pFilesRaw;
        check_hresult(store.sxs_store->EnumFiles(
            dwFlag, asm_id.get(), __uuidof(IEnumSTORE_ASSEMBLY_FILE), pFilesRaw.put()));
        auto pFiles = pFilesRaw.as<IEnumSTORE_ASSEMBLY_FILE>();

        return GetIEnumStructVector<STORE_ASSEMBLY_FILE, SIZE_T>(pFiles);
    }

} // namespace winrt::UFCase
