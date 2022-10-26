#include "EventChangePassable.h"
void EventChangePassable::set_is_passable(std::pair <long int, long int> left_down, std::pair <long int, long int> right_up, bool type){
    for(long int x = left_down.first; x <= right_up.first; x++){
        for(long int y = left_down.second; y <= right_up.second; y++){
            field->get_cell(x, y)->set_passable(type);
        }
    }
}
EventChangePassable::EventChangePassable(Field *f, std::pair <long int, long int> c, unsigned int r) : coord(c), radius(r){
    field = f;
}
EventChangePassable::EventChangePassable(Field *f, long int x, long int y, unsigned int r) : radius(r){
    coord.first = x;
    coord.second = y;
}
EventChangePassable::EventChangePassable(Field *f, std::pair <long int, long int> c) : coord(c), radius(3){
    field = f;
}
EventChangePassable::EventChangePassable(Field *f, long int x, long int y) : radius(3){
    field = f;
    coord.first = x;
    coord.second = y;
}
EventChangePassable::EventChangePassable(Field *f) : radius(5){
    field = f;
    coord.first = 0;
    coord.second = 0;
}
EventChangePassable::EventChangePassable() : radius(5){
    field = nullptr;
    coord.first = 0;
    coord.second = 0;
}
EventChangePassable::EventChangePassable(const EventChangePassable& e) : coord(e.coord), radius(e.radius){
    field = e.field;
}
EventChangePassable::EventChangePassable(EventChangePassable&& e){
    std::swap(field, e.field);
    std:swap(coord, e.coord);
    std::swap(radius, e.radius);
}
EventChangePassable& EventChangePassable::operator=(const EventChangePassable& e){
    if(this != &e){
        field = e.field;
        coord = e.coord;
        radius = e.radius;
    }
    return *this;
}
EventChangePassable& EventChangePassable::operator=(EventChangePassable&& e){
    if(this != &e){
        std::swap(field, e.field);
        std:swap(coord, e.coord);
        std::swap(radius, e.radius);
    }
    return *this;
}
void EventChangePassable::set_coord(std::pair <long int, long int> c){
    coord = c;
}
void EventChangePassable::set_coord(long int x, long int y){
    coord.first = x;
    coord.second = y;
}
void EventChangePassable::set_radius(unsigned int r){
    radius = r;
}
std::pair <long int, long int> EventChangePassable::get_coord(){
    return coord;
}
unsigned int EventChangePassable::get_radius(){
    return radius;
}