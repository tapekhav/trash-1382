#ifndef LABS_CELL_H
#define LABS_CELL_H

#include <iostream>
#include <algorithm>
#include "../Events/Box.h"
#include "../Events/Enemy.h"
#include "../Events/Heal.h"

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

#endif //LABS_CELL_H
