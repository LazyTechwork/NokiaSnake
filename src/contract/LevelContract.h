#ifndef NOKIASNAKE_LEVELCONTRACT_H
#define NOKIASNAKE_LEVELCONTRACT_H

#include <cstdint>
#include <ostream>
#include "../common/Point2D.h"
#include "../level/Block.h"
#include "MapBlockType.h"

namespace Contract {
#pragma pack(push, 1)

    struct LevelContract {
        char levelHeader[6] = "LVLFH";
        char name[24];
        struct SnakeInfo {
            Common::Point2D position;
            uint8_t score;
            Common::Direction direction;
        } snake;
        Common::Point2D mapSize;
        uint16_t predefinedBlocksSize;
        struct MapBlockContract {
            MapBlockType type;
            Common::Point2D coordinates;
        } *map;

        friend std::ostream &operator<<(std::ostream &s, const LevelContract &contract);

        friend std::istream &operator>>(std::istream &s, LevelContract &contract);
    };

#pragma pack(pop)
} // Contract

#endif //NOKIASNAKE_LEVELCONTRACT_H
