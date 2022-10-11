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
#include "../Events/ChangeField/NewLevel.h"
#include "../Events/ChangeField/NewLevel.h"
#include "../Events/ChangeField/NewLevel.h"
#include "../Events/ChangeField/NewLevel.h"

class Cell {
public:
    Cell();

    void set_player_in(bool player_status);
    bool get_player_in() const;

    bool get_passability() const;
    void set_passability(bool pass);

    void set_event(Event* event);
    void update(Player& player, Field& field);
    Event* get_event() const;
private:
    bool player_in;
    bool passability;
    Event* event;
};

#endif
