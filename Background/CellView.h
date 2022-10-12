#ifndef LABS_CELLVIEW_H
#define LABS_CELLVIEW_H

#include "CellType/CellWall.h"
#include "CellType/CellBox.h"
#include "CellType/CellHeal.h"
#include "CellType/CellKey.h"
#include "CellType/CellNewLevel.h"
#include "CellType/CellStandard.h"
#include "CellType/CellTrap.h"

class CellView {
public:
    explicit CellView(CellType* c);
    char get_cell() const;
private:
    char cell;
};

#endif //LABS_CELLVIEW_H
