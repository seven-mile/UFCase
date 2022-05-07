#pragma once

#include "HrError.g.h"
#include "ErrorDialog.g.h"

namespace winrt::UFCase::implementation
{

    struct HrError : HrErrorT<HrError>
    {
        HrError();
        HrError(uint32_t hr);

        uint32_t Code();
        void Code(uint32_t val);
        hstring Message();
        void Message(const hstring &val);

    private:
        int m_code;
        hstring m_msg;
    };

    struct ErrorDialog : ErrorDialogT<ErrorDialog>
    {
        UFCase::HrError error;

        ErrorDialog(UFCase::HrError error) : error(error) {
            InitializeComponent();

            TitleBlock().Text(std::format(L"Error: 0x{:x}", error.Code()));
            MsgBlock().Text(error.Message());
        }
    };
}

namespace winrt::UFCase::factory_implementation
{
    struct HrError : HrErrorT<HrError, implementation::HrError>
    {
    };

    struct ErrorDialog : ErrorDialogT<ErrorDialog, implementation::ErrorDialog>
    {
    };
}
