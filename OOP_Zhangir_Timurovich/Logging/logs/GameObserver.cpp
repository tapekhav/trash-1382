//
// Created by roman on 25.10.2022.
//

#include "GameObserver.h"
#include "../../Info/Structs.h"

void GameObserver::update(Message &msg) {
    if(msg.getType() == GAME){
        Logger logger(msg.get_info());
        logger.print(msg);
    }
}

GameObserver::GameObserver(Subject *model) {
    model->attach(this);
}