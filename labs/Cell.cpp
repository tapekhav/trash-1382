#include "Cell.h"
#include "Event.h"

Cell::Cell(bool passable, bool stepped): passable(passable), stepped(stepped){};

bool Cell::isPassable() const{
    return passable;
};

const Cell& Cell::getCell() const{
    return *this;
};

bool Cell::isStepped() const{
    return stepped;
};

void Cell::setUnstepped() {
    this->stepped = false;
}

void Cell::setStepped() {
    this->stepped = true;
}

void Cell::setEvent(Event* event){
    this->event = event;
}