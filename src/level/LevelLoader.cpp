
#include "LevelLoader.h"

#include <utility>
#include <dirent.h>

namespace Level {
    LevelLoader::LevelLoader(std::string basePath) : basePath(std::move(basePath)) {
        auto dir = opendir(this->basePath.c_str());
        struct dirent *dirEntry;
        if (dir != nullptr) {
            while ((dirEntry = readdir(dir)) != nullptr) {
                if (dirEntry->d_type == 8) {
                    loadedLevels.insert(dirEntry->d_name);
                }
            }
            closedir(dir);
        } else {
            // Error
        }
    }
} // Level