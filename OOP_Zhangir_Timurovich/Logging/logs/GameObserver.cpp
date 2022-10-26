//
// Created by roman on 25.10.2022.
//

#include "GameObserver.h"

void GameObserver::update() {
    return;
}

GameObserver::GameObserver(Subject *model) {
    model->attach(this);
}