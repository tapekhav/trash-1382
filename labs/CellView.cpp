#include "CellView.h"

CellView::CellView(const Cell& c) {
    switch(c.get_obj())
    {
        case STANDARD:
            cell = ' ';
            break;
        case BOX:
            cell = 'b';
            break;
        case ENEMY:
            cell = 'e';
            break;
        case HEAL:
            cell = 'h';
            break;
        case BARRIER:
            cell = '/';
            break;
        case PLAYER:
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