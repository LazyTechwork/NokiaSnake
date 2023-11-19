#include <iostream>
#include "src/Game.h"
#include "src/contract/LevelContract.h"
#include <fstream>

int main() {
    auto game = Game::getInstance();
    /*auto l = Contract::LevelContract{
            "LVLFH",
            "Test Level",
            {
                    {5, 5}, 1, Direction::UP
            },
            {25, 25},
            7,
            new Contract::LevelContract::MapBlockContract[7]{
                    {MapBlockType::BORDER, {0, 0}},
                    {MapBlockType::BORDER, {1, 0}},
                    {MapBlockType::BORDER, {2, 0}},
                    {MapBlockType::GATE,   {3, 0}},
                    {MapBlockType::BORDER, {4, 0}},
                    {MapBlockType::BORDER, {5, 0}},
                    {MapBlockType::BORDER, {6, 0}},
            }
    };

    std::ofstream levelFile("./levels/test.level", std::ios::binary | std::ios::out);
    levelFile << l;
    levelFile.close();

    auto readLevel = Contract::LevelContract{};
    std::ifstream iLevelFile("./levels/test.level", std::ios::binary | std::ios::in);
    iLevelFile >> readLevel;
    iLevelFile.close();

     */

    std::vector<Contract::LevelContract::MapBlockContract> map;
    std::string stringMap[] = {
            "BBBBBBBBBBBBBBBBBBBBBBBBB",
            "B                       B",
            "B     BBBBBBBBBBBBB     B",
            "B   BBB           BBB   B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       G",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B   BBB           BBB   B",
            "B     BBBBBBBBBBBBB     B",
            "B                       B",
            "BBBBBBBBBBBBBBBBBBBBBBBBB"
    };

    /*std::string stringMap[] = {
            "BBBBBBBBBBBBBBBBBBBBBBBBB",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B   BBBBBBBBBBBBBBBBB   B",
            "B                       B",
            "B                       B",
            "B       BBBBBBBBB       B",
            "B                       G",
            "B                       B",
            "B                       B",
            "B       BBBBBBBBB       B",
            "B                       B",
            "B                       B",
            "B   BBBBBBBBBBBBBBBBB   B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "B                       B",
            "BBBBBBBBBBBBBBBBBBBBBBBBB"
    };*/

    /*for (int16_t y = 0; y < 25; ++y) {
        auto s = stringMap[y];
        for (int16_t x = 0, l = s.length(); x < l; ++x) {
            switch (s[x]) {
                case 'B':
                    map.push_back({MapBlockType::BORDER, {x, y}});
                    break;
                case 'G':
                    map.push_back({MapBlockType::GATE, {x, y}});
                    break;
                case 'F':
                    map.push_back({MapBlockType::FOOD, {x, y}});
                    break;
                default:
                    break;
            }
        }
    }

    auto l = Contract::LevelContract{
            "LVLFH",
            "Level 1",
            {{25 / 2, 25 / 2}, 1, Direction::UP},
            {25, 25},
            (uint16_t) map.size(),
            map.data()
    };

    std::ofstream levelFile("./levels/standard_level1.level", std::ios::binary | std::ios::out);
    levelFile << l;
    levelFile.close();*/

    auto l = Level::LevelLoader::loadLevel("./levels/standard_level1.level");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
