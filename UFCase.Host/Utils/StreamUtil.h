#pragma once

#include <winrt/UFCase.Host.Manifest.h>

namespace winrt::UFCase::Host::Manifest::implementation
{
    struct ComStreamWrapper : implements<ComStreamWrapper, IComStreamWrapper, ::IStream>
    {
        ComStreamWrapper(com_ptr<::IStream> stream) : m_stream(stream)
        {
        }

        HRESULT __stdcall Read(void *pv, ULONG cb, ULONG *pcbRead) noexcept
        {
            return m_stream->Read(pv, cb, pcbRead);
        }

        HRESULT __stdcall Write(const void *pv, ULONG cb, ULONG *pcbWritten) noexcept
        {
            return m_stream->Write(pv, cb, pcbWritten);
        }

        HRESULT __stdcall Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin,
                               ULARGE_INTEGER *plibNewPosition) noexcept
        {
            return m_stream->Seek(dlibMove, dwOrigin, plibNewPosition);
        }

        HRESULT __stdcall SetSize(ULARGE_INTEGER libNewSize) noexcept
        {
            return m_stream->SetSize(libNewSize);
        }

        HRESULT __stdcall CopyTo(::IStream *pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead,
                                 ULARGE_INTEGER *pcbWritten) noexcept
        {
            return m_stream->CopyTo(pstm, cb, pcbRead, pcbWritten);
        }

        HRESULT __stdcall Commit(DWORD grfCommitFlags) noexcept
        {
            return m_stream->Commit(grfCommitFlags);
        }

        HRESULT __stdcall Revert() noexcept
        {
            return m_stream->Revert();
        }

        HRESULT __stdcall LockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb,
                                     DWORD dwLockType) noexcept
        {
            return m_stream->LockRegion(libOffset, cb, dwLockType);
        }

        HRESULT __stdcall UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb,
                                       DWORD dwLockType) noexcept

        {
            return m_stream->UnlockRegion(libOffset, cb, dwLockType);
        }

        HRESULT __stdcall Stat(STATSTG *pstatstg, DWORD grfStatFlag) noexcept
        {
            return m_stream->Stat(pstatstg, grfStatFlag);
        }

        HRESULT __stdcall Clone(::IStream **ppstm) noexcept
        {
            return m_stream->Clone(ppstm);
        }

      private:
        com_ptr<::IStream> m_stream;
    };
} // namespace winrt::UFCase::Host::Manifest::implementation
