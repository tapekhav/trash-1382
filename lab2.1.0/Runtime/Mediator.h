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
    void help() const;
    void notify(MediatorObject&);
    bool update();
};


#endif
