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
#include <ncursesw/ncurses.h>

typedef std::map<std::string, chtype> ResourceRegistry;
namespace Proxy {

    class ConsoleProxy : public GameProxy {
    private:
        ActionQueue actionQueue = {};
        InputMappings keyMappings;
        ResourceRegistry resourceRegistry;
        std::set<Point2D> *previousSnakePositions = new std::set<Point2D>;

        void renderBlock(Common::Point2D &pos, Level::Block &block);

        void renderLevel(Level::Level &level);

        void renderSnake(Level::Snake &snake);

        void renderInfo(Level::Level &level);

    public:
        virtual ~ConsoleProxy();

        ConsoleProxy();

        void terminate() override;

        void registerKeyMappings(InputMappings mappings) override;

        void registerKeyMapping(int key, Common::InputAction action) override;

        void registerResource(const std::string &resource, chtype texture);

        void registerResources(const ResourceRegistry &resources);

        ActionQueue &getActionQueue() override;

        void render(const Game &game) override;

        bool renderLevelSelector(Game &game);
    };

} // Common

#endif //NOKIASNAKE_CONSOLEPROXY_H
