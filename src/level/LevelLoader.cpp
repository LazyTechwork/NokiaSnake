
#include "LevelLoader.h"

namespace Level {
    LevelLoader::LevelLoader(fs::path basePath) : basePath(std::move(basePath)) {
        introspectLevels();
    }

    void LevelLoader::introspectLevels() {
        if (fs::exists(basePath)) {
            if (fs::is_directory(basePath)) {
                for (auto const &dirEntry: std::filesystem::recursive_directory_iterator(basePath)) {
                    if (dirEntry.is_regular_file() && dirEntry.path().extension() == ".level") {
                        loadedLevels.insert(dirEntry.path());
                    }
                }
            }
        } else {
            fs::create_directory(basePath);
        }
    }
} // Level