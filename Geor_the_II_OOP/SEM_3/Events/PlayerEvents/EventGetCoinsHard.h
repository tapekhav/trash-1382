#pragma once
#include "EventGetCoins.h"
class EventGetCoinsHard : public EventGetCoins{
    public:
        GameStatus trigger();
};