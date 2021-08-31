#include "pch.h"
#include "ErrorPage.h"
#if __has_include("HrError.g.cpp")
#include "HrError.g.cpp"
#endif
#if __has_include("ErrorPage.g.cpp")
#include "ErrorPage.g.cpp"
#endif

#include <filesystem>

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UFCase::implementation
{
    HrError::HrError() : m_code() { }

    HrError::HrError(int hr) : m_code(hr)
    {
        std::wstring pathstrMsgdll(GetWindowsDirectoryW(nullptr, 0), L'\0');
        if (pathstrMsgdll.size() !=
            GetWindowsDirectoryW(pathstrMsgdll.data(), pathstrMsgdll.size()))
            winrt::throw_last_error();

        std::filesystem::path pathMsgdll(pathstrMsgdll);
        pathMsgdll /= L"servicing\\CbsMsg.dll";

        auto hmsg = LoadLibraryW(pathMsgdll.c_str());
        LPWSTR buffer;
        if (!FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_ALLOCATE_BUFFER,
            hmsg, hr, 0, reinterpret_cast<LPWSTR>(&buffer), 0, nullptr))
            winrt::throw_last_error();
        m_msg = buffer;
        LocalFree(buffer);
    }

    int HrError::Code()
    {
        return m_code;
    }

    void HrError::Code(int val)
    {
        m_code = val;
    }

    hstring HrError::Message()
    {
        return m_msg;
    }

    void HrError::Message(const hstring& val)
    {
        m_msg = val;
    }

    ErrorPage::ErrorPage()
    {
        InitializeComponent();
    }

    void ErrorPage::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {
        if (auto val = e.Parameter().try_as<UFCase::HrError>()) {
            // copy a com_ptr to ensure AddRef is called
            // never use [&] in async callback
            this->DispatcherQueue().TryEnqueue([val, ptr = this->get_strong()](){
                ptr->TitleBlock().Text(L"Failed to load page");
                ptr->MsgBlock().Text(val.Message());
            });
        }
    }

}
