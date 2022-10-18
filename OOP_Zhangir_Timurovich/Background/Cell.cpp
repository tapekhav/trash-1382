#include <iostream>
#include "Cell.h"

Cell::Cell(Event *event) {
    set_pass(true);
    set_event(event);
    this->player_loc = false;
}


bool Cell::get_pass() const {
    return this->pass;
}


bool Cell::check_player() const {
    return this->player_loc;
}


void Cell::set_event(Event *new_event) {
    this->event = new_event;
}

Cell &Cell::operator=(Cell &&other)

noexcept {
if (this != &other)
this->
swap(other);
return *this;
}

Cell::Cell(Cell &&other)

noexcept {
this->
swap(other);
}

Cell::Cell(const Cell &other) {
    this->player_loc = other.player_loc;
    this->event = other.event;
    this->pass = other.pass;
}

void Cell::swap(Cell &other) {
    std::swap(event, other.event);
    std::swap(player_loc, other.player_loc);
    std::swap(pass, other.pass);
}

Event *Cell::get_event() const {
    return this->event;
}

void Cell::set_player(bool arg) {
    this->player_loc = arg;
}

void Cell::set_pass(bool ps) {
    this->pass = ps;
}

Cell &Cell::operator=(const Cell &other) = default;


