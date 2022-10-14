#include "EventFieldSpawnCoins.h"
#include "../EventPlayer/EventPlayerAddCoin.h"

void EventFieldSpawnCoins::changeField(Field *field) {
    std::pair<int, int> player_position =  field->getPlayerPosition();
    field->setField();
    for(int w = -1; w != 2; ++w){
        for(int h = -1; h != 2; ++h){
            auto* addCoin = new EventPlayerAddCoin(10);
            field->getCell(std::pair<int, int>({player_position.first+w, player_position.second+h})).setEvent(addCoin);
        }
    }
}