#ifndef GAME_CELLWALL_H
#define GAME_CELLWALL_H


#include "Cell.h"

class CellWall: public Cell{
private:
    bool passable;
public:
    CellWall();
    bool isPassable() const override;
};


#endif
