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

void Cell::CheckEvent() {
    if (mEvent == nullptr)
        mEvent = mManager->ChooseEvent();
    else if (mManager->CheckEvent(mEvent))
        mEvent = nullptr;
}

void Cell::ActivateEvent() {
    if (mEvent != nullptr) {
        if(mManager->UseEvent(mEvent))
            mEvent = nullptr;
    }
}

void Cell::SetEvent(EnumClass::Events event) {
    if (mEvent == nullptr)
        mEvent = mManager->ChooseConcreteEvent(event);
}
