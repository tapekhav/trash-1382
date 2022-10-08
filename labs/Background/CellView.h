#ifndef LABS_CELLVIEW_H
#define LABS_CELLVIEW_H

#include "Cell.h"
#include "../Events/ChangePlayer/Box.h"
#include "../Events/ChangePlayer/Enemy.h"
#include "../Events/ChangePlayer/Heal.h"

class CellView {
public:
    explicit CellView(const Cell& c);
    char get_cell() const;
private:
    char cell;
};

#endif //LABS_CELLVIEW_H
