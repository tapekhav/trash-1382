#include "Cell.h"

Cell::Cell() : player_in(false), passability(true), eventPlayer(nullptr) {}

bool Cell::get_player_in() const {
    return player_in;
}

void Cell::update(Player& player) {
    if (eventPlayer != nullptr)
        eventPlayer->execute(player);
}


void Cell::set_event(EventPlayer* event) {
    delete this->eventPlayer;
    this->eventPlayer = event;
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

EventPlayer *Cell::get_event() const {
    return eventPlayer;
}
