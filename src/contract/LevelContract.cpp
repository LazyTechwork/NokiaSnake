#include "LevelContract.h"

#include <fstream>

namespace Contract {
    std::ostream &operator<<(std::ostream &s, const LevelContract &contract) {
        s.write((char *) &contract.levelHeader, sizeof(contract.levelHeader));
        s.write((char *) &contract.name, sizeof(contract.name));
        s.write((char *) &contract.snake.position.x, sizeof(contract.snake.position.x));
        s.write((char *) &contract.snake.position.y, sizeof(contract.snake.position.y));
        s.write((char *) &contract.snake.score, sizeof(contract.snake.score));
        s.write((char *) &contract.snake.direction, sizeof(contract.snake.direction));
        s.write((char *) &contract.mapSize.x, sizeof(contract.mapSize.x));
        s.write((char *) &contract.mapSize.y, sizeof(contract.mapSize.y));
        s.write((char *) &contract.predefinedBlocksSize, sizeof(contract.predefinedBlocksSize));
        for (int i = 0; i < contract.predefinedBlocksSize; ++i) {
            auto block = contract.map[i];
            s.write((char *) &block.type, sizeof(block.type));
            s.write((char *) &block.coordinates.x, sizeof(block.coordinates.x));
            s.write((char *) &block.coordinates.y, sizeof(block.coordinates.y));
        }

        return s;
    }

    std::istream &operator>>(std::istream &s, LevelContract &contract) {
        s.read((char *) &contract.levelHeader, sizeof(contract.levelHeader));
        s.read((char *) &contract.name, sizeof(contract.name));
        s.read((char *) &contract.snake.position.x, sizeof(contract.snake.position.x));
        s.read((char *) &contract.snake.position.y, sizeof(contract.snake.position.y));
        s.read((char *) &contract.snake.score, sizeof(contract.snake.score));
        s.read((char *) &contract.snake.direction, sizeof(contract.snake.direction));
        s.read((char *) &contract.mapSize.x, sizeof(contract.mapSize.x));
        s.read((char *) &contract.mapSize.y, sizeof(contract.mapSize.y));
        s.read((char *) &contract.predefinedBlocksSize, sizeof(contract.predefinedBlocksSize));
        contract.map = new LevelContract::MapBlockContract[contract.predefinedBlocksSize];
        for (int i = 0; i < contract.predefinedBlocksSize; ++i) {
            auto block = LevelContract::MapBlockContract{};
            s.read((char *) &block.type, sizeof(block.type));
            s.read((char *) &block.coordinates.x, sizeof(block.coordinates.x));
            s.read((char *) &block.coordinates.y, sizeof(block.coordinates.y));
            contract.map[i] = block;
        }
        return s;
    }
} // Contract