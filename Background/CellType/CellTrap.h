#ifndef LABS_CELLTRAP_H
#define LABS_CELLTRAP_H

#include "CellType.h"
#include "../../Events/ChangePlayer/Trap.h"

class CellTrap : public CellType {
public:
    CellTrap();
    Event* get_event() override;
    ~CellTrap() override;
};


#endif
