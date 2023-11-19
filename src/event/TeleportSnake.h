
#ifndef NOKIASNAKE_TELEPORTSNAKE_H
#define NOKIASNAKE_TELEPORTSNAKE_H

#include "../common/Point2D.h"
#include "BlockEvent.h"

namespace Event {

    class TeleportSnake: public BlockEvent{
    private:
        Common::Point2D newPosition;
    public:
        explicit TeleportSnake(const Common::Point2D &newPosition);

        bool dispatch(Level::Snake &snake, Level::Block &block) override;
    };

} // Event

#endif //NOKIASNAKE_TELEPORTSNAKE_H
