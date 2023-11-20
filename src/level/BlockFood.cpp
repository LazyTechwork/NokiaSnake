
#include "BlockFood.h"

namespace Level {
    BlockFood::BlockFood() {
        BlockFood::passable = true;
        if (event == nullptr) {
            event = new Event::IncreaseScoreEvent(1);
        }
        setSnakeStepsOnEvent(event);
    }
} // Level