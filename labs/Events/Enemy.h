#ifndef LABS_ENEMY_H
#define LABS_ENEMY_H

#include "Event.h"

class Enemy: public Event{
public:
    void execute(Player& player) override;
    ~Enemy() override = default;
};


#endif //LABS_ENEMY_H
