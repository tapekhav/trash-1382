#ifndef LABS_CELL_H
#define LABS_CELL_H

class Field;

#include <iostream>
#include <algorithm>
#include "../Events/ChangePlayer/Box.h"
#include "../Events/ChangePlayer/Key.h"
#include "../Events/ChangePlayer/Heal.h"
#include "../Events/ChangePlayer/Trap.h"
#include "../Events/ChangeField/NewLevel.h"

class Cell {
public:
    Cell();

    bool get_pass() const;
    void set_pass(bool pass);

    void set_event(Event* event);
    void update();
    Event* get_event() const;
private:
    bool pass;
    Event* event;
};

#endif
