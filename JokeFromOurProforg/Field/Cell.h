#ifndef SURVIVE_CELL_H
#define SURVIVE_CELL_H

#include "Event/Event.h"
#include "Event/Manager.h"

class Cell {
public:
    Cell() : mManager(nullptr), mWall(false), mEvent(nullptr) {};
    Cell(const Cell& obj);

    Cell& operator =(Cell const& other);

    bool IsWall() const { return mWall; }
    void SetWall(bool val) { mWall = val; }
    void SetManager(Manager* manager) { mManager = manager; }

    Event* GetEvent() const { return mEvent; }
    bool CheckEvent();
    void SetEvent(EnumClass::Events event);
    bool ActivateEvent();

private:
    bool mWall;
    Event* mEvent;
    Manager* mManager;
};

#endif //SURVIVE_CELL_H