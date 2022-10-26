#include "EventMakeNotPassable.h"
void EventMakeNotPassable::check_field_passability(){
    std::pair<long int, long int> coord = field->get_coord();
    if(!field->get_cell(coord.first + 1, coord.second)->is_passable() && !field->get_cell(coord.first, coord.second + 1)->is_passable() && !field->get_cell(coord.first + 1, coord.second + 1)->is_passable() && !field->get_cell(coord.first + 1, coord.second - 1)->is_passable() && !field->get_cell(coord.first - 1, coord.second + 1)->is_passable() && !field->get_cell(coord.first - 1, coord.second)->is_passable() && !field->get_cell(coord.first, coord.second - 1)->is_passable() && !field->get_cell(coord.first - 1, coord.second - 1)->is_passable()){
        std::pair<long int, long int> left_down = field->get_coord();
        std::pair<long int, long int> right_up = field->get_coord();
        left_down.first -= 1;
        left_down.second -= 1;
        right_up.first += 1;
        right_up.second += 1;
        set_is_passable(left_down, right_up, true);
    }
}
GameStatus EventMakeNotPassable::trigger(){
    if(!field){
        throw("Error! EventMakeNotPassable class object does not have a field set.\n");
    }
    std::pair <long int, long int> left_down;
    std::pair <long int, long int> right_up;
    left_down = coord;
    right_up = coord;
    left_down.first -= (long int) radius;
    left_down.second -= (long int) radius;
    right_up.first += (long int) radius;
    right_up.second += (long int) radius;
    set_is_passable(left_down, right_up, false);
    check_field_passability();
    return null_event;
}