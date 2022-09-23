#ifndef GAME_CELL_H
#define GAME_CELL_H


#include "Event.h"

class Cell{
private:
    bool passable;
    bool stepped;
    Event* event;
public:
    explicit Cell(bool passable = true, bool stepped = false);
    bool isPassable() const;
    bool isStepped() const;

    const Cell& getCell() const;
    void setEvent(Event* event);
    void callEvent();

    void setStepped();
    void setUnstepped();

};



#endif //GAME_CELL_H
