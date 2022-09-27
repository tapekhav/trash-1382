#include "Cell.h"

Cell::Cell(Cell::TYPE type) {
    this->obj = type;
    set_player();
};

Cell::TYPE Cell::get_obj() {
    return this->obj;
};

void Cell::set_obj(Cell::TYPE type) {
    this->obj = type;
    set_player();
}

bool Cell::check_player() const {
    return this->player_loc;
}

void Cell::set_player() {
    if (this->obj == Cell::player)
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
    this->obj = other.obj;
}

void Cell::swap(Cell &other) {
    std::swap(obj, other.obj);
}

Cell &Cell::operator=(const Cell& other)= default;


