#include "CreatorEventChangePassable.h"
CellEvent *CreatorEventChangePassable::create(Field *f){
    EventChangePassable *event = new EventChangePassable;
    event->set_field(f);
    
}