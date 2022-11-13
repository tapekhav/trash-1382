#include "EventFieldVirtual.h"
void EventFieldVirtual::set_field(Field *f){
    field = f;
}
Field *EventFieldVirtual::get_field(){
    return field;
}