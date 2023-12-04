#include "Game.h"
#include "Player.h"
#include "contract/LevelContract.h"
#include "level/BlockFood.h"
#include "level/BlockGate.h"
#include <filesystem>
#include <chrono>
#include <thread>
#include <fstream>

Game *Game::_instance = nullptr;

Game::Game() {
    levelLoader = new Level::LevelLoader(
            fs::absolute(fs::current_path().append("levels"))
    );
    std::random_device rd;
    randomEngine.seed(rd());
};

Game * Game::getInstance() {
    if (_instance == nullptr)
        _instance = new Game();

    return _instance;
}

Level::Level *Game::getLevel() const {
    return level;
}

void Game::mainLoop() {
    while (true) {
        if (level == nullptr) {
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
    generateFood();

    level->getPlayer().doTick();

    if (level->getSnake().getHealth() <= 0)
        fireLevelExit(false);

    if (level->getSnake().getScore() == 15) {
        Level::Block *gateBlock = nullptr;
        auto mapSize = level->getMapSize();
        for (int16_t y = 0; y < mapSize.y; ++y) {
            for (int16_t x = 0; x < mapSize.x; ++x) {
                auto block = level->getBlock({x, y});
                if (block != nullptr && block->getResourceName() == "gate:closed") {
                    gateBlock = block;
                    break;
                }
            }
            if (gateBlock != nullptr)
                break;
        }

        if (gateBlock != nullptr)
            gateBlock->setPassable(true);
    }
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

void Game::generateFood() {
    auto foodOnLevel = level->countFood();
    std::uniform_int_distribution<> xRange(0, level->getMapSize().x - 1);
    std::uniform_int_distribution<> yRange(0, level->getMapSize().y - 1);
    while (foodOnLevel < maxFoodOnLevel) {
        Point2D pos{(int16_t) xRange(randomEngine), (int16_t) yRange(randomEngine)};
        if (level->getBlock(pos) == nullptr) {
            level->setBlock(new Level::BlockFood(), pos);
            ++foodOnLevel;
        }
    }
}
