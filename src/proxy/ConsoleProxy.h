#ifndef NOKIASNAKE_CONSOLEPROXY_H
#define NOKIASNAKE_CONSOLEPROXY_H

#include <queue>
#include <cstdint>
#include <map>
#include "GameProxy.h"
#include "../common/InputAction.h"

namespace Proxy {

    class ConsoleProxy : public GameProxy {
    private:
        ActionQueue actionQueue = {};
        std::map<int, Common::InputAction> keyMappings;
        bool firedTermination = false;
    public:
        virtual ~ConsoleProxy();

        ConsoleProxy();

        void inputHandler();

        void terminate();

        void registerKeyMappings(std::map<int, InputAction> mappings);

        void registerKeyMapping(int key, InputAction action);

        ActionQueue &getActionQueue();
    };

} // Common

#endif //NOKIASNAKE_CONSOLEPROXY_H
