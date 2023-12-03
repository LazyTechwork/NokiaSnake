
#ifndef NOKIASNAKE_BLOCKGATE_H
#define NOKIASNAKE_BLOCKGATE_H

#include "Block.h"

namespace Level {

    class BlockGate: public Block {
    private:
        Event::BlockEvent *event = nullptr;
    public:
        BlockGate();

        std::string getResourceName() const override;
    };

} // Level

#endif //NOKIASNAKE_BLOCKGATE_H
