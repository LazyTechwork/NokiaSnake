
#ifndef NOKIASNAKE_LEVEL_H
#define NOKIASNAKE_LEVEL_H

#include "Block.h"

namespace Level {

    class Snake;

    class Level {
        std::string levelFile;
        Snake *snake;
        Block ***map;
        Point2D mapSize;
    };

} // Level

#endif //NOKIASNAKE_LEVEL_H
