#ifndef NOKIASNAKE_PLAYER_H
#define NOKIASNAKE_PLAYER_H


#include "level/Snake.h"
#include "level/Level.h"

class Player {
private:
    Level::Level *level;
public:
    explicit Player(Level::Level *level);
    void doTick();
};


#endif //NOKIASNAKE_PLAYER_H
