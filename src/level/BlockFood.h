
#ifndef NOKIASNAKE_BLOCKFOOD_H
#define NOKIASNAKE_BLOCKFOOD_H

#include "Block.h"
#include "../event/IncreaseScoreEvent.h"

namespace Level {

    class BlockFood : public Block {
    private:
        static Event::BlockEvent *event;
    public:
        BlockFood();
    };

} // Level

#endif //NOKIASNAKE_BLOCKFOOD_H
