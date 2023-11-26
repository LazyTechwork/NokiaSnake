#include <iostream>
#include "src/Game.h"
#include "src/proxy/ConsoleProxy.h"

int main() {
    setlocale(LC_ALL, "");
    auto game = Game::getInstance();
    auto proxy = Proxy::ConsoleProxy();
    proxy.inputHandler();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
