
#ifndef NOKIASNAKE_LEVELLOADER_H
#define NOKIASNAKE_LEVELLOADER_H

#include <string>
#include <set>

namespace Level {

    class LevelLoader {
    private:
        std::string basePath;
        std::set<std::string> loadedLevels;
    public:
        explicit LevelLoader(std::string basePath);
    };

} // Level

#endif //NOKIASNAKE_LEVELLOADER_H
