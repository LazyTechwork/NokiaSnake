
#include "Snake.h"
#include "../Game.h"

namespace Level {
    Snake::Snake(Level *level, const Point2D &headPosition, int8_t health, Direction direction) : headPosition(
            headPosition), direction(direction), health(health), level(level) {}

    const Point2D &Snake::getHeadPosition() const {
        return headPosition;
    }

    const std::deque<Point2D> &Snake::getTail() const {
        return tail;
    }

    Direction Snake::getDirection() const {
        return direction;
    }

    int8_t Snake::getHealth() const {
        return health;
    }

    Level *Snake::getLevel() const {
        return level;
    }

    void Snake::setDirection(Direction direction) {
        Snake::direction = direction;
    }

    void Snake::setHealth(int8_t health) {
        Snake::health = health;
    }

    void Snake::increaseHealth(int8_t health) {
        Snake::health += health;
        if (Snake::health <= 0) {
            Game::getInstance().fireLevelExit();
        }
    }

    void Snake::moveForward() {
        tail.push_front(getHeadPosition());
        tail.pop_back();
        headPosition += lookingAt();
    }

    Point2D Snake::lookingAt() {
        return Common::Point2D::fromDirection(direction);
    }
} // Entity