#include <iostream>
#include "Cell.h"
#include "Event.h"


void Cell::setEvent(Event* event){
    if (this->event != nullptr)
        this->event->~Event();
    this->event = event;
}

void Cell::callEvent() {
    if (this->event != nullptr)
        event->callReaction();
}

bool Cell::isPassable() const {
    return false;
}

Cell::Type Cell::getType() const{
    return type;
}