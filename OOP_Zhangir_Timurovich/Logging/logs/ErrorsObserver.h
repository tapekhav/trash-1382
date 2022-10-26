//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_ERRORSOBSERVER_H
#define MAIN_CPP_ERRORSOBSERVER_H

#include "../Observer.h"
#include "../Subject.h"

class ErrorsObserver : public Observer {
public:
    ErrorsObserver(Subject *model) {
        model->attach(this);
    }

    void update() override;

    ~ErrorsObserver() override = default;
};


#endif //MAIN_CPP_ERRORSOBSERVER_H
