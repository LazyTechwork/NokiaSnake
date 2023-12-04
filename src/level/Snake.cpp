
#include "Snake.h"
#include "../Game.h"

namespace Level {
    Snake::Snake(Level &level, const Point2D &headPosition, int8_t health, Direction direction) : headPosition(
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

    Level &Snake::getLevel() const {
        return level;
    }

    void Snake::setDirection(Direction direction) {
        if (Common::Point2D::fromDirection(direction) != Common::Point2D::fromDirection(Snake::direction) * -1)
            Snake::direction = direction;
    }

    void Snake::setHealth(int8_t health) {
        Snake::health = health;
    }

    void Snake::increaseHealth(int8_t health) {
        Snake::health += health;
        if (Snake::health <= 0) {
            Game::getInstance()->fireLevelExit(false);
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

    void Snake::pushTail(Point2D p) {
        tail.push_back(p);
    }

    void Snake::pushTail(std::vector<Point2D> &p) {
        for (const auto &item: p)
            tail.push_back(item);
        tail.shrink_to_fit();
    }

    uint16_t Snake::getScore() {
        return tail.size();
    }

    void Snake::eatTail(uint8_t count) {
        tail.resize(tail.size() - count);
    }

    void Snake::setHeadPosition(const Point2D &headPosition) {
        Snake::headPosition = headPosition;
    }

    void Snake::pushTail() {
        tail.push_back((tail.empty() ? headPosition : tail.back()) - Common::Point2D::fromDirection(direction));
    }
} // Entity