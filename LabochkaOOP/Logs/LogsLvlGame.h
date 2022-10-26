//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_LOGSLVLGAME_H
#define LABOCHKAOOP_LOGSLVLGAME_H
#include "Observer.h"
#include "Subject.h"
class LogsLvlGame: public Observer{
public:
    void update() override;

    ~LogsLvlGame() override = default;

    explicit LogsLvlGame(Subject& model);
};


#endif //LABOCHKAOOP_LOGSLVLGAME_H
