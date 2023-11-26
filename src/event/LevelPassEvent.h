//
// Created by LazyTechwork on 11/27/2023.
//

#ifndef NOKIASNAKE_LEVELPASSEVENT_H
#define NOKIASNAKE_LEVELPASSEVENT_H

#include "BlockEvent.h"

namespace Event {

    class LevelPassEvent : public BlockEvent {
    public:
        LevelPassEvent();

        bool dispatch(Level::Snake &snake, Level::Block &block) override;
    };

} // Event

#endif //NOKIASNAKE_LEVELPASSEVENT_H
