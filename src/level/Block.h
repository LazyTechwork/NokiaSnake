#ifndef NOKIASNAKE_BLOCK_H
#define NOKIASNAKE_BLOCK_H

#include <string>
#include "Snake.h"
#include "../event/BlockEvent.h"

namespace Level {

    /**
     * Интерфейс блока - любой сущности на карте (кроме змейки).
     * Может являться как барьером, так и едой.
     */
    class Block {
    private:
        Event::BlockEvent *snakeStepsOnEvent = nullptr;
    protected:
        bool passable = true;
    public:
        /**
         * Событие При нахождении змейки на данном блоке
         * @param snake Змейка
         * @return необходимо ли уничтожить блок после события
         */
        bool onSnakeStepsOn(Snake &snake);

        void setSnakeStepsOnEvent(Event::BlockEvent *snakeStepsOnEvent);

        [[nodiscard]] bool isPassable() const;

        [[nodiscard]] virtual std::string getResourceName() const = 0;
    };

}

#endif //NOKIASNAKE_BLOCK_H
