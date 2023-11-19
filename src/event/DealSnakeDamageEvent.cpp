
#include "DealSnakeDamageEvent.h"
#include "../level/Snake.h"
#include "../level/Block.h"

namespace Event {
    bool DealSnakeDamageEvent::dispatch(Level::Snake &snake, Level::Block &block) {
        snake.increaseHealth(-damage);
        return false;
    }

    DealSnakeDamageEvent::DealSnakeDamageEvent(int8_t damage) : damage(damage) {}
} // Event