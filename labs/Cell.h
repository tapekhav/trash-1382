#ifndef LABS_CELL_H
#define LABS_CELL_H

#include <iostream>
#include "structs.h"
#include "Event.h"
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
    Cell(const Cell& other) = default;
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);
    OBJECT get_obj() const;
    void update();
    void set_obj(OBJECT obj);

private:
    void swap(Cell &other);
    OBJECT obj;
    Event* event;
};

#endif //LABS_CELL_H
