#ifndef GAME_CELLVIEW_H
#define GAME_CELLVIEW_H


#include "Cell.h"

class CellView{
private:
    enum Color{PASSABLE, NOTPASSABLE, STEPPED};
    Color cellType;
public:
    CellView(const Cell &cell);
    char getCellView() const;
};


#endif
