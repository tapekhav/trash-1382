#include "CellView.h"

CellView::CellView(Cell c) {
    switch (c.get_obj()) {
        case Cell::coin:
            cell = '$';
            break;
        case Cell::enemy:
            cell = 'e';
            break;
        case Cell::wall_vert:
            cell = '|';
            break;
        case Cell::wall_hor:
            cell = '-';
            break;
        case Cell::heal:
            cell = '@';
            break;
        case Cell::empty:
            cell = ' ';
            break;
        case Cell::player:
            cell = 'p';
            break;
        case Cell::fix:
            cell = '+';
            break;
    }

}


char CellView::get_cell() {
    return this->cell;
}
