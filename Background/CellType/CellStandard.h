#ifndef LABS_CELLSTANDARD_H
#define LABS_CELLSTANDARD_H

#include "CellType.h"

class CellStandard : CellType {
public:
    Event* get_event() final;
};

#endif
