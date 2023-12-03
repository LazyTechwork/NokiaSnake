#include "LevelLoader.h"
#include "../contract/LevelContract.h"
#include "../Game.h"
#include "BlockFood.h"
#include "BlockBorder.h"
#include "BlockGate.h"
#include <fstream>

namespace Level {
    LevelLoader::LevelLoader(fs::path basePath) : basePath(std::move(basePath)) {
        introspectLevels();
    }

    void LevelLoader::introspectLevels() {
        if (fs::exists(basePath)) {
            if (fs::is_directory(basePath)) {
                for (auto const &dirEntry: std::filesystem::recursive_directory_iterator(basePath)) {
                    if (dirEntry.is_regular_file() && dirEntry.path().extension() == ".level") {
                        loadedLevels.insert(dirEntry.path());
                    }
                }
            }
        } else {
            fs::create_directory(basePath);
        }
    }

    Level *LevelLoader::loadLevel(const fs::path &file) {
        if (fs::exists(file) && fs::is_regular_file(file) && file.extension() == ".level") {
            std::ifstream fStream(file, std::ios::in | std::ios::binary);
            Contract::LevelContract levelContract;
            fStream >> levelContract;
            fStream.close();

            auto level = new Level(levelContract.mapSize, file);
            level->setName(levelContract.name);
            auto map = level->getMap();
            for (int i = 0; i < levelContract.predefinedBlocksSize; ++i) {
                auto blockContract = levelContract.map[i];
                if (blockContract.coordinates > levelContract.mapSize || blockContract.coordinates < Game::zeroPoint)
                    continue;

                Block *block;
                switch (blockContract.type) {
                    case FOOD:
                        block = new BlockFood();
                        break;
                    case BORDER:
                        block = new BlockBorder();
                        break;
                    case GATE:
                        block = new BlockGate();
                        break;
                    default:
                        block = nullptr;
                        break;
                }

                map[blockContract.coordinates.y][blockContract.coordinates.x] = block;
            }
            level->getSnake().setHeadPosition(levelContract.snake.position);
            level->getSnake().setDirection(levelContract.snake.direction);

            for (int i = 0; i < levelContract.snake.score; ++i)
                level->getSnake().pushTail();

            return level;
        }
        return nullptr;
    }

    const std::set<fs::path> &LevelLoader::getLoadedLevels() const {
        return loadedLevels;
    }
} // Level