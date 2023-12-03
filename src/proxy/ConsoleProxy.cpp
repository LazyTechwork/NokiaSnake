#include "ConsoleProxy.h"
#include "../Game.h"

#include <utility>

namespace Proxy {
    void ConsoleProxy::terminate() {
        endwin();
    }

    ConsoleProxy::ConsoleProxy() {
        initscr();
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_GREEN, COLOR_BLACK);
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        clear();
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
        renderInfo(*game.getLevel());

        refresh();
    }

    void ConsoleProxy::renderSnake(Level::Snake &snake) {
        std::set<Point2D> snakePos{snake.getHeadPosition()};
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
        for (const auto &item: positionsToClear) {
            previousSnakePositions->erase(item);
            mvaddch(item.y, item.x, ' ' | A_INVIS);
        }

        if (resourceRegistry.contains("snake_tail")) {
            for (const auto &item: positionsToRender)
                mvaddch(item.y, item.x, resourceRegistry["snake_tail"]);
        } else {
            for (const auto &item: positionsToRender)
                mvaddch(item.y, item.x, 'X' | A_BOLD | COLOR_PAIR(3));
        }
    }

    void ConsoleProxy::renderBlock(Point2D &pos, Level::Block &block) {
        if (resourceRegistry.contains(block.getResourceName())) {
            mvaddch(pos.y, pos.x, resourceRegistry[block.getResourceName()]);
        } else {
            mvaddch(pos.y, pos.x, '?' | COLOR_PAIR(1) | A_BLINK | A_BOLD);
        }
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
    }

    void ConsoleProxy::renderInfo(Level::Level &level) {
        auto mapSize = level.getMapSize();
        attron(A_BOLD);
        move(mapSize.y + 2, 0);
        clrtoeol();
        mvprintw(mapSize.y + 2, 0, "Score: %d  Health: %d", level.getSnake().getScore(), level.getSnake().getHealth());
        attroff(A_BOLD);
    }

    bool ConsoleProxy::renderLevelSelector(Game &game) {
        clear();
        auto levelLoader = new Level::LevelLoader("./levels");
        std::vector<Model::LevelInfo> levels = {};
        mvprintw(1, 1, "Select level to load:");
        int y = 1, x = 2;
        for (const auto &levelPath: levelLoader->getLoadedLevels()) {
            auto level = Level::LevelLoader::loadLevel(levelPath);
            if (level == nullptr)
                continue;
            levels.push_back({level->getName(), levelPath});
            mvprintw(++y, x, level->getName().c_str());
            delete level;
        }

        delete levelLoader;

        mvprintw(y + 2, 1, "Press Q to exit the game, use arrow keys to select");

        nodelay(stdscr, FALSE);
        uint16_t levelNum = 1;
        int key = 0;
        do {
            switch (key) {
                case KEY_DOWN:
                    chgat(-1, A_NORMAL, 1, NULL);
                    ++levelNum;
                    break;
                case KEY_UP:
                    chgat(-1, A_NORMAL, 1, NULL);
                    --levelNum;
                    break;
                case 'q':
                    return false;
                default:
                    break;
            }

            if (levelNum < 1)
                levelNum = 1;
            if (levelNum > levels.size())
                levelNum = levels.size();

            move(1 + levelNum, 1);
            chgat(levels[levelNum - 1].name.size() + 2, A_BOLD, 2, NULL);
            refresh();
        } while ((key = getch()) != '\n');
        nodelay(stdscr, TRUE);
        clear();
        game.initialize(levels[levelNum - 1]);
        clear();
        previousSnakePositions->clear();

        mvprintw(3, 2, game.getExitStatus().exitIsWin ? "You have won! Congratulations!"
                                                      : "You've lost. Try your luck next time");
        mvprintw(4, 2, "Final score: %d", game.getExitStatus().finalScore);
        mvprintw(6, 2, "Press any key to continue");

        nodelay(stdscr, FALSE);
        while (getch() == ERR);
        nodelay(stdscr, TRUE);

        return true;
    }

    void ConsoleProxy::registerResource(const std::string &resource, chtype texture) {
        resourceRegistry.insert_or_assign(resource, texture);
    }

    void ConsoleProxy::registerResources(const ResourceRegistry &resources) {
        for (const auto &item: resources)
            registerResource(item.first, item.second);
    }
} // Common