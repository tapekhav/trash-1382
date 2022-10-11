#ifndef LABS_CELLHEAL_H
#define LABS_CELLHEAL_H

#include "CellType.h"
#include "../../Events/ChangePlayer/Heal.h"

class CellHeal : public CellType {
public:
    CellHeal();
    ~CellHeal() override = default;

    Event* get_event() final;
private:
    Event* event;
};


#endif
