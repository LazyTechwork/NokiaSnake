#ifndef NOKIASNAKE_MAPBLOCKTYPE_H
#define NOKIASNAKE_MAPBLOCKTYPE_H

#include <cstdint>

#pragma pack(push, 1)
enum MapBlockType: uint8_t {
    AIR, BORDER, GATE, FOOD
};
#pragma pack(pop)

#endif //NOKIASNAKE_MAPBLOCKTYPE_H
