#include "Player.h"
#include "Game.h"

Player::Player(Level::Level *level) : level(level) {}

void Player::doTick() {
    auto lookingAt = level->getSnake().getHeadPosition() + level->getSnake().lookingAt();
    if (lookingAt < Game::zeroPoint || lookingAt > level->getMapSize()) {
        return;
    }

    auto lookingAtBlock = level->getBlock(lookingAt);
    if (lookingAtBlock != nullptr) {
        if (!lookingAtBlock->isPassable()) {
            damageEvent.dispatch(level->getSnake(), *lookingAtBlock);
        } else {
            level->getSnake().moveForward();
            if(lookingAtBlock->onSnakeStepsOn(level->getSnake())) {
                level->destroyBlock(lookingAt);
            }
        }
    } else {
        level->getSnake().moveForward();
    }
}
