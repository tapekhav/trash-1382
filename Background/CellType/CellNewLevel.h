#ifndef LABS_CELLNEWLEVEL_H
#define LABS_CELLNEWLEVEL_H

#include "CellType.h"
#include "../../Events/ChangeField/NewLevel.h"

class CellNewLevel : public CellType {
public:
    CellNewLevel();
    ~CellNewLevel() override = default;

    Event* get_event() final;
private:
    Event* event;
};


#endif
