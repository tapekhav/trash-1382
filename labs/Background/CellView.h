#ifndef GAME_CELLVIEW_H
#define GAME_CELLVIEW_H


#include <map>
#include "Cell.h"

class CellView{
private:
    const std::map<Cell::Type, char> view = {
            {Cell::Grass, ' '},
            {Cell::Player, '*'},
            {Cell::Wall, '#'},
            {Cell::Empty, '?'}
    };
public:
    char getCellView(const Cell& cell) const;
    CellView &operator=(const CellView&);
};


#endif