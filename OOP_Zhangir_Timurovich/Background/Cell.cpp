#include <iostream>
#include "Cell.h"

Cell::Cell(CellType *cell_type, Event *event) {
    set_pass(cell_type->get_pass());
    set_event(event);
    set_type(cell_type);
};

CellType *Cell::get_type() {
    return this->type;
};

void Cell::set_type(CellType *cell_type) {
    this->type = cell_type;
    this->pass = cell_type->get_pass();
    set_player();
}

bool Cell::get_pass() const {
    return this->pass;
}


bool Cell::check_player() const {
    return this->player_loc;
}

void Cell::set_player() {
    if (dynamic_cast<PlayerType *>(this->type)) {
        this->player_loc = true;
    } else
        this->player_loc = false;
}

void Cell::set_event(Event *new_event) {
    this->event = new_event;
}

Cell &Cell::operator=(Cell &&other) noexcept {
    if (this != &other)
        this->swap(other);
    return *this;
}

Cell::Cell(Cell &&other) noexcept {
    this->swap(other);
}

Cell::Cell(const Cell &other) {
    this->player_loc = other.player_loc;
    this->event = other.event;
    this->type = other.type;
    this->pass = other.pass;
}

void Cell::swap(Cell &other) {
    std::swap(type, other.type);
    std::swap(event, other.event);
    std::swap(player_loc, other.player_loc);
    std::swap(pass, other.pass);
}

Event *Cell::get_event() const {
    return this->event;
}

void Cell::set_pass(bool ps) {
    this->pass = ps;
}

Cell &Cell::operator=(const Cell &other) = default;


