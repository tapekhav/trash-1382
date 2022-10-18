#pragma once

#include "RulesEvent.h"

class Win : public RulesEvent {
public:
    Win(Player* player);

    ~Win() override = default;

    bool execute() override;
};



