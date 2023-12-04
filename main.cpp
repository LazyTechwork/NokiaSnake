#include "src/Game.h"
#include "src/proxy/ConsoleProxy.h"
#include "src/contract/UserSettingsContract.h"
#include <ncursesw/ncurses.h>
#include <fstream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "");

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

    proxy->registerResource("border", ('#' | A_DIM | COLOR_PAIR(2)));
    proxy->registerResource("gate:open", (' ' | A_BLINK | COLOR_PAIR(5)));
    proxy->registerResource("gate:closed", ('#' | COLOR_PAIR(5)));
    proxy->registerResource("food", ('@' | A_BOLD | A_BLINK | COLOR_PAIR(4)));
    proxy->registerResource("snake_head", ('0' | COLOR_PAIR(6) | A_BOLD));
    proxy->registerResource("snake_tail", ('&' | COLOR_PAIR(3)));

    game->setGameProxy(proxy);

    while (proxy->renderLevelSelector(*game));

    proxy->terminate();

    delete proxy;
    return 0;
}
