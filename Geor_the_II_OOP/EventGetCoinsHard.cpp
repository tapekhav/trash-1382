#include "EventGetCoinsHard.h"
GameStatus EventGetCoinsHard::trigger(){
    if(!player->add_coins(coins)){
        return lose;
    }
    if(additional_event){
        return additional_event->trigger();
    }
    return null_event;
}