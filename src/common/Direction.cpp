#include "Direction.h"

namespace Common {

    Point2D directionToPoint2D(Direction &direction) {
        switch (direction) {
            case Direction::UP:
                return {0, 1};
            case Direction::DOWN:
                return {0, -1};
            case Direction::RIGHT:
                return {1, 0};
            case Direction::LEFT:
                return {-1, 0};
        }
    }
}