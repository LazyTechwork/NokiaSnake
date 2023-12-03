#include "Game.h"
#include "Player.h"
#include "contract/LevelContract.h"
#include <filesystem>
#include <chrono>
#include <thread>
#include <fstream>

Game::Game() {
    levelLoader = new Level::LevelLoader(
            fs::absolute(fs::current_path().append("levels"))
    );
};

Game &Game::getInstance() {
    static Game instance;
    return instance;
}

Level::Level *Game::getLevel() const {
    return level;
}

void Game::mainLoop() {
    while (true) {
        if (level== nullptr) {
            exitStatus.exitIsWin = false;
            exitStatus.finalScore = 0;
            return;
        }
        if (exitLevel) {
            exitStatus.finalScore = level->getSnake().getScore();
            return;
        }

        processInput();
        update();
        gameProxy->render(*this);

        std::this_thread::sleep_for(std::chrono::milliseconds(420));
    }
}

void Game::fireLevelExit(bool win) {
    exitLevel = true;
    exitStatus.exitIsWin = win;
}

void Game::update() {
    level->getPlayer().doTick();
    if (level->getSnake().getHealth() <= 0)
        fireLevelExit(false);
}

std::vector<Model::LevelInfo> Game::getAvailableLevels() {
    levelLoader->introspectLevels();
    std::vector<Model::LevelInfo> levels{};
    auto levelFiles = levelLoader->getLoadedLevels();
    for (const auto &levelFile: levelFiles) {
        std::ifstream fd(levelFile, std::ios::in | std::ios::binary);
        Contract::LevelContract contract;
        fd >> contract;
        fd.close();
        levels.push_back(Model::LevelInfo{
                contract.name,
                levelFile
        });
    }
    return levels;
}

void Game::setGameProxy(Proxy::GameProxy *proxy) {
    gameProxy = proxy;
}

void Game::processInput() {
    while (!gameProxy->getActionQueue().empty()) {
        auto action = gameProxy->getActionQueue().front();
        switch (action) {
            case Common::InputAction::TURN_LEFT:
            case Common::InputAction::TURN_RIGHT:
            case Common::InputAction::TURN_UP:
            case Common::InputAction::TURN_DOWN:
                level->getSnake().setDirection(inputActionDirectionMapping[action]);
                break;
            case Common::InputAction::EXIT:
                fireLevelExit(false);
                break;
            default:
                break;
        }
        gameProxy->getActionQueue().pop();
    }
}

void Game::initialize(Model::LevelInfo &levelInfo) {
    exitLevel = false;
    auto loadedLevel = Level::LevelLoader::loadLevel(levelInfo.path);
    this->level = loadedLevel;
    mainLoop();
}

const Game::ExitStatus &Game::getExitStatus() const {
    return exitStatus;
}
