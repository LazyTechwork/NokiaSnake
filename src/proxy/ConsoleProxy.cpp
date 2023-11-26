#include "ConsoleProxy.h"
#include <ncurses.h>

namespace Proxy {
    void ConsoleProxy::inputHandler() {
        int key;
        while (!firedTermination && (key = getch()) != ERR) {
            inputQueue.push(key);
            mvwprintw(stdscr, 0, 0, "Key pressed is = %3d Hopefully it can be printed as '%c'", key, key);
            refresh();
        }
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
} // Proxy