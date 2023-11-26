#ifndef NOKIASNAKE_CONSOLEPROXY_H
#define NOKIASNAKE_CONSOLEPROXY_H

#include <queue>
#include <cstdint>

namespace Proxy {

    class ConsoleProxy {
    private:
        std::queue<int> inputQueue = {};
        bool firedTermination = false;
    public:
        virtual ~ConsoleProxy();

        ConsoleProxy();
        void inputHandler();
        void terminate();
    };

} // Proxy

#endif //NOKIASNAKE_CONSOLEPROXY_H
