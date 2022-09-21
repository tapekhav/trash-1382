#include "Cell.h"

Cell::Cell(bool passable, bool stepped): passable(passable), stepped(stepped){};

bool Cell::isPassable() const{
        return passable;
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