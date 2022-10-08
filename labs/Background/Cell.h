#ifndef LABS_CELL_H
#define LABS_CELL_H

#include <iostream>
#include <algorithm>
#include "../Events/ChangePlayer/EventPlayer.h"
//#include "../Events/ChangeField/EventField.h"

class Cell {
public:
    Cell();

    void set_player_in(bool player_status);
    bool get_player_in() const;

    bool get_passability() const;
    void set_passability(bool pass);

    void set_event(EventPlayer* event);
    void update(Player& player);
    EventPlayer* get_event() const;
private:
    bool player_in;
    bool passability;
    EventPlayer* eventPlayer;
    //EventField* eventField;
};

#endif //LABS_CELL_H
