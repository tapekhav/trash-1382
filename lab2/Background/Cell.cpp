#include "Cell.h"

Cell::Cell() : pass(true), event(nullptr) {}

void Cell::update() {
    if (dynamic_cast<EventPlayer*>(event) != nullptr)
        event->execute();
    else if (dynamic_cast<EventField*>(event) != nullptr)
        event->execute();
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
