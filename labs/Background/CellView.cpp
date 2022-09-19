#include "CellView.h"

CellView::CellView(const Cell& c) {
    switch(c.get_obj())
    {
        case Cell::STANDARD:
            cell = ' ';
            break;
        case Cell::BOX:
            cell = 'b';
            break;
        case Cell::ENEMY:
            cell = 'e';
            break;
        case Cell::HEAL:
            cell = 'h';
            break;
        case Cell::BARRIER:
            cell = '/';
            break;
        case Cell::PLAYER:
            cell = 'p';
            break;
        default:
            cell = '?';
            break;
    }
}

char CellView::get_cell() const {
    return cell;
}