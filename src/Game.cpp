#include "Game.h"
#include "Player.h"
#include <filesystem>
#include <chrono>
#include <thread>

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
    level->getPlayer()->doTick();
}
