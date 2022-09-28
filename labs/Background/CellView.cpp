#include "CellView.h"

CellView::CellView(const Cell& c) {
    if (c.get_player_in())
        cell = 'p';
    else if (dynamic_cast<Box*>(c.get_event()) != nullptr)
        cell = 'b';
    else if (dynamic_cast<Heal*>(c.get_event()) != nullptr)
        cell = 'h';
    else if (dynamic_cast<Enemy*>(c.get_event()) != nullptr)
        cell = 'e';
    else if (!c.get_passability())
        cell = '/';
    else {
        cell = ' ';
    }
}

char CellView::get_cell() const {
    return cell;
}