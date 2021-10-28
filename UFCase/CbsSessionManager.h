#pragma once

#include "CbsApi.h"
#include "SSShimApi.h"

#include <filesystem>

#include "AppConfig.h"

namespace winrt::UFCase {

    class CbsSessionManager
    {
        inline static CbsSessionManager *pInst;
        std::filesystem::path m_pathCore;

        CbsSessionManager() = default;

        struct SSShimHelper {
            winrt::hresult GetStack(
                std::filesystem::path const& pathWindir,
                std::wstring const& filename,
                std::filesystem::path& pathStack);

            ~SSShimHelper();

        private:
            winrt::hresult LoadDll();
            HINSTANCE m_dll = nullptr;
            SssBindServicingStack_t *m_pBindFunc;
            SssGetServicingStackFilePathLength_t *m_pGetLenFunc;
            SssGetServicingStackFilePath_t *m_pGetPathFunc;
            SssReleaseServicingStack_t *m_pReleaseFunc;
            _SSS_COOKIE *m_pCookie;
            std::filesystem::path m_curWindir;
        } m_ssshim;

        enum class StackSourceInternal {
            Unbinded = -1,
            Online = 0,
            Offline = 1,
        } m_curSrc = StackSourceInternal::Unbinded;

        struct OfflineHelper {
            
            winrt::hresult Initialize(std::filesystem::path const &pathCore, winrt::com_ptr<IClassFactory> &pFactory);
            winrt::hresult Finalize();

        private:

            using CbsCoreInitialize_t = HRESULT(__stdcall)(IMalloc*, UINT64(WINAPI*)(UINT64), void (*)(), void (*)(), void (*)(), void (*)(), void (*)(), IClassFactory**);
            using CbsCoreFinalize_t = HRESULT(__stdcall)();

            CbsCoreInitialize_t *m_pInit;
            CbsCoreFinalize_t *m_pFree;

            winrt::hresult LoadDll(std::filesystem::path const &pathCore);
            HINSTANCE m_dll = nullptr;
        } m_offline;

    public:

        enum class StackSource {
            Online = 0,
            Offline = 1, // SSShim
        };

        static CbsSessionManager &instance();
        winrt::hresult SetCustomLogging(std::filesystem::path const &pathLogFile) const;
        winrt::hresult BindStack(StackSource src, std::filesystem::path const &pathWindir = {});
        void ReleaseStack();
        winrt::com_ptr<ICbsSession> ApplyNew();

        static StackSource GetCurrentSource() {
            return static_cast<StackSource>(g_appConfig.GetNamedObject(L"stack").GetNamedNumber(L"source"));
        }

        static winrt::hstring GetCurrentBootdrive() {
            if (GetCurrentSource() == StackSource::Online) throw hresult_illegal_method_call{};
            return g_appConfig.GetNamedObject(L"stack").GetNamedString(L"argBootdrive");
        }

        static winrt::hstring GetCurrentWindir() {
            if (GetCurrentSource() == StackSource::Online) throw hresult_illegal_method_call{};
            auto windir = std::filesystem::path(g_appConfig.GetNamedObject(L"stack").GetNamedString(L"argBootdrive").c_str())
                                / L"Windows";
            return windir.c_str();
        }
    };

}


