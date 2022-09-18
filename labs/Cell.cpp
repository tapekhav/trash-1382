#include "Cell.h"

Cell::Cell() {
    obj = Cell::STANDARD;
}

Cell& Cell::operator=(const Cell &other) {
    if (this != &other)
        Cell(other).swap(*this);

    return *this;
}

Cell::Cell(Cell &&other) {
    this->swap(other);
}

Cell &Cell::operator=(Cell &&other) {
    if (this != &other)
        this->swap(other);
    return *this;
}

Cell::OBJECT Cell::get_obj() const {
    return obj;
}

void Cell::set_obj(Cell::OBJECT obj) {
    this->obj = obj;
}


void Cell::swap(Cell &other) {
    std::swap(obj, other.obj);
}

void Cell::update() {
    event->execute();
}
