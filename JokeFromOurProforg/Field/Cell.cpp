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
        if(mEvent = mManager->ChooseEvent())
            return true;
    }
    else if (mManager->CheckEvent(mEvent)) {
        mEvent = nullptr;
        return true;
    }
    return false;

}

bool Cell::ActivateEvent() {
    if (mEvent != nullptr) {
        if (mManager->UseEvent(mEvent)) {
            mEvent = nullptr;
            return true;
        }
        else
            return false;
    }
    return false;
}

void Cell::SetEvent(EnumClass::Events event) {
    if (mEvent == nullptr)
        mEvent = mManager->ChooseConcreteEvent(event);
}
