#ifndef LABS_MEDIATOR_H
#define LABS_MEDIATOR_H

#include "CommandReader.h"
#include "Controller.h"
#include "LogLevel/ErrorLog.h"

class Mediator {
public:
    Mediator();
    ~Mediator();

    void start();
private:

    CommandReader input;
    Controller     game;
    ErrorLog* error_log;
};

#endif //LABS_MEDIATOR_H