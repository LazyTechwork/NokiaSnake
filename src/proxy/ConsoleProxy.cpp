#include "ConsoleProxy.h"
#include "../Game.h"

#include <utility>

namespace Proxy {
    void ConsoleProxy::inputHandler() {
        int key;
        while (!firedTermination) {
            if ((key = getch()) != ERR && keyMappings.contains(key))
                actionQueue.push(keyMappings[key]);
        }

        firedTermination = false;
    }

    void ConsoleProxy::terminate() {
        endwin();
    }

    ConsoleProxy::ConsoleProxy() {
        initscr();
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
        init_pair(3, COLOR_WHITE, COLOR_GREEN);
        clear();
        erase();
        noecho();
        raw();
        move(0, 0);
        curs_set(0);
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        refresh();
    }

    ConsoleProxy::~ConsoleProxy() {
        endwin();
    }

    void ConsoleProxy::registerKeyMappings(InputMappings mappings) {
        keyMappings = std::move(mappings);
    }

    void ConsoleProxy::registerKeyMapping(int key, Common::InputAction action) {
        keyMappings[key] = action;
    }

    ActionQueue &ConsoleProxy::getActionQueue() {
        int key;
        while ((key = getch()) != ERR) {
            if (keyMappings.contains(key))
                actionQueue.push(keyMappings[key]);
        }

        return actionQueue;
    }

    void ConsoleProxy::render(const Game &game) {
        renderLevel(*game.getLevel());
        renderSnake(game.getLevel()->getSnake());
    }

    void ConsoleProxy::renderSnake(Level::Snake &snake) {
        std::set<Point2D> snakePos = {snake.getHeadPosition()};
        for (const auto &item: snake.getTail())
            snakePos.insert(item);

        std::set<Point2D> intersection;
        std::set_intersection(
                snakePos.begin(), snakePos.end(), previousSnakePositions->begin(),
                previousSnakePositions->end(), std::inserter(intersection, intersection.begin())
        );

        std::set<Point2D> positionsToClear;
        std::set_difference(
                previousSnakePositions->begin(), previousSnakePositions->end(),
                intersection.begin(), intersection.end(),
                std::inserter(positionsToClear, positionsToClear.begin())
        );

        std::set<Point2D> positionsToRender;
        std::set_difference(
                snakePos.begin(), snakePos.end(),
                intersection.begin(), intersection.end(),
                std::inserter(positionsToRender, positionsToRender.begin())
        );


        previousSnakePositions->insert(positionsToRender.begin(), positionsToRender.end());
        previousSnakePositions->erase(positionsToClear.begin(), positionsToClear.end());

        for (const auto &item: positionsToRender)
            mvaddch(item.y, item.x, 'X' | A_BLINK | A_BOLD | COLOR_PAIR(2));

        refresh();
    }

    void ConsoleProxy::renderBlock(Point2D &pos, Level::Block &block) {
        mvaddch(pos.y, pos.x, ((char) 219) | COLOR_PAIR(1));
    }

    void ConsoleProxy::renderLevel(Level::Level &level) {
        auto mapSize = level.getMapSize();
        for (int16_t y = 0; y < mapSize.y; ++y)
            for (int16_t x = 0; x < mapSize.x; ++x) {
                Point2D pos = {x, y};
                auto block = level.getBlock(pos);
                if (block != nullptr)
                    renderBlock(pos, *block);
            }

        refresh();
    }
} // Common