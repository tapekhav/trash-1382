#include "Field/Cell.h"

Cell::Cell(const Cell& obj) {
    mWall = obj.mWall;
    mEvent = obj.mEvent;
}

Cell& Cell::operator=(const Cell& other) {
    if (this == &other)
        return *this;
    mWall = other.mWall;
    mEvent = other.mEvent;
    return *this;
}


void Cell::ActiveEvent() {
    return;
}
