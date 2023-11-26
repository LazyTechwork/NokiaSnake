#include "ConsoleProxy.h"
#include <ncurses.h>

#include <utility>

namespace Proxy {
    void ConsoleProxy::inputHandler() {
        int key;
        while (!firedTermination) {
            if ((key = getch()) != ERR && keyMappings.contains(key)) {
                actionQueue.push(keyMappings[key]);
                mvwprintw(stdscr, 0, 0, "Used action: %d", keyMappings[key]);
                refresh();
            }
        }

        firedTermination = false;
    }

    void ConsoleProxy::terminate() {
        firedTermination = true;
    }

    ConsoleProxy::ConsoleProxy() {
        initscr();
        erase();
        noecho();
        raw();
        move(0, 0);
        curs_set(0);
        keypad(stdscr, TRUE);
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
        return actionQueue;
    }
} // Common