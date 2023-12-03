
#ifndef NOKIASNAKE_LEVEL_H
#define NOKIASNAKE_LEVEL_H

#include <filesystem>
#include "Block.h"

class Player;

namespace Level {

    class Snake;

    class Level {
    private:
        std::string name = "Unnamed level";
        std::filesystem::path levelFile;
        Snake *snake = nullptr;
        Player *player;
        Block ***map;
        Point2D mapSize;
    public:
        Level();

        Level(const Point2D &mapSize, std::filesystem::path levelFile);

        explicit Level(const Point2D &mapSize);

        [[nodiscard]] const std::filesystem::path &getLevelFile() const;

        [[nodiscard]] Player & getPlayer() const;

        [[nodiscard]] Snake & getSnake() const;

        [[nodiscard]] Block ***getMap() const;

        [[nodiscard]] const Point2D &getMapSize() const;

        [[nodiscard]] Block * getBlock(Point2D p) const;

        void destroyBlock(Point2D p);

        virtual ~Level();

        Level(const Level &levelCopy);

        Level &operator=(const Level &levelCopy);

        Level(Level &&l) noexcept;

        Level &operator=(Level &&l) noexcept;

        const std::string &getName() const;

        void setName(const std::string &name);

    };

} // Level

#endif //NOKIASNAKE_LEVEL_H
