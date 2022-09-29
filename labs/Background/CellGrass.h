#ifndef GAME_CELLGRASS_H
#define GAME_CELLGRASS_H


#include "Cell.h"

class CellGrass: public Cell{
private:
    bool passable;
    bool stepped;
public:
    CellGrass();
    bool isPassable() const override;

};


#endif
