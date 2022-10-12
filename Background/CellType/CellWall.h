#ifndef LABS_CELLWALL_H
#define LABS_CELLWALL_H

#include "CellType.h"

class CellWall : public CellType {
public:
    CellWall();
    Event* get_event() override;
    ~CellWall() override = default;
};


#endif
