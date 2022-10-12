#ifndef LABS_CELLTYPE_H
#define LABS_CELLTYPE_H


#include "../../Events/Event.h"
#include "../../Characters/Player.h"

class CellType {
public:
    CellType() = default;
    virtual Event* get_event() = 0;
    virtual ~CellType() = default;
};

#endif
