
#ifndef NOKIASNAKE_BLOCKBORDER_H
#define NOKIASNAKE_BLOCKBORDER_H

#include "Block.h"

namespace Level {

    class BlockBorder: public Block {
    public:
        BlockBorder();

        std::string getResourceName() const override;
    };

} // Level

#endif //NOKIASNAKE_BLOCKBORDER_H
