#ifndef LABS_CELLBOX_H
#define LABS_CELLBOX_H

#include "CellType.h"
#include "../../Events/ChangePlayer/Box.h"

class CellBox : public CellType {
public:
    CellBox();
    Event* get_event() override;
    ~CellBox() override;
private:
    Event* event;
};



#endif
