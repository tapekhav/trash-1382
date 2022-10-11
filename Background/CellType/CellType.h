#ifndef LABS_CELLTYPE_H
#define LABS_CELLTYPE_H

#include "../../Events/Event.h"

class CellType {
public:
    virtual ~CellType() = default;
    virtual Event* get_event() = 0;
};

#endif
