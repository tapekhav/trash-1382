#include "EventMakeAllPassable.h"
GameStatus EventMakeAllPassable::trigger(){
    for(long int x = 0; x <= field->get_width(); x++){
        for(long int y = 0; y <= field->get_length(); y++){
            field->get_cell(x, y)->set_passable(true);
        }
    }
    return null_event;
}