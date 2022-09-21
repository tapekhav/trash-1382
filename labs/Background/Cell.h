#ifndef LABS_CELL_H
#define LABS_CELL_H

#include <iostream>
#include "../Events/Event.h"
#include <algorithm>

class Cell {
public:
    enum OBJECT {
        STANDARD,
        ENEMY,
        BOX,
        HEAL,
        BARRIER,
        PLAYER
    };
    Cell();

    void set_obj(OBJECT obj);
    OBJECT get_obj() const;

    void set_event(Event* event);
    void update(Player& player);
private:
    OBJECT obj;
    Event* event;
};

#endif //LABS_CELL_H
