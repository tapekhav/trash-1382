#include "CellPlayer.h"

CellPlayer::CellPlayer() {
    type = Cell::Type(Player);
    passable = false;
}

bool CellPlayer::isPassable() const {
    return passable;
}
