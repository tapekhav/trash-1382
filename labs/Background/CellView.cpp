#include "Cell.h"
#include "CellView.h"


char CellView::getCellView(const Cell& cell) const{
    return view.at(cell.getType());
}

CellView &CellView::operator=(const CellView &) {
    return *this;
}
