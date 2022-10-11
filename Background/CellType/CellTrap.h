#ifndef LABS_CELLTRAP_H
#define LABS_CELLTRAP_H

#include "CellType.h"
#include "../../Events/ChangePlayer/Trap.h"

class CellTrap : public CellType {
public:
    CellTrap();
    ~CellTrap() override = default;
    Event* get_event() final;
private:
    Event* event;
};


#endif
