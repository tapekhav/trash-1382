#pragma once
#include "../Event.h"
#include "../../Characters/Player.h"

class PlayerEvent: public Event {
public:
    virtual void execute(Player* player) = 0;
    void execute() override {};
};

