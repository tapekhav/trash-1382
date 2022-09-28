#include "Cell.h"

Cell::Cell() {
//    this->type = type;
    this->event = nullptr;
    set_player();
};

CellType* Cell::get_type() {
    return this->type;
};

void Cell::set_type(CellType* cell_type) {
    this->type = cell_type;
    set_player();
}

bool Cell::check_player() const {
    return this->player_loc;
}

void Cell::set_player() {
    if (dynamic_cast<PlayerType*>(this->type))
        this->player_loc = true;
    else
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

Cell::Cell(Cell &&other)  noexcept {
    this->swap(other);
}

Cell::Cell(const Cell& other){
    this->player_loc = other.player_loc;
    this->event = other.event;
    this->type = other.type;
}

void Cell::swap(Cell &other) {
    std::swap(type, other.type);
    std::swap(event, other.event);
    std::swap(player_loc, other.player_loc);
}

Cell &Cell::operator=(const Cell& other)= default;


