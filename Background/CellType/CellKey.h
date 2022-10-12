#ifndef LABS_CELLKEY_H
#define LABS_CELLKEY_H

#include "CellType.h"
#include "../../Events/ChangePlayer/Key.h"

class CellKey : public CellType {
public:
    CellKey();
    Event* get_event() override;
    ~CellKey() override;;
};


#endif
