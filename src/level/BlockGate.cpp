
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

    std::string BlockGate::getResourceName() const {
        return passable ? "gate:open" : "gate:closed";
    }
} // Level