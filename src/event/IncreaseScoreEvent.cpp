
#include "IncreaseScoreEvent.h"
#include "../level/Snake.h"
#include <vector>

namespace Event {
    bool IncreaseScoreEvent::dispatch(Level::Snake &snake, Level::Block &block) {
        if (score == 0)
            return true;
        if (score > 0) {
            std::vector<Point2D> appendix = {};
            appendix.resize(score);
            std::fill(appendix.begin(), appendix.end(), snake.getTail().back());
            snake.pushTail(appendix);
        } else {
            snake.eatTail(snake.getScore() + score >= 0 ? -score : snake.getScore());
        }
        return true;
    }

    IncreaseScoreEvent::IncreaseScoreEvent(int8_t score) : score(score) {}
} // Event