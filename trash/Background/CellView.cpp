#include "CellView.h"

CellView::CellView(const Cell& c) {
    if (c.get_event() != nullptr) {
        cell = 'e';
        return;
    }
    if (!c.get_pass()) {
        cell = '/';
        return;
    }
    cell = ' ';

}

char CellView::get_cell() const {
    return cell;
}