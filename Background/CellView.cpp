#include "CellView.h"

CellView::CellView(CellType* c) {
    if (dynamic_cast<CellBox*>(c) != nullptr) {
        cell = 'b';
    }
    else if (dynamic_cast<CellHeal*>(c) != nullptr) {
        cell = 'h';
    }
    else if (dynamic_cast<CellWall*>(c) != nullptr) {
        cell = '/';
    }
    else if (dynamic_cast<CellKey*>(c) != nullptr) {
        cell = 'k';
    }
    else if (dynamic_cast<CellTrap*>(c) != nullptr) {
        cell = 't';
    }
    else if (dynamic_cast<CellNewLevel*>(c) != nullptr) {
        cell = 'n';
    }
    else {
        cell = ' ';
    }
}

char CellView::get_cell() const {
    return cell;
}