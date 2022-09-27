#include "CellView.h"

CellView::CellView(Cell c) {
    switch (c.get_obj()) {
        case Cell::coin:
            view = '$';
            break;
        case Cell::enemy:
            view = 'e';
            break;
        case Cell::wall_vert:
            view = '|';
            break;
        case Cell::wall_hor:
            view = '-';
            break;
        case Cell::heal:
            view = '@';
            break;
        case Cell::empty:
            view = ' ';
            break;
        case Cell::player:
            view = 'p';
            break;
        case Cell::fix:
            view = '+';
            break;
    }

}


char CellView::get_view() {
    return this->view;
}
