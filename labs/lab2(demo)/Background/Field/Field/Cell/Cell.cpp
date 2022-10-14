#include "Cell.h"


bool Cell::isPassable() const {
    return passable;
}

bool Cell::isStepped() const {
    return stepped;
}

void Cell::setEvent(Event* event){
    if (this->event != nullptr and passable)
        delete this->event;
    this->event = event;
}

Event* Cell::getEvent(){
    return event;
}

void Cell::callEvent(void* obj){
    if (event != nullptr)
        event->callReaction(obj);
        event = nullptr;
}