#ifndef LAB2_CELL_H
#define LAB2_CELL_H


#include <memory>
#include "../../../../Characters/Player.h"
#include "../Event/Event.h"

class Cell{
public:
    bool isPassable() const;
    void setEvent(Event* event);
    void callEvent(std::shared_ptr<Player> player);
    int getId() const;
    const Cell& getCell() const;
protected:
    Event* event = nullptr;
    int id = -1;
    bool passable = false;
};


#endif

