#include "Cell.h"


bool Cell::isPassable() const {
    return passable;
}

/*
void Cell::setEvent(Event* event){
    if (this->event != nullptr)
        delete this->event;
    this->event = event;
}

void Cell::callEvent(std::shared_ptr<Player> player) {
    if (this->event != nullptr)
        event->callReaction(player);
}
 */

int Cell::getId() const{
    return id;
}

const Cell& Cell::getCell() const{
    return *this;
};