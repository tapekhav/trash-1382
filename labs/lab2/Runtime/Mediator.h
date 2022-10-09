#ifndef LAB2_MEDIATOR_H
#define LAB2_MEDIATOR_H


#include "MediatorObject.h"
#include "CommandReader.h"
#include "Controller.h"

class Mediator {
public:
    Mediator();
    void start();
private:
    char command = ' ';
    CommandReader commandReader;
    Controller controller;
    void notify(MediatorObject&);
    bool update();
    std::string help = "Use WASD to move\te for exit game";
};


#endif
