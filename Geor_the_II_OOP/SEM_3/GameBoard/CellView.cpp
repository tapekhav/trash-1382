#include "CellView.h"
char CellView::cell_view(Cell *c){
    if(c->is_passable()){
        return '0';
    }
    return 'X';
}
