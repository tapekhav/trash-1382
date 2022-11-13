#include "EventMakeBorder.h"
EventMakeBorder::EventMakeBorder(Field *f){
    field = f;
}
GameStatus EventMakeBorder::trigger(){
    long int width = (long int) field->get_width();
    long int length = (long int) field->get_length();
    for(long int y = 0; y < length; y++){
        field->get_cell(0, y)->set_passable(false);
        field->get_cell(width - 1, y)->set_passable(false);
    }
    for(long int x = 1; x < width - 1; x++){
        field->get_cell(x, 0)->set_passable(false);
        field->get_cell(x, length - 1)->set_passable(false);
    }
    std::pair<long int, long int> coord = field->get_coord();
    if(!field->get_cell(coord.first + 1, coord.second)->is_passable() && !field->get_cell(coord.first, coord.second + 1)->is_passable() && !field->get_cell(coord.first + 1, coord.second + 1)->is_passable() && !field->get_cell(coord.first + 1, coord.second - 1)->is_passable() && !field->get_cell(coord.first - 1, coord.second + 1)->is_passable() && !field->get_cell(coord.first - 1, coord.second)->is_passable() && !field->get_cell(coord.first, coord.second - 1)->is_passable() && !field->get_cell(coord.first - 1, coord.second - 1)->is_passable()){
        field->get_cell(coord.first + 1, coord.second)->set_passable(true);
        field->get_cell(coord.first, coord.second + 1)->set_passable(true);
        field->get_cell(coord.first + 1, coord.second + 1)->set_passable(true);
        field->get_cell(coord.first + 1, coord.second - 1)->set_passable(true);
        field->get_cell(coord.first - 1, coord.second + 1)->set_passable(true);
        field->get_cell(coord.first - 1, coord.second)->set_passable(true);
        field->get_cell(coord.first, coord.second - 1)->set_passable(true);
        field->get_cell(coord.first - 1, coord.second - 1)->set_passable(true);
    }
    return null_event;
}