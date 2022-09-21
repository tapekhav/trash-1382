#include "Cell.h"
#include "CellView.h"

CellView::CellView(const Cell &cell) {
    if(cell.isStepped()){
        this->cellType = Color(STEPPED);
    }else if (cell.isPassable()){
        this->cellType = Color(PASSABLE);
    }else {
        this->cellType = Color(NOTPASSABLE);
    }
}

char CellView::getCellView() const{
    switch (cellType) {
        case 2: return '*';
        case 1: return '#';
        case 0: return ' ';
        default: return '?';
    }
}