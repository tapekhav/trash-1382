#include <iostream>
#include "Cell.h"


bool Cell::isPassable() const {
    return passable;
}

void Cell::setEvent(Event* event){
    if (this->event != nullptr)
        delete this->event;
    this->event = event;
}

Event* Cell::getEvent(){
    return event;
}

const void Cell::callEvent(void* obj) const{
    if (this->event != nullptr)
        event->callReaction(obj);
}

int Cell::getType() const{
    return type;
}
