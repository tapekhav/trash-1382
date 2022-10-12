#pragma once

#include "RulesEvent.h"

class Win : public RulesEvent {
public:
    Win() = default;

    ~Win() override = default;

    bool execute(void *obj) override;
};



