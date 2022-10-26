#pragma once


#include "RulesEvent.h"

class Lose : public RulesEvent {
public:
    Lose(Player *player);

    ~Lose() override = default;

    bool execute() override;

};



