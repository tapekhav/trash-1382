#include "CellView.h"

CellView::CellView(const Cell& c) {
    if (dynamic_cast<NewLevel*>(c.get_event()) != nullptr) {
        cell = 'n';
    }
    else if (dynamic_cast<Box*>(c.get_event()) != nullptr) {
        cell = 'b';
    }
    else if (dynamic_cast<Heal*>(c.get_event()) != nullptr) {
        cell = 'h';
    }
    else if (dynamic_cast<Key*>(c.get_event()) != nullptr) {
        cell = 'k';
    }
    else if (dynamic_cast<Trap*>(c.get_event()) != nullptr) {
        cell = 't';
    }
    else if (!c.get_pass())
        cell = '/';
    else {
        cell = ' ';
    }
}

char CellView::get_cell() const {
    return cell;
}