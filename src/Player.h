#ifndef NOKIASNAKE_PLAYER_H
#define NOKIASNAKE_PLAYER_H


#include "level/Snake.h"
#include "level/Level.h"
#include "event/DealSnakeDamageEvent.h"

class Player {
private:
    Level::Level *level;
    Event::DealSnakeDamageEvent damageEvent{1};
public:
    explicit Player(Level::Level *level);

    void doTick();
};


#endif //NOKIASNAKE_PLAYER_H
