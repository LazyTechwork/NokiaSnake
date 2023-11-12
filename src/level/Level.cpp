
#include "Level.h"

#include <stdexcept>

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

    Level::Level(const Point2D &mapSize, std::string levelFile)
            : levelFile(std::move(levelFile)), mapSize(mapSize) {
        map = new Block **[mapSize.y];
        for (int y = 0; y < mapSize.y; ++y) {
            map[y] = new Block *[mapSize.x];
            for (int x = 0; x < mapSize.x; ++x)
                map[y][x] = nullptr;
        }

        if (!getLevelFile().empty()) {
            // Level loader logic
        }

        if (snake == nullptr) {
            snake = new Snake(
                    this,
                    {static_cast<int16_t>(mapSize.x / 2), static_cast<int16_t>(mapSize.y / 2)},
                    3,
                    Common::Direction::UP
            );
        }
    }

    Level::Level() {
        throw std::runtime_error("Cannot construct level without level parameters");
    };

    Level::~Level() {
        for (int y = 0; y < mapSize.y; ++y) {
            for (int x = 0; x < mapSize.x; ++x)
                delete map[y][x];

            delete map[y];
        }

        delete map;
        delete snake;
    }

    Level::Level(const Point2D &mapSize) : Level(mapSize) {

    }

    Level::Level(const Level &levelCopy) : Level(levelCopy.getMapSize(), levelCopy.getLevelFile()) {
        for (int y = 0; y < mapSize.y; ++y)
            std::copy(levelCopy.getMap()[y], levelCopy.getMap()[y] + mapSize.y, map[y]);
    }

    Level &Level::operator=(const Level &levelCopy) {
        Level l(levelCopy);
        std::swap(map, l.map);
        std::swap(mapSize, l.mapSize);
        std::swap(snake, l.snake);
        std::swap(levelFile, l.levelFile);

        return *this;
    }

    Level::Level(Level &&l) noexcept: mapSize({0, 0}), snake(nullptr), map(nullptr) {
        std::swap(map, l.map);
        std::swap(mapSize, l.mapSize);
        std::swap(snake, l.snake);
        std::swap(levelFile, l.levelFile);
    }

    Level &Level::operator=(Level &&l) noexcept {
        if (this != &l) {
            std::swap(map, l.map);
            std::swap(mapSize, l.mapSize);
            std::swap(snake, l.snake);
            std::swap(levelFile, l.levelFile);
        }
        return *this;
    }
} // Level