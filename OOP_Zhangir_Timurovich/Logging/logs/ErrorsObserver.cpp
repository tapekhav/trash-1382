//
// Created by roman on 26.10.2022.
//

#include "ErrorsObserver.h"

void ErrorsObserver::update(Message &msg) {
    if(msg.getType() == ERROR){
        Logger logger(msg.get_info());
        logger.print(msg);
    }
}

ErrorsObserver::ErrorsObserver(Subject *model){{
        model->attach(this);
    }
}