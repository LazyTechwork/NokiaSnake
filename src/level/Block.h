
#ifndef NOKIASNAKE_BLOCK_H
#define NOKIASNAKE_BLOCK_H

#include <string>
#include "Snake.h"

namespace Level {

    /**
     * Интерфейс блока - любой сущности на карте (кроме змейки).
     * Может являться как барьером, так и едой.
     */
    class Block {
    protected:
        bool passable = true;
    public:
        /**
         * Событие При нахождении змейки на данном блоке
         * @param snake Змейка
         * @return необходимо ли уничтожить блок после события
         */
        virtual bool onSnakeStepsOn(Snake *snake) = 0;

        [[nodiscard]] bool isPassable() const;
    };

}

#endif //NOKIASNAKE_BLOCK_H
