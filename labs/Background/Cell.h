#ifndef LABS_CELL_H
#define LABS_CELL_H

class Field;

#include <iostream>
#include <algorithm>
#include "../Events/ChangePlayer/EventPlayer.h"
#include "../Events/ChangeField/EventField.h"

class Cell {
public:
    Cell();

    void set_player_in(bool player_status);
    bool get_player_in() const;

    bool get_passability() const;
    void set_passability(bool pass);

    void set_event(Event* event);
    void update(Player& player);
    Event* get_event() const;
private:
    bool player_in;
    bool passability;
    Event* event;
};

#endif
