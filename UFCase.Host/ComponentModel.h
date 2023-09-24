#pragma once

#include "ComponentModel.g.h"

#include "ServicingApi/isolation.h"

#include <winrt/UFCase.Host.Manifest.h>

namespace winrt::UFCase::Isolation::implementation
{
    struct StoreModel;

    struct ComponentModel : ComponentModelT<ComponentModel>
    {
        ComponentModel(Isolation::StoreModel store, com_ptr<IDefinitionIdentity> asm_id);

        hstring GetAttribute(hstring ns, hstring attr);
        hstring GetAttribute(hstring attr);

        hstring TextForm();
        hstring KeyForm();

        hstring Manifest();
        UFCase::Host::Manifest::Assembly CookedManifest();

        CsiComponentStatus Status();
        hstring PayloadPath();

        Windows::Foundation::Collections::IVector<ComponentFileModel> GetFileCollection(
            DWORD dwFlag = ISTORE_ENUM_FILES_FLAG_INCLUDE_INSTALLED_FILES);

      private:
        implementation::StoreModel *m_store;
        com_ptr<IDefinitionIdentity> m_asm_id;
    };
} // namespace winrt::UFCase::Isolation::implementation

// namespace winrt::UFCase::Isolation::factory_implementation
//{
//     struct ComponentModel : ComponentModelT<ComponentModel, implementation::ComponentModel>
//     {
//     };
// }
