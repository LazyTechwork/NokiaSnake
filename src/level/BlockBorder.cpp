
#include "BlockBorder.h"

namespace Level {
    BlockBorder::BlockBorder() {
        BlockBorder::passable = false;
    }

    std::string BlockBorder::getResourceName() const {
        return "border";
    }
} // Level