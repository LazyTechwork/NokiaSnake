
#ifndef NOKIASNAKE_LEVELLOADER_H
#define NOKIASNAKE_LEVELLOADER_H

#include <string>
#include <set>

#include <filesystem>
namespace fs = std::filesystem;

namespace Level {

    class LevelLoader {
    private:
        fs::path basePath;
        std::set<fs::path> loadedLevels = {};
    public:
        explicit LevelLoader(fs::path basePath);
        void introspectLevels();
    };

} // Level

#endif //NOKIASNAKE_LEVELLOADER_H
