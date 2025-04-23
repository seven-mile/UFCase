#include <Windows.h>
#include <dbghelp.h>

#include <filesystem>

namespace winrt::UFCase
{

    DWORD GetExecutableProcessArchitecture(std::filesystem::path const &exePath)
    {
        wil::unique_hfile hFile{CreateFile(exePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL,
                                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL)};
        if (!hFile.is_valid())
        {
            THROW_LAST_ERROR();
        }

        wil::unique_handle hMapping{
            CreateFileMapping(hFile.get(), NULL, PAGE_READONLY, 0, 0, NULL)};
        if (!hMapping)
        {
            THROW_LAST_ERROR();
        }

        wil::unique_mapview_ptr<> baseAddress{MapViewOfFile(hMapping.get(), FILE_MAP_READ, 0, 0, 0)};
        if (!baseAddress.get())
        {
            THROW_LAST_ERROR();
        }

        PIMAGE_DOS_HEADER dosHeader = static_cast<PIMAGE_DOS_HEADER>(baseAddress.get());
        if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE)
        {
            THROW_WIN32(STATUS_INVALID_PARAMETER);
        }

        PIMAGE_NT_HEADERS ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(
            static_cast<BYTE *>(baseAddress.get()) + dosHeader->e_lfanew);
        if (ntHeaders->Signature != IMAGE_NT_SIGNATURE)
        {
            throw_hresult(E_UNEXPECTED);
        }

        switch (ntHeaders->FileHeader.Machine)
        {
        case IMAGE_FILE_MACHINE_I386:
            return PROCESSOR_ARCHITECTURE_INTEL; // x86
        case IMAGE_FILE_MACHINE_AMD64:
            return PROCESSOR_ARCHITECTURE_AMD64; // x64
        case IMAGE_FILE_MACHINE_ARM:
            return PROCESSOR_ARCHITECTURE_ARM; // ARM
        case IMAGE_FILE_MACHINE_ARM64:
            return PROCESSOR_ARCHITECTURE_ARM64; // ARM64
        default:
            throw_hresult(E_UNEXPECTED);
        }
    }
} // namespace winrt::UFCase
