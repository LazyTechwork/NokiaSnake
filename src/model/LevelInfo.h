#ifndef NOKIASNAKE_LEVELINFO_H
#define NOKIASNAKE_LEVELINFO_H

#include <filesystem>

namespace Model {
    struct LevelInfo {
        std::string name;
        std::filesystem::path path;
    };
}

#endif //NOKIASNAKE_LEVELINFO_H
