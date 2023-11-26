#ifndef NOKIASNAKE_INPUTACTION_H
#define NOKIASNAKE_INPUTACTION_H

#include <cstdint>

namespace Common {
#pragma pack(push, 1)
    enum InputAction : uint8_t {
        TURN_LEFT, TURN_RIGHT, TURN_UP, TURN_DOWN, PAUSE
    };
#pragma pack(pop)
}

#endif //NOKIASNAKE_INPUTACTION_H
