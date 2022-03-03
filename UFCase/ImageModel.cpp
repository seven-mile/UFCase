#include "pch.h"
#include "ImageModel.h"
#include "SessionModel.h"

#include "CbsProviderManager.h"

namespace winrt::UFCase {

    ImageModel::ImageModel(std::filesystem::path const &bootdrive) : bootdrive(bootdrive) {
        //if (bootdrive == CbsProviderManager::GetOnlineBootdrive())
        //    type = ImageType::Online;
        //else type = ImageType::Offline;
    }

    ImageModel::~ImageModel()
    {
        for (auto val : sessions) {
            ModelManager<SessionModel>::Erase(val);
        }
        sessions.clear();
    }

    ImageModel* ImageModel::Create(std::filesystem::path const& bootdrive)
    {
        static std::unordered_map<std::wstring, uint64_t> images;
        if (auto it = images.find(bootdrive); it != images.end())
            return &ImageModel::GetInstance(it->second);
        auto res = new ImageModel{ bootdrive };
        images[bootdrive] = res->GetHandle();
        return res;
    }

    SessionModel* ImageModel::OpenSession(_CbsSessionOption option)
    {
        auto &&res = SessionModel::Create(this, option);
        sessions.insert(res->GetHandle());
        return res;
    }

    std::filesystem::path ImageModel::Bootdrive()
    {
        return bootdrive;
    }

    std::filesystem::path ImageModel::WinDir()
    {
        return bootdrive / L"Windows";
    }
}
