#ifndef NOKIASNAKE_GAME_H
#define NOKIASNAKE_GAME_H

#include "./common/Point2D.h"
#include "level/Level.h"
#include "level/LevelLoader.h"
#include "model/LevelInfo.h"
#include "proxy/GameProxy.h"
#include <filesystem>

using Common::Point2D;
namespace fs = std::filesystem;

class Game {
public:
    constexpr static const Point2D zeroPoint = {0, 0};

    static Game &getInstance();

private:
    Level::Level *level = nullptr;
    Level::LevelLoader *levelLoader;
    Proxy::GameProxy &gameProxy;
    bool exitLevel = false;

    explicit Game();

    void operator=(Game const &);

    void mainLoop();

    void update();

public:
    [[nodiscard]] Level::Level *getLevel() const;

    void fireLevelExit();

    std::vector<Model::LevelInfo> getAvailableLevels();

    void initialize(Model::LevelInfo &level);

    void setGameProxy(Proxy::GameProxy &proxy);
};


#endif //NOKIASNAKE_GAME_H
