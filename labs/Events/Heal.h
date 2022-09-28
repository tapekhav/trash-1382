#ifndef LABS_HEAL_H
#define LABS_HEAL_H

#include "Event.h"

class Heal : public Event {
public:
    void execute(Player& player) override;
    ~Heal() override = default;
};


#endif //LABS_HEAL_H
