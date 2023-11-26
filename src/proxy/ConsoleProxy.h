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
        InputMappings keyMappings;
        bool firedTermination = false;
    public:
        virtual ~ConsoleProxy();

        ConsoleProxy();

        void inputHandler() override;

        void terminate() override;

        void registerKeyMappings(InputMappings mappings) override;

        void registerKeyMapping(int key, Common::InputAction action) override;

        ActionQueue &getActionQueue() override;
    };

} // Common

#endif //NOKIASNAKE_CONSOLEPROXY_H
