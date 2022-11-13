#include "CreatorEventMakeBorder.h"
CellEvent *create(Field *f){
    EventMakeBorder *event = new EventMakeBorder;
    event->set_field(f);
    return event;
}