
#ifndef NOKIASNAKE_DIRECTION_H
#define NOKIASNAKE_DIRECTION_H

#include <cstdint>
#include "Point2D.h"

namespace Common {
    enum Direction: uint8_t {
        UP, RIGHT, DOWN, LEFT
    };

    static Point2D directionToPoint2D(Direction &direction);
}

#endif //NOKIASNAKE_DIRECTION_H
