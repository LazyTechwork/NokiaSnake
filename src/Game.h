#ifndef NOKIASNAKE_GAME_H
#define NOKIASNAKE_GAME_H

#include "./common/Point2D.h"
#include "level/Level.h"
#include "level/LevelLoader.h"
#include "model/LevelInfo.h"
#include "proxy/GameProxy.h"
#include <filesystem>
#include <map>

using Common::Point2D;
namespace fs = std::filesystem;

class Game {
public:
    constexpr static const Point2D zeroPoint = {0, 0};

    static Game &getInstance();

private:
    Level::Level *level = nullptr;
    Level::LevelLoader *levelLoader;
    Proxy::GameProxy *gameProxy = nullptr;
    bool exitLevel = false;
    std::map<Common::InputAction, Common::Direction> inputActionDirectionMapping = {
            {Common::InputAction::TURN_UP, Common::Direction::UP},
            {Common::InputAction::TURN_DOWN, Common::Direction::DOWN},
            {Common::InputAction::TURN_LEFT, Common::Direction::LEFT},
            {Common::InputAction::TURN_RIGHT, Common::Direction::RIGHT},
    };

    explicit Game();

    void operator=(Game const &);

    void mainLoop();

    void update();

    void processInput();

public:
    [[nodiscard]] Level::Level *getLevel() const;

    void fireLevelExit(bool win);

    std::vector<Model::LevelInfo> getAvailableLevels();

    void initialize(Model::LevelInfo &levelInfo);

    void setGameProxy(Proxy::GameProxy *proxy);
};


#endif //NOKIASNAKE_GAME_H
