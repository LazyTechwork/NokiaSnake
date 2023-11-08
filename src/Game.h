
#ifndef NOKIASNAKE_GAME_H
#define NOKIASNAKE_GAME_H

#include "./common/Point2D.h"
#include "level/Level.h"
#include "level/LevelLoader.h"

using Common::Point2D;

class Game {
public:
    constexpr static const Point2D zeroPoint = {0, 0};

    static Game &getInstance();

private:
    Level::Level *level = nullptr;
    Level::LevelLoader *levelLoader;
    bool exitLevel = false;

    explicit Game();

    void operator=(Game const &);

    void mainLoop();

    void update();

public:
    [[nodiscard]] Level::Level *getLevel() const;
    void fireLevelExit();
};


#endif //NOKIASNAKE_GAME_H
