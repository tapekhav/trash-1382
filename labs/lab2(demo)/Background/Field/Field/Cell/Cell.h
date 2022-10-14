#ifndef LAB2_CELL_H
#define LAB2_CELL_H


#include <memory>
#include "../../../../Characters/Player.h"
#include "../Event/Event.h"

class Cell{
public:
    bool isPassable() const;
    bool isStepped() const;
    void setEvent(Event* event);
    Event* getEvent();
    void callEvent(void*);
protected:
    Event* event = nullptr;
    bool passable = false;
    bool stepped = false;
};


#endif

