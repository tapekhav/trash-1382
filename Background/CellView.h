#ifndef LABS_CELLVIEW_H
#define LABS_CELLVIEW_H

#include "Cell.h"
#include "../Events/ChangePlayer/Box.h"
#include "../Events/ChangePlayer/Key.h"
#include "../Events/ChangePlayer/Heal.h"
#include "../Events/ChangePlayer/Trap.h"

class CellView {
public:
    explicit CellView(Cell&& c);
    char get_cell() const;
private:
    char cell;
};

#endif //LABS_CELLVIEW_H
