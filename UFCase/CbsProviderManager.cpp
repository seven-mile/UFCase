#include "pch.h"
#include "CbsProviderManager.h"
#pragma warning(disable: 4244 4311 4302)

extern "C" CLSID CLSID_CbsSession;

namespace winrt::UFCase {

	struct CbsOfflineProvider : public ICbsProvider {
		std::filesystem::path m_bootdrv;
		winrt::guid m_guid;
		HINSTANCE m_hHost;
		winrt::com_ptr<IClassFactory> m_pFactory;

		CbsOfflineProvider(std::filesystem::path bootdrv) : m_bootdrv(bootdrv) {
			m_guid = winrt::GuidHelper::CreateNewGuid();
			WCHAR pathExe[MAX_PATH];
			GetModuleFileNameW(NULL, pathExe, MAX_PATH);
			std::filesystem::path pathTmp{ pathExe };
			pathTmp = pathTmp.parent_path();
			pathTmp /= L"ServicingApiHost.exe";
			if (!std::filesystem::is_regular_file(pathTmp))
				check_win32(ERROR_FILE_NOT_FOUND);
			auto pmtstr = std::format(L"{} {}", winrt::to_hstring(m_guid), m_bootdrv.c_str());
			m_hHost = ShellExecute(nullptr, L"runas", pathTmp.c_str(),
				pmtstr.c_str(), L"", SW_HIDE);
			if (uint64_t(m_hHost) < 32)
				winrt::check_win32(uint32_t(m_hHost));
		}
		CbsOfflineProvider(CbsOfflineProvider const&) = delete;
		CbsOfflineProvider(CbsOfflineProvider&) = delete;

		virtual ~CbsOfflineProvider() {

		}

		virtual std::filesystem::path GetBootdrive() const override {
			return m_bootdrv;
		}

		virtual winrt::guid GetGuid() const {
			return m_guid;
		}

		virtual winrt::com_ptr<ICbsSession> ApplySession() override {
			winrt::com_ptr<ICbsSession> pSess{};
			pSess = winrt::create_instance<ICbsSession>(m_guid, CLSCTX_LOCAL_SERVER);
			//winrt::check_hresult(CoGetClassObject(m_guid, CLSCTX_LOCAL_SERVER, nullptr, __uuidof(IClassFactory), m_pFactory.put_void()));
			//winrt::check_hresult(m_pFactory->CreateInstance(nullptr, __uuidof(ICbsSession), pSess.put_void()));
			//winrt::check_hresult(CoCreateInstance(m_guid, nullptr, CLSCTX_SERVER, __uuidof(ICbsSession), pSess.put_void()));
			return pSess;
		}
		virtual void Dispose() override {
			// kill cbs host proc
			winrt::check_bool(TerminateProcess(m_hHost, S_OK));

			delete this;
		}
	};

	struct CbsOnlineProvider : public ICbsProvider {
		CbsOnlineProvider() {

		}
		CbsOnlineProvider(CbsOnlineProvider const&) = delete;
		CbsOnlineProvider(CbsOnlineProvider&) = delete;

		virtual ~CbsOnlineProvider() = default;
		virtual std::filesystem::path GetBootdrive() const override {
			return CbsProviderManager::GetOnlineBootdrive();
		}

		virtual winrt::com_ptr<ICbsSession> ApplySession() override {
			winrt::com_ptr<ICbsSession> pRes;
			THROW_IF_FAILED(CoCreateInstance(CLSID_CbsSession, nullptr, CLSCTX_SERVER, __uuidof(ICbsSession), pRes.put_void()));
			return pRes;
		}
		virtual void Dispose() override {
			// have nothing to do
			delete this;
		}
	};

	CbsProviderManager::CbsProviderManager()
	{

	}

	CbsProviderManager& CbsProviderManager::Current()
	{
		static CbsProviderManager* singleton{ nullptr };
		if (singleton) return *singleton;
		return *(singleton = new CbsProviderManager{});
	}

	std::filesystem::path CbsProviderManager::GetOnlineBootdrive()
	{
		static std::filesystem::path pathBd{};
		if (!pathBd.empty()) return pathBd;

		{ // first call
			static wchar_t pathBuffer[MAX_PATH]{};
			if (!GetWindowsDirectory(pathBuffer, MAX_PATH))
				winrt::throw_last_error();
			pathBd = pathBuffer;
			pathBd = pathBd.parent_path();
		}
		return pathBd;
	}

	ICbsProvider* CbsProviderManager::ApplyFromBootdrive(winrt::hstring const& client, std::filesystem::path const& bootdrive)
	{
		auto& users = m_mapUsers[bootdrive];
		users.insert(client);
		auto& prov = m_provStore[bootdrive];

		if (prov) return prov;
		if (CbsProviderManager::GetOnlineBootdrive() == bootdrive) {
			return prov = new CbsOnlineProvider{};
		}
		else {
			return prov = new CbsOfflineProvider{ bootdrive };
		}
	}

	const void CbsProviderManager::Return(winrt::hstring const& client, std::filesystem::path const& bootdrive)
	{
		auto& users = m_mapUsers[bootdrive];
		if (!users.count(client)) throw winrt::hresult_illegal_method_call{};
		users.erase(client);

		if (users.empty()) {
			// auto delete this
			m_provStore[bootdrive]->Dispose();
			m_provStore.erase(bootdrive);
		}
	}
} // namespace winrt::UFCase