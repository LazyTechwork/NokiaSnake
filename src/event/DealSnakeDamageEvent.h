
#ifndef NOKIASNAKE_DEALSNAKEDAMAGEEVENT_H
#define NOKIASNAKE_DEALSNAKEDAMAGEEVENT_H

#include <cstdint>
#include "BlockEvent.h"

namespace Event {

    class DealSnakeDamageEvent: public BlockEvent{
    private:
        int8_t damage;
    public:
        explicit DealSnakeDamageEvent(int8_t damage);

        bool dispatch(Level::Snake &snake, Level::Block &block) override;
    };

} // Event

#endif //NOKIASNAKE_DEALSNAKEDAMAGEEVENT_H
