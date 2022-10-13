#include <iostream>
#include "EventFieldCrashWall.h"
#include "../EventPlayer/EventPlayerAddCoin.h"

void EventFieldCrashWall::changeField(Field *field) {
    std::pair<int, int> player_position =  field->getPlayerPosition();
    field->setField();
    for(int w = -1; w != 2; ++w){
        for(int h = -1; h != 2; ++h){
            field->setCell(std::pair<int, int>({player_position.first+w, player_position.second+h}), "Grass");
            field->getCell(std::pair<int, int>({player_position.first+w, player_position.second+h})).setEvent(new EventPlayerAddCoin());
        }
    }
}