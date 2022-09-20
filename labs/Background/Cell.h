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
    explicit Cell();
    OBJECT get_obj() const;
    void update(Player& player);
    void set_event(Event* event);
    void set_obj(OBJECT obj);
private:
    OBJECT obj;
    Event* event;
};

#endif //LABS_CELL_H
