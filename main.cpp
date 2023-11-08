#include <iostream>
#include "src/Game.h"

int main() {
    auto game = Game::getInstance();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
