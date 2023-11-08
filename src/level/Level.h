
#ifndef NOKIASNAKE_LEVEL_H
#define NOKIASNAKE_LEVEL_H

#include "Block.h"

namespace Level {

    class Snake;

    class Level {
    private:
        std::string levelFile;
        Snake *snake;
        Block ***map;
        Point2D mapSize;
    public:
        [[nodiscard]] const std::string &getLevelFile() const;

        [[nodiscard]] Snake *getSnake() const;

        [[nodiscard]] Block ***getMap() const;

        [[nodiscard]] const Point2D &getMapSize() const;

        [[nodiscard]] Block *getBlock(Point2D p) const;

        void destroyBlock(Point2D p);
    };

} // Level

#endif //NOKIASNAKE_LEVEL_H
