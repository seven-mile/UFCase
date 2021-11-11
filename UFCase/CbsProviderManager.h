#pragma once

#include "CbsApi.h"

#include <string>
#include <map>
#include <filesystem>
#include <unordered_set>

namespace winrt::UFCase {

	class ICbsProvider {
	public:
		virtual std::filesystem::path GetBootdrive() const = 0;
		virtual winrt::com_ptr<ICbsSession> ApplySession() = 0;
		virtual void Dispose() = 0;
	};

	class CbsProviderManager
	{
		std::map<std::filesystem::path, ICbsProvider*> m_provStore;
		std::map<std::filesystem::path, std::unordered_set<winrt::hstring>> m_mapUsers;

		CbsProviderManager();
	public:

		static CbsProviderManager& Current();
		static std::filesystem::path GetOnlineBootdrive();

		ICbsProvider* ApplyFromBootdrive(winrt::hstring const& client, std::filesystem::path const& bootdrive);
		const void Return(winrt::hstring const& client, std::filesystem::path const& bootdrive);
	};

} // namespace winrt::UFCase