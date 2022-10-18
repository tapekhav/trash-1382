#include "CellView.h"

CellView::CellView(Cell c) {
    Event *type = c.get_event();
    if (dynamic_cast<GetCoin *>(type)) {
        view = '$';
    } else if (dynamic_cast<Enemy *>(type)) {
        view = 'e';
    } else if (dynamic_cast<Heal *>(type)) {
        view = '@';
    } else if (dynamic_cast<Collapse *>(type)) {
        view = '?';
    } else if (dynamic_cast<Increase *>(type)) {
        view = '+';
    } else if (dynamic_cast<Decrease *>(type)) {
        view = '-';
    } else if (c.get_pass())
        view = ' ';
    else
        view = '*';

}


char CellView::get_view() const {
    return this->view;
}
