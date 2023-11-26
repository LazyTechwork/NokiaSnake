
#include "BlockGate.h"
#include "../event/LevelPassEvent.h"

namespace Level {
    BlockGate::BlockGate() {
        BlockGate::passable = false;
        if (event == nullptr) {
            event = new Event::LevelPassEvent();
        }
        setSnakeStepsOnEvent(event);
    }
} // Level