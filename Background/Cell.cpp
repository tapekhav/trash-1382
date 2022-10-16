#include "Cell.h"

Cell::Cell() : pass(true), event(nullptr) {}

void Cell::update(Player& player, Field& field) {
    if (auto tmp = dynamic_cast<EventPlayer*>(event))
        tmp->execute(player);
    else if (auto tmp = dynamic_cast<EventField*>(event))
        tmp->execute(field);
}


void Cell::set_event(Event* event) {
    delete this->event;
    this->event = event;
}

void Cell::set_pass(bool pass) {
    this->pass = pass;
}

bool Cell::get_pass() const {
    return pass;
}

Event *Cell::get_event() const {
    return event;
}
