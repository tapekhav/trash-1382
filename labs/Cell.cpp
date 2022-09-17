#include "Cell.h"

Cell::Cell() : obj(STANDARD) {}

Cell::Cell(const Cell& other) : obj(other.obj) {}

OBJECT Cell::get_obj() const {
    return obj;
}

void Cell::set_obj(OBJECT obj) {
    this->obj = obj;
}

Cell& Cell::operator=(const Cell &other) {
    if (this != &other)
        Cell(other).swap(*this);

    return *this;
}

void Cell::swap(Cell &other) {
    std::swap(obj, other.obj);
}

Cell::Cell(Cell &&other) {
    this->swap(other);
}

Cell &Cell::operator=(Cell &&other) {
    if (this != &other)
        this->swap(other);
    return *this;
}
