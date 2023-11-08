
#include "Level.h"

namespace Level {
    const std::string &Level::getLevelFile() const {
        return levelFile;
    }

    Snake *Level::getSnake() const {
        return snake;
    }

    Block ***Level::getMap() const {
        return map;
    }

    const Point2D &Level::getMapSize() const {
        return mapSize;
    }

    Block *Level::getBlock(Point2D p) const {
        return map[p.y][p.x];
    }

    void Level::destroyBlock(Point2D p) {
        map[p.y][p.x] = nullptr;
    }
} // Level