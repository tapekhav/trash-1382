#ifndef LAB2_CELL_H
#define LAB2_CELL_H


#include <memory>
#include "../../../../Characters/Player.h"
#include "../Event/Event.h"

class Cell{
public:
    bool isPassable() const;
    void setEvent(Event* event);
    const void callEvent(void*) const;
    int getType() const;
    Event* getEvent();
protected:
    Event* event = nullptr;
    int type = -1;
    bool passable = false;
};


#endif

