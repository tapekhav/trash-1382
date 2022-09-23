#ifndef GAME_MEDIATOR_H
#define GAME_MEDIATOR_H


#include "MediatorObject.h"
#include "CommandReader.h"
#include "Controller.h"

class Mediator {
public:
    Mediator(Controller&, CommandReader&);
    void start();
private:
    Player::STEP step;
    CommandReader commandReader;
    Controller controller;
    void notify(MediatorObject&);
    bool update(char&);
};


#endif
