//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_MEDIATOR_H
#define UNTITLED48_MEDIATOR_H

#include "Controller.h"
#include "../Commands/ConsoleGameSetings.h"
#include "../Commands/ConsoleReader.h"
#include "../Commands/GameSettings.h"
class Mediator {
private:
    Person person;
    GameSettings *game;
    Controller play;
    ConsoleGameSetings input;
    ConsoleReader cread;
public:
    void start();

};


#endif //UNTITLED48_MEDIATOR_H
