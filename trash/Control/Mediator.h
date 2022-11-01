#ifndef LABS_MEDIATOR_H
#define LABS_MEDIATOR_H

#include "CommandReader.h"
#include "Controller.h"

class Mediator {
public:
    Mediator();
    ~Mediator();

    void start();
    void init_logs(std::vector<Logger*>& loggers);
private:
    CommandReader    input;
    Controller        game;
    GameLog*       logging;
};

#endif //LABS_MEDIATOR_H