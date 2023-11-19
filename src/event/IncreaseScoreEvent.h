
#ifndef NOKIASNAKE_INCREASESCOREEVENT_H
#define NOKIASNAKE_INCREASESCOREEVENT_H

#include <cstdint>
#include "BlockEvent.h"

namespace Event {

    class IncreaseScoreEvent: public BlockEvent {
    private:
        int8_t score;
    public:
        explicit IncreaseScoreEvent(int8_t score);

        bool dispatch(Level::Snake &snake, Level::Block &block) override;
    };

} // Event

#endif //NOKIASNAKE_INCREASESCOREEVENT_H
