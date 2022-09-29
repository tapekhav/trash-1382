#include "CellGrass.h"

CellGrass::CellGrass(){
    type = Cell::Type(Grass);
    passable = true;
    stepped = false;
}

bool CellGrass::isPassable() const{
    return passable;
};

bool CellGrass::isStepped() const{
    return stepped;
};


void CellGrass::setUnstepped() {
    this->stepped = false;
}

void CellGrass::setStepped() {
    callEvent();
    setEvent(nullptr);
    this->stepped = true;
}
