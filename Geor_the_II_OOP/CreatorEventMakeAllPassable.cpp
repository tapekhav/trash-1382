#include "CreatorEventMakeAllPassable.h"
CellEvent *CreatorEventMakeAllPassable::create(Field *f){
    EventMakeAllPassable *event = new EventMakeAllPassable;
    event->set_field(f);
    return event;
}