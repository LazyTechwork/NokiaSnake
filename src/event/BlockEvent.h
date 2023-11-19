
#ifndef NOKIASNAKE_BLOCKEVENT_H
#define NOKIASNAKE_BLOCKEVENT_H

namespace Level {
    class Block;

    class Snake;
}

namespace Event {
    class BlockEvent {
    public:
        virtual bool dispatch(Level::Snake &snake, Level::Block &block) = 0;
    };

} // Event

#endif //NOKIASNAKE_BLOCKEVENT_H
