#include "CellView.h"

CellView::CellView(const Cell& c) {
    if (!c.get_pass()) {
        cell = '/';
        return;
    }
    if (dynamic_cast<Key*>(c.get_event()) != nullptr) {
        cell = 'k';
        return;
    }
    if (dynamic_cast<Box*>(c.get_event()) != nullptr) {
        cell = 'b';
        return;
    }
    if (dynamic_cast<Heal*>(c.get_event()) != nullptr) {
        cell = 'h';
        return;
    }
    if (dynamic_cast<Trap*>(c.get_event()) != nullptr) {
        cell = 't';
        return;
    }
    if (dynamic_cast<DelWalls*>(c.get_event()) != nullptr) {
        cell = 'd';
        return;
    }
    if (dynamic_cast<SetWalls*>(c.get_event()) != nullptr) {
        cell = 'w';
        return;
    }
    cell = ' ';
}

char CellView::get_cell() const {
    return cell;
}