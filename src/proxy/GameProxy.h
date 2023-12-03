#ifndef NOKIASNAKE_GAMEPROXY_H
#define NOKIASNAKE_GAMEPROXY_H

#include <queue>
#include <map>
#include "../common/InputAction.h"

typedef std::queue<Common::InputAction> ActionQueue;
typedef std::map<int, Common::InputAction> InputMappings;

class Game;
namespace Proxy {

    class GameProxy {
    public:
        virtual void terminate() = 0;

        virtual void registerKeyMappings(InputMappings mappings) = 0;

        virtual void registerKeyMapping(int key, Common::InputAction action) = 0;

        virtual ActionQueue &getActionQueue() = 0;

        virtual void render(const Game &game) = 0;
    };

} // Proxy

#endif //NOKIASNAKE_GAMEPROXY_H
