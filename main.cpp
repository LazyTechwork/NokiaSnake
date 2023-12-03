#include <iostream>
#include "src/Game.h"
#include "src/proxy/ConsoleProxy.h"
#include "src/contract/UserSettingsContract.h"
#include <ncurses.h>
#include <fstream>
#include <thread>

int main() {
    setlocale(LC_ALL, "");

    auto levelLoader = new Level::LevelLoader("./levels");
    std::vector<Model::LevelInfo> levels = {};
    std::cout << "Select level to load" << std::endl;
    for (const auto &levelPath: levelLoader->getLoadedLevels()) {
        auto level = Level::LevelLoader::loadLevel(levelPath);
        if (level == nullptr)
            continue;
        levels.push_back({level->getName(), levelPath});
        std::cout << levels.size() << ". " << level->getName() << std::endl;
        delete level;
    }

    uint16_t levelNum;
    do {
        std::cout << "Select level by number: " << std::flush;
        std::cin >> levelNum;
        std::cout << std::endl << "Trying to load level #" << levelNum << std::endl;
    } while (!(levelNum >= 1 && levelNum <= levels.size()));

    auto game = Game::getInstance();
    auto proxy = new Proxy::ConsoleProxy();
    if (!std::filesystem::exists("./settings.dat")) {
        std::ofstream settingsFile("./settings.dat", std::ios::out | std::ios::binary);
        settingsFile << Contract::UserSettingsContract{
                "Player", 5, {
                        {KEY_UP, Common::InputAction::TURN_UP},
                        {KEY_DOWN, Common::InputAction::TURN_DOWN},
                        {KEY_LEFT, Common::InputAction::TURN_LEFT},
                        {KEY_RIGHT, Common::InputAction::TURN_RIGHT},
                        {'q', Common::InputAction::EXIT},
                        {' ', Common::InputAction::PAUSE},
                }
        };
        settingsFile.close();
    }
    Contract::UserSettingsContract userSettings;
    std::ifstream settingsFile("./settings.dat", std::ios::in | std::ios::binary);
    settingsFile >> userSettings;
    settingsFile.close();
    proxy->registerKeyMappings(userSettings.keyMappings);
    game.setGameProxy(proxy);

    game.initialize(levels[levelNum - 1]);
    proxy->terminate();

    delete levelLoader;
    delete proxy;
    return 0;
}
