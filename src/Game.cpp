
#include "Game.h"
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
        if (exitLevel) {
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
    auto lookingAt = level->getSnake()->lookingAt();
    if (lookingAt < zeroPoint || lookingAt > level->getMapSize()) {
        return;
    }

    auto lookingAtBlock = level->getBlock(lookingAt);
    if (lookingAtBlock != nullptr) {
        if (!lookingAtBlock->isPassable()) {
            level->getSnake()->increaseHealth(-1);
        } else {
            level->getSnake()->moveForward();
            lookingAtBlock->onSnakeStepsOn(level->getSnake());
        }
    } else {
        level->getSnake()->moveForward();
    }
}
