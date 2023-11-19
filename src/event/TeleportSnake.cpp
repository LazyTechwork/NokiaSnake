
#include "TeleportSnake.h"
#include "../level/Snake.h"

namespace Event {
    TeleportSnake::TeleportSnake(const Common::Point2D &newPosition) : newPosition(newPosition) {}

    bool TeleportSnake::dispatch(Level::Snake &snake, Level::Block &block) {
        auto diff = newPosition - snake.getHeadPosition();
        snake.setHeadPosition(snake.getHeadPosition() + diff);
        auto tail = snake.getTail();
        std::vector<Point2D> newTail = {};
        newTail.resize(tail.size());
        for (const auto &item: tail)
            newTail.push_back(item + diff);
        snake.eatTail(tail.size());
        snake.pushTail(newTail);
        return false;
    }
} // Event