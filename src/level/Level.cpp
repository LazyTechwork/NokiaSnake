#include "Level.h"
#include "../Player.h"

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

        if (mapSize < Point2D{10, 10}) {
            throw std::runtime_error("Cannot create map with sides lower of 10");
        }

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

        player = new Player(this);
    }

    Level::Level() {
        throw std::runtime_error("Cannot construct level without level parameters");
    };

    Level::~Level() {
        for (int y = 0; y < mapSize.y; ++y)
            delete []map[y];

        delete []map;
        delete player;
        delete snake;
    }

    Level::Level(const Point2D &mapSize) : Level(mapSize, "") {

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
        std::swap(player, l.player);
        std::swap(levelFile, l.levelFile);

        return *this;
    }

    Level::Level(Level &&l) noexcept: mapSize({0, 0}), snake(nullptr), map(nullptr) {
        std::swap(map, l.map);
        std::swap(mapSize, l.mapSize);
        std::swap(snake, l.snake);
        std::swap(player, l.player);
        std::swap(levelFile, l.levelFile);
    }

    Level &Level::operator=(Level &&l) noexcept {
        if (this != &l) {
            std::swap(map, l.map);
            std::swap(mapSize, l.mapSize);
            std::swap(snake, l.snake);
            std::swap(player, l.player);
            std::swap(levelFile, l.levelFile);
        }
        return *this;
    }

    Player *Level::getPlayer() const {
        return player;
    }
} // Level