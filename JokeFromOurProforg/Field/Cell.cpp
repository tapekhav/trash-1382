#include "Field/Cell.h"
#include <iostream>
Cell::Cell(const Cell& obj) {
    mWall = obj.mWall;
    mEvent = obj.mEvent;
}

Cell& Cell::operator=(const Cell& other) {
    if (this == &other)
        return *this;
    mWall = other.mWall;
    mEvent = other.mEvent;
    return *this;
}

bool Cell::CheckEvent() {
    if (mEvent == nullptr) {
        mEvent = mManager->ChooseEvent();
        return mEvent;
    }
    else if (mManager->CheckEvent(mEvent)) {
        mEvent = nullptr;
        return true;
    }
    return false;
}

bool Cell::ActivateEvent() {
    if (mEvent != nullptr) {
        if(mManager->UseEvent(mEvent))
            return !(mEvent = nullptr);
    }
    return false;
}

void Cell::SetEvent(Event* event) {
    if (mEvent == nullptr) {
        mManager->ChooseConcreteEvent(event);
        mEvent = event;
    }
}
