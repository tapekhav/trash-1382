#include "Cell.h"

Cell::Cell() : obj(STANDARD) {}

Cell::OBJECT Cell::get_obj() const {
    return obj;
}

void Cell::update(Player& player) {
    event->execute(player);
}

void Cell::set_event(Event* event) {
    this->event = event;
}

void Cell::set_obj(Cell::OBJECT obj) {
    this->obj = obj;
}
