
#ifndef NOKIASNAKE_SNAKE_H
#define NOKIASNAKE_SNAKE_H

#include <deque>
#include <vector>
#include "../common/Point2D.h"
#include "../common/Direction.h"

using Common::Point2D;
using Common::Direction;

namespace Level {
    class Level;

    class Snake {
    private:
        Point2D headPosition;
        std::deque<Point2D> tail;
        Direction direction = Direction::UP;
        int8_t health = INT8_MAX;
        Level &level;
    public:
        Snake(Level &level, const Point2D &headPosition, int8_t health, Direction direction);

        [[nodiscard]] const Point2D &getHeadPosition() const;

        [[nodiscard]] const std::deque<Point2D> &getTail() const;

        void pushTail(Point2D p);

        void pushTail();

        void pushTail(std::vector<Point2D> &p);

        void eatTail(uint8_t count);

        [[nodiscard]] uint16_t getScore();

        void setHeadPosition(const Point2D &headPosition);

        [[nodiscard]] Direction getDirection() const;

        [[nodiscard]] int8_t getHealth() const;

        [[nodiscard]] Level &getLevel() const;

        void moveForward();

        void setDirection(Direction direction);

        void setHealth(int8_t health);

        void increaseHealth(int8_t health);

        Point2D lookingAt();
    };

} // Entity

#endif //NOKIASNAKE_SNAKE_H
