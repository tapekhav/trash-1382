#include "Cell.h"

Cell::Cell() : player_in(false), passability(true), event(nullptr) {}

bool Cell::get_player_in() const {
    return player_in;
}

void Cell::update(Player& player, Field& field) {
    if (auto tmp = dynamic_cast<EventPlayer*>(event))
        tmp->execute(player);
    else if (auto tmp = dynamic_cast<EventField*>(event))
        tmp->execute(field);
}


void Cell::set_event(Event* event) {
    this->event = event;
}

void Cell::set_player_in(bool player_status) {
    player_in = player_status;
}

void Cell::set_passability(bool pass) {
    passability = pass;
}

bool Cell::get_passability() const {
    return passability;
}

Event *Cell::get_event() const {
    return event;
}

