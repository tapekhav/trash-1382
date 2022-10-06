//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_MEDIATOR_H
#define UNTITLED48_MEDIATOR_H
#include "CommandReader.h"
#include "Controller.h"

class Mediator{
private:
    Person person;
    CommandReader input;
    Controller play;
public:
    void start();

};


#endif //UNTITLED48_MEDIATOR_H
