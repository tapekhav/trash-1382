//
// Created by corvussharp on 28.10.22.
//


#define LABOCHKAOOP_LOGSLVLGAME_H


#include "Observer.h"
#include "Subject.h"

class LogsLvlGame : public Observer {
public:

    LogsLvlGame(Subject *model);

    void update(Message &msg) override;

};






