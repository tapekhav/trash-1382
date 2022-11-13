#include "EventCasing.h"
EventCasing::EventCasing(std::string n, CellEvent *e, float c) : name(n), event(e), chance(c){}
EventCasing::EventCasing(std::string n, CellEvent *e) : name(n), event(e), chance(1.0){}
EventCasing::EventCasing(CellEvent *e, float c) : event(e), chance(c){}
EventCasing::EventCasing(CellEvent *e) : event(e), chance(1.0){}
EventCasing::EventCasing(const EventCasing& e) : name(e.name), event(e.event), chance(e.chance){}
EventCasing::EventCasing(EventCasing&& e){
    std::swap(name, e.name);
    std::swap(event, e.event);
    std::swap(chance, e.chance);
}
EventCasing& EventCasing::operator=(const EventCasing& e){
    if(this != &e){
        name = e.name;
        event = e.event;
        chance = e.chance;
    }
    return *this;
}
EventCasing& EventCasing::operator=(EventCasing&& e){
    if(this != &e){
        std::swap(name, e.name);
        std::swap(event, e.event);
        std::swap(chance, e.chance);
    }
    return *this;
}
EventCasing& EventCasing::operator=(CellEvent& e){
    if(this != &e){
        event = &e;
    }
    return *this;
}
GameStatus EventCasing::trigger(){
    std::mt19937 r;
    std::random_device device;
    r.seed(device());
    if(r() % 100 < chance * 100.0){
        return event->trigger();
    }
    return status_quo;
}
void EventCasing::set_event(CellEvent *e){
    event = e;
}
void EventCasing::set_name(std::string n){
    name = n;
}
void EventCasing::set_chance(float c){
    chance = c;
}
std::string EventCasing::get_name(){
    return name;
}
float EventCasing::get_chance(){
    return chance;
}
CellEvent *EventCasing::get_event(){
    return event;
}