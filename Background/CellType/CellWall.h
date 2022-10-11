#ifndef LABS_CELLWALL_H
#define LABS_CELLWALL_H

#include "CellType.h"

class CellWall : public CellType {
public:
    Event* get_event() final;
};


#endif
