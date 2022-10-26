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
    void attach_loggers(std::vector<Logger*>& loggers);
private:
    CommandReader    input;
    Controller        game;
    ErrorLog*    error_log;
    GameLog*     field_log;
    GameLog*    player_log;
    StatusLog*  status_log;
};

#endif //LABS_MEDIATOR_H