//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_STATUSOBSERVER_H
#define MAIN_CPP_STATUSOBSERVER_H

#include "../Observer.h"
#include "../Subject.h"

class StatusObserver : public Observer {
public:
    StatusObserver(Subject *model);

    void update() override;

    ~StatusObserver() override = default;
};


#endif //MAIN_CPP_STATUSOBSERVER_H
