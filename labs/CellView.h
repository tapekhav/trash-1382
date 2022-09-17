#ifndef LABS_CELLVIEW_H
#define LABS_CELLVIEW_H

#include "Cell.h"
#include "structs.h"

class CellView {
public:
    CellView() = default;
    ~CellView() = default;
    explicit CellView(const Cell& c);
    char get_cell() const;
private:
    char cell;
};

#endif //LABS_CELLVIEW_H
