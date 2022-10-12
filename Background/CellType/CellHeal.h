#ifndef LABS_CELLHEAL_H
#define LABS_CELLHEAL_H

#include "CellType.h"
#include "../../Events/ChangePlayer/Heal.h"

class CellHeal : public CellType {
public:
    CellHeal();
    Event* get_event() override;
    ~CellHeal() override;
private:
    Event* event;
};


#endif
