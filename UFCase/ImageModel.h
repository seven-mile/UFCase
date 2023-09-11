#pragma once
#include "Model.h"
#include "PackageModel.h"

#include "SSShimApi.h"

#include <filesystem>
#include <set>

namespace winrt::UFCase
{

    enum class ImageType
    {
        Online,
        Offline
    };

    class SessionModel;
    class StoreModel;

    class ImageModel : public Model<ImageModel>
    {
        std::filesystem::path bootdrive;

        ImageModel(std::filesystem::path const &bootdrive);
        std::set<uint64_t> sessions;

        // persist registry access
        SessionModel *basic_sess;
        StoreModel *sxs_store;

      public:
        ~ImageModel();

        static ImageModel *Create(std::filesystem::path const &bootdrive);
        static ImageModel *Current();
        static void Current(ImageModel *);

        SessionModel *OpenSession(_CbsSessionOption option = CbsSessionOptionNone);
        void CloseSession(uint64_t handle);

        StoreModel *SxsStore();

        std::filesystem::path Bootdrive();
        std::filesystem::path WinDir();

        ImageType Type();
        FOUR_PART_VERSION Version();
        hstring Edition();
        hstring Architecture();
        bool IsWinPE();
    };

} // namespace winrt::UFCase
