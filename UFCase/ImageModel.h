#pragma once
#include "Model.h"
#include "PackageModel.h"

#include <filesystem>
#include <set>

namespace winrt::UFCase {

    enum class ImageType {
        Online,
        Offline
    };

    class SessionModel;

    struct FOUR_PART_VERSION {
        short major, minor, build, revision;
    };

    class ImageModel : public Model<ImageModel>
    {
        std::filesystem::path bootdrive;

        ImageModel(std::filesystem::path const& bootdrive);
        std::set<uint64_t> sessions;

        // persist registry access
        SessionModel* basic_sess;

    public:
        ~ImageModel();

        static ImageModel* Create(std::filesystem::path const& bootdrive);
        static ImageModel* Current();
        static void Current(ImageModel*);

        SessionModel* OpenSession(_CbsSessionOption option = CbsSessionOptionNone);
        void CloseSession(uint64_t handle);

        std::filesystem::path Bootdrive();
        std::filesystem::path WinDir();

        ImageType Type();
        FOUR_PART_VERSION Version();
        hstring Edition();
        hstring Architecture();
        bool IsWinPE();
    };
}
