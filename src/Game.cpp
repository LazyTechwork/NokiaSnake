
#include "Game.h"

Game::Game() {
    levelLoader = new Level::LevelLoader();
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
