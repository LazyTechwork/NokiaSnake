#ifndef NOKIASNAKE_CONSOLEPROXY_H
#define NOKIASNAKE_CONSOLEPROXY_H

#include <queue>
#include <cstdint>
#include <map>
#include <set>
#include "GameProxy.h"
#include "../common/InputAction.h"
#include "../common/Point2D.h"
#include "../level/Block.h"
#include <ncurses.h>

namespace Proxy {

    class ConsoleProxy : public GameProxy {
    private:
        ActionQueue actionQueue = {};
        InputMappings keyMappings;
        bool firedTermination = false;
        std::set<Point2D> *previousSnakePositions = new std::set<Point2D>;

        void renderBlock(Common::Point2D &pos, Level::Block &block);

        void renderLevel(Level::Level &level);

        void renderSnake(Level::Snake &snake);

    public:
        virtual ~ConsoleProxy();

        ConsoleProxy();

        void inputHandler() override;

        void terminate() override;

        void registerKeyMappings(InputMappings mappings) override;

        void registerKeyMapping(int key, Common::InputAction action) override;

        ActionQueue &getActionQueue() override;

        void render(const Game &game) override;
    };

} // Common

#endif //NOKIASNAKE_CONSOLEPROXY_H
