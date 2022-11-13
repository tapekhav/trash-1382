#include "EventResetEvents.h"
EventResetEvents::EventResetEvents(SetterCellEvent *s, bool i) : setter(s), is_only_null(i){}
EventResetEvents::EventResetEvents(SetterCellEvent *s) : setter(s), is_only_null(false){}
EventResetEvents::EventResetEvents(const EventResetEvents& e) : setter(e.setter), is_only_null(e.is_only_null){}
EventResetEvents::EventResetEvents(EventResetEvents&& e){
    std::swap(setter, e.setter);
    std::swap(is_only_null, e.is_only_null);
}
EventResetEvents& EventResetEvents::operator=(const EventResetEvents& e){
    if(this != &e){
        setter = e.setter;
        is_only_null = e.is_only_null;
    }
    return *this;
}
EventResetEvents& EventResetEvents::operator=(EventResetEvents&& e){
    if(this != &e){
        std::swap(setter, e.setter);
        std::swap(is_only_null, e.is_only_null);
    }
    return *this;
}
EventResetEvents& EventResetEvents::operator=(SetterCellEvent& e){
    setter = &e;
}
GameStatus EventResetEvents::trigger(){
    setter->set(is_only_null);
    return status_quo;
}
void EventResetEvents::set_setter(SetterCellEvent *s){
    setter = s;
}
void EventResetEvents::set_is_only_null(bool i){
    is_only_null = i;
}
SetterCellEvent *EventResetEvents::get_setter(){
    return setter;
}
bool EventResetEvents::get_is_only_null(){
    return is_only_null;
}