#include "pch.h"
#include "ErrorDialog.h"
#if __has_include("HrError.g.cpp")
#include "HrError.g.cpp"
#endif
#if __has_include("ErrorDialog.g.cpp")
#include "ErrorDialog.g.cpp"
#endif

#include <filesystem>
#include "PathUtil.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UFCase::implementation
{
    HrError::HrError() : m_code()
    {
    }

    HrError::HrError(uint32_t hr) : m_code(hr)
    {
        std::filesystem::path pathMsgdll{GetOnlineWindir() / L"servicing\\CbsMsg.dll"};

        static auto hmsg = ::LoadLibrary(pathMsgdll.c_str());
        if (!hmsg)
            throw_last_error();
        LPWSTR buffer;
        if (!::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_FROM_HMODULE |
                                 FORMAT_MESSAGE_ALLOCATE_BUFFER,
                             hmsg, hr, 0, reinterpret_cast<LPWSTR>(&buffer), 0, nullptr))
            throw_last_error();
        m_msg = buffer;
        ::LocalFree(buffer);
    }

    uint32_t HrError::Code()
    {
        return m_code;
    }

    void HrError::Code(uint32_t val)
    {
        m_code = val;
    }

    hstring HrError::Message()
    {
        return m_msg;
    }

    void HrError::Message(const hstring &val)
    {
        m_msg = val;
    }

} // namespace winrt::UFCase::implementation
