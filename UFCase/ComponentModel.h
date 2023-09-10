#pragma once

#include "Model.h"

#include "isolation.h"

namespace winrt::UFCase
{
    class StoreModel;

    class ComponentModel : public Model<ComponentModel>
    {
        friend class StoreModel;

        StoreModel &store;
        com_ptr<IDefinitionIdentity> asm_id;

        ComponentModel(StoreModel *store, com_ptr<IDefinitionIdentity> asm_id);

        static ComponentModel *Create(StoreModel *store, com_ptr<IDefinitionIdentity> asm_id);

      public:
        hstring GetAttribute(hstring ns, hstring attr);
        hstring GetAttribute(hstring attr);

        hstring TextForm();
        hstring KeyForm();

        hstring Manifest();

        DWORD Status();
        hstring PayloadPath();

        std::vector<STORE_ASSEMBLY_FILE> Files(DWORD dwFlag = ISTORE_ENUM_FILES_FLAG_INCLUDE_INSTALLED_FILES);
    };

} // namespace winrt::UFCase
