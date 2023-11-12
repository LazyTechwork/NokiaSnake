
#ifndef NOKIASNAKE_LEVEL_H
#define NOKIASNAKE_LEVEL_H

#include "Block.h"

class Player;

namespace Level {

    class Snake;

    class Level {
    private:
        std::string levelFile;
        Snake *snake;
        Player *player;
        Block ***map;
        Point2D mapSize;
    public:
        Level();

        Level(const Point2D &mapSize, std::string levelFile);

        explicit Level(const Point2D &mapSize);

        [[nodiscard]] const std::string &getLevelFile() const;

        [[nodiscard]] Player *getPlayer() const;

        [[nodiscard]] Snake *getSnake() const;

        [[nodiscard]] Block ***getMap() const;

        [[nodiscard]] const Point2D &getMapSize() const;

        [[nodiscard]] Block *getBlock(Point2D p) const;

        void destroyBlock(Point2D p);

        virtual ~Level();

        Level(const Level &levelCopy);

        Level &operator=(const Level &levelCopy);

        Level(Level &&l) noexcept;

        Level &operator=(Level &&l) noexcept;

    };

} // Level

#endif //NOKIASNAKE_LEVEL_H
