#ifndef LABS_CELLKEY_H
#define LABS_CELLKEY_H

#include "CellType.h"
#include "../../Events/ChangePlayer/Key.h"

class CellKey : public CellType {
public:
    CellKey();
    ~CellKey() override = default;

    Event* get_event() final;
private:
    Event* event;
};


#endif
