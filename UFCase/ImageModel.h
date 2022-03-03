#pragma once
#include "Model.h"
#include "PackageModel.h"

#include <filesystem>
#include <set>

namespace winrt::UFCase {

    //enum class ImageType {
    //    Online,
    //    Offline
    //};

    class SessionModel;

    class ImageModel : public Model<ImageModel>
    {
        std::filesystem::path bootdrive;
        //ImageType type;

        ImageModel(std::filesystem::path const& bootdrive);
        std::set<uint64_t> sessions;
    public:
        ~ImageModel();

        static ImageModel* Create(std::filesystem::path const& bootdrive);

        SessionModel* OpenSession(_CbsSessionOption option = CbsSessionOptionNone);

        std::filesystem::path Bootdrive();
        std::filesystem::path WinDir();

        //ImageType Type();
    };
}
