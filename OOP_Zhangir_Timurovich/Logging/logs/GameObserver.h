#ifndef MAIN_CPP_GAMEOBSERVER_H
#define MAIN_CPP_GAMEOBSERVER_H

#include "../Observer.h"
#include "../Subject.h"

class GameObserver : public Observer {
public:

    GameObserver(Subject *model) {
        model->attach(this);
    }

    void update() override;

    ~GameObserver() override = default;

};


#endif //MAIN_CPP_GAMEOBSERVER_H
