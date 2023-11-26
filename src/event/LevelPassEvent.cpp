#include "LevelPassEvent.h"
#include "../Game.h"

namespace Event {
    LevelPassEvent::LevelPassEvent() = default;

    bool LevelPassEvent::dispatch(Level::Snake &snake, Level::Block &block) {
        Game::getInstance().fireLevelExit(true);
        return false;
    }
} // Event