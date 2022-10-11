#ifndef LABS_CELLBOX_H
#define LABS_CELLBOX_H

#include "CellType.h"
#include "../../Events/ChangePlayer/Box.h"

class CellBox : public CellType {
public:
    CellBox();
    ~CellBox() override = default;

    Event* get_event() final;
private:
    Event* event;
};



#endif
