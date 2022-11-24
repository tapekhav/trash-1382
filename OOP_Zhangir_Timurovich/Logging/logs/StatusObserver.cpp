//
// Created by roman on 26.10.2022.
//

#include "StatusObserver.h"

void StatusObserver::update(Message &msg) {
    if(msg.getType() == STATUS){
//        Logger logger(msg.get_info());
        LOG.print(msg);
    }
}

StatusObserver::StatusObserver(Subject *model) {
    model->attach(this);
}