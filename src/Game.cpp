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
        if (exitLevel || level == nullptr) {
            exitLevel = false;
            return;
        }

        update();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void Game::fireLevelExit() {
    exitLevel = true;
}

void Game::update() {
    level->getPlayer().doTick();
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
