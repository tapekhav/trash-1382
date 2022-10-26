//
// Created by roman on 25.10.2022.
//

#include "GameObserver.h"

void GameObserver::update(Message &msg) {
    return;
}

GameObserver::GameObserver(Subject *model) {
    model->attach(this);
}