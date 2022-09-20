#ifndef LABS_CELLVIEW_H
#define LABS_CELLVIEW_H

#include "Cell.h"

class CellView {
public:
    explicit CellView(const Cell& c);
    char get_cell() const;
private:
    char cell;
};

#endif //LABS_CELLVIEW_H
