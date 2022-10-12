#include "CellView.h"

CellView::CellView(Cell c) {
    CellType *type = c.get_type();
    if (type) {
        if (dynamic_cast<CoinType *>(type)) {
            view = '$';
        } else if (dynamic_cast<EnemyType *>(type)) {
            view = 'e';
        } else if (dynamic_cast<WallVertType *>(type)) {
            view = '|';
        } else if (dynamic_cast<WallHorType *>(type)) {
            view = '-';
        } else if (dynamic_cast<HealType *>(type)) {
            view = '@';
        } else if (dynamic_cast<EmptyType *>(type)) {
            view = ' ';
        } else if (dynamic_cast<PlayerType *>(type)) {
            view = 'p';
        } else if (dynamic_cast<StoneType *>(type)) {
            view = '*';
        } else if (dynamic_cast<CollapseType *>(type)) {
            view = '?';
        } else if (dynamic_cast<IncreaseType *>(type)) {
            view = '+';
        } else if (dynamic_cast<DecreaseType *>(type)) {
            view = '-';
        }
    }

}


char CellView::get_view() const {
    return this->view;
}
