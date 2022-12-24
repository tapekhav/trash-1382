//
// Created by corvussharp on 21.09.22.
//

#include "Cell.h"
#include "../Events/EventsPerson//EventPerson.h"

Cell::Cell() : player_loc(false), passability(true), event(nullptr) {

};


Event *Cell::get_event() const {
    return event;
}

void Cell::update(void *obj) {
    event->execute(nullptr);
}

/*
void Cell::update_field(Field *field) {
    if(auto tmp = dynamic_cast<EventField*>(event))
        tmp ->doing(field);
}
 */

void Cell::set_event(Event *event_) {
    delete this->event;
    this->event = event_;
}


bool Cell::get_passab() const {
    return passability;
}

void Cell::set_passab(bool pass) {
    passability = pass;
}

bool Cell::get_person_in() const {
    return person_in;
}

void Cell::set_person_in(bool in) {
    person_in = in;
}


Cell::~Cell() {
}