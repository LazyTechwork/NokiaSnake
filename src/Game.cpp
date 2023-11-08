
#include "Game.h"
#include <filesystem>

Game::Game() {
    levelLoader = new Level::LevelLoader(fs::absolute(fs::current_path().append("levels")));
};

Game &Game::getInstance() {
    static Game instance;
    return instance;
}

Level::Level *Game::getLevel() const {
    return level;
}

void Game::mainLoop() {

}
