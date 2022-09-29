#include "CellWall.h"

CellWall::CellWall() {
    type = Cell::Type(Wall);
    passable = false;
}

bool CellWall::isPassable() const{
    return passable;
};
