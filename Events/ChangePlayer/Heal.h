#ifndef LABS_HEAL_H
#define LABS_HEAL_H

#include "EventPlayer.h"

class Heal: public EventPlayer {
public:
    void execute(Player& player) override;
};


#endif
