
#include "Block.h"

namespace Level {
    bool Block::isPassable() const {
        return passable;
    }

    bool Block::onSnakeStepsOn(Snake &snake) {
        if (snakeStepsOnEvent != nullptr) {
            return snakeStepsOnEvent->dispatch(snake, *this);
        }

        return false;
    }

    void Block::setSnakeStepsOnEvent(Event::BlockEvent *snakeStepsOnEvent) {
        Block::snakeStepsOnEvent = snakeStepsOnEvent;
    }
}
