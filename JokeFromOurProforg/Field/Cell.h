#ifndef SURVIVE_CELL_H
#define SURVIVE_CELL_H

#include "Event/Event.h"

class Cell {
public:
    Cell() : mWall(false), mEvent(nullptr) {};
    Cell(const Cell& obj);

    Cell& operator =(Cell const& other);

    bool IsWall() const { return mWall; }
    void SetWall(bool val) { mWall = val; }

    void ActiveEvent();

private:
    bool mWall;
    Event* mEvent;
};

#endif //SURVIVE_CELL_H