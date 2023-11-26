#include <iostream>
#include "src/Game.h"
#include "src/proxy/ConsoleProxy.h"
#include "src/contract/UserSettingsContract.h"
#include <ncurses.h>
#include <fstream>

int main() {
    setlocale(LC_ALL, "");
    auto game = Game::getInstance();

    auto proxy = Proxy::ConsoleProxy();
    if (!std::filesystem::exists("./settings.dat")) {
        std::ofstream settingsFile("./settings.dat", std::ios::out | std::ios::binary);
        settingsFile << Contract::UserSettingsContract{
                "Player", 5, {
                        {KEY_UP, Common::InputAction::TURN_UP},
                        {KEY_DOWN, Common::InputAction::TURN_DOWN},
                        {KEY_LEFT, Common::InputAction::TURN_LEFT},
                        {KEY_RIGHT, Common::InputAction::TURN_RIGHT},
                        {' ', Common::InputAction::PAUSE},
                }
        };
        settingsFile.close();
    }
    Contract::UserSettingsContract userSettings;
    std::ifstream settingsFile("./settings.dat", std::ios::in | std::ios::binary);
    settingsFile >> userSettings;
    settingsFile.close();
    proxy.registerKeyMappings(userSettings.keyMappings);
    proxy.inputHandler();

    game.setGameProxy(proxy);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
