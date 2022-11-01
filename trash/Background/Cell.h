#ifndef LABS_CELL_H
#define LABS_CELL_H


#include <iostream>
#include <algorithm>
#include "../Events/ChangePlayer/Box.h"
#include "../Events/ChangePlayer/Key.h"
#include "../Events/ChangePlayer/Heal.h"
#include "../Events/ChangePlayer/Trap.h"
#include "../Events/ChangeField/SetWalls.h"
#include "../Events/ChangeField/DelWalls.h"


class Cell {
public:
    Cell();

    bool get_pass() const;
    void set_pass(bool);

    void set_event(Event*);
    void update();
    Event* get_event() const;
private:
    bool pass;
    Event* event;
};

#endif
