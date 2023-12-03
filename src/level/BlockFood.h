
#ifndef NOKIASNAKE_BLOCKFOOD_H
#define NOKIASNAKE_BLOCKFOOD_H

#include "Block.h"
#include "../event/IncreaseScoreEvent.h"

namespace Level {

    class BlockFood : public Block {
    private:
        Event::BlockEvent *event = nullptr;
    public:
        BlockFood();

        std::string getResourceName() const override;
    };

} // Level

#endif //NOKIASNAKE_BLOCKFOOD_H
