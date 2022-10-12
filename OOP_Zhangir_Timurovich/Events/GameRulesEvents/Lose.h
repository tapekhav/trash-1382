#pragma once


#include "RulesEvent.h"

class Lose : public RulesEvent {
public:
    Lose() = default;

    ~Lose() override = default;

    bool execute(void *obj) override;
};



