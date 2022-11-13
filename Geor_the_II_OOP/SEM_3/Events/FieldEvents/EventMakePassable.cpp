#include "EventMakePassable.h"
EventMakePassable::EventMakePassable(const EventMakePassable& e) : is_player_coord(e.is_player_coord){
    field = e.field;
    coord = e.coord;
    radius = e.radius;
}
EventMakePassable::EventMakePassable(EventMakePassable&& e){
    std::swap(field, e.field);
    std::swap(is_player_coord, e.is_player_coord);
    std::swap(coord, e.coord);
    std::swap(radius, e.radius);
}
EventMakePassable& EventMakePassable::operator=(const EventMakePassable& e){
    if(this != &e){
        field = e.field;
        coord = e.coord;
        radius = e.radius;
        is_player_coord = e.is_player_coord;
    }
    return *this;
}
EventMakePassable& EventMakePassable::operator=(EventMakePassable&& e){
    if(this != &e){
        std::swap(field, e.field);
        std::swap(is_player_coord, e.is_player_coord);
        std::swap(coord, e.coord);
        std::swap(radius, e.radius);
    }
    return *this;
}
GameStatus EventMakePassable::trigger(){
    std::pair <long int, long int> left_down;
    std::pair <long int, long int> right_up;
    if(is_player_coord){
        left_down = field->get_coord();
        right_up = field->get_coord();
    }
    else{
        left_down = coord;
        right_up = coord;
    }
    left_down.first -= (long int) radius;
    left_down.second -= (long int) radius;
    right_up.first += (long int) radius;
    right_up.second += (long int) radius;
    set_is_passable(left_down, right_up, true);
    return null_event;
}
void EventMakePassable::set_is_player_coord(bool i){
    is_player_coord = i;
}
bool EventMakePassable::get_is_player_coord(){
    return is_player_coord;
}