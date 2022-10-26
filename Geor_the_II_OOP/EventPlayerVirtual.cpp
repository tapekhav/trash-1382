#include "EventPlayerVirtual.h"
void EventPlayerVirtual::set_player(Player *p){
    player = p;
}
Player *EventPlayerVirtual::get_player(){
    return player;
}