#ifndef GAME_CELLPLAYER_H
#define GAME_CELLPLAYER_H

#include "Cell.h"


class CellPlayer: public Cell{
private:
    bool passable;
public:
    CellPlayer();
    bool isPassable() const override;
};


#endif
